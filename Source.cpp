#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;

void LDLFactorization(vector<vector<double>> A, vector<double> B) {
    double L[MAX_SIZE][MAX_SIZE];
    double D[MAX_SIZE][MAX_SIZE];

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j <= i; j++) {
            double sum = 0;
            if (j == i) {
                for (int k = 0; k < j; k++) {
                    sum += pow(L[j][k], 2) * D[k][k];
                }
                D[j][j] = A[j][j] - sum;
                L[j][j] = 1;
            }
            else {
                for (int k = 0; k < j; k++) {
                    sum += L[i][k] * D[k][k] * L[j][k];
                }
                L[i][j] = (A[i][j] - sum) / D[j][j];
            }
        }
    }

    double y[MAX_SIZE];
    for (int i = 0; i < 3; i++) {
        double sum = 0;
        for (int j = 0; j < i; j++) {
            sum += L[i][j] * y[j];
        }
        y[i] = (B[i] - sum) / L[i][i];
    }

    double z[MAX_SIZE];
    for (int i = 0; i < 3; i++) {
        z[i] = y[i] / sqrt(D[i][i]);
    }

    double x[MAX_SIZE];
    for (int i = 2; i >= 0; i--) {
        double sum = 0;
        for (int j = i + 1; j < 3; j++) {
            sum += L[j][i] * x[j];
        }
        x[i] = (z[i] - sum) / L[i][i];
    }

    cout << "Solution vector:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }
}

int main() {
    double l1 = 1;
    double l2 = pow(10, 3);
    double l3 = pow(10, 6);
    vector<vector<double>> A = { {2 * l1 + 4 * l2, 2 * (l1 - l2), 2 * (l1 - l2)},
                            {2 * (l1 - l2), 2 * l1 + l2 + 3 * l3, 2 * l1 + l2 - 3 * l3},
                            {2 * (l1 - l2), 2 * l1 + l2 - 3 * l3, 2 * l1 + l2 + 3 * l3} };

    vector<double> b = { -4 * l1 - 2 * l2, -4 * l1 + l2 + 9 * l3, -4 * l1 + l2 - 9 * l3 };

    LDLFactorization(A, b);
}
