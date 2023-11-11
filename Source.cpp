#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
const int MAX_SIZE = 100;
void gaussElimination(vector<vector<double>> A, vector<double> B) {
    for (int i = 0; i < 3; i++) {
        int maxRow = i;
        for (int k = i + 1; k < 3; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        for (int k = i; k < 3; k++) {
            swap(A[maxRow][k], A[i][k]);
        }
        swap(B[maxRow], B[i]);

        for (int k = i + 1; k < 3; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < 3; j++) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }

    double x[MAX_SIZE];
    for (int i = 2; i >= 0; i--) {
        x[i] = B[i];
        for (int j = i + 1; j < 3; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    double residual[MAX_SIZE];
    double maxResidual = 0.0;
    for (int i = 0; i < 3; i++) {
        residual[i] = B[i];
        for (int j = 0; j < 3; j++) {
            residual[i] -= A[i][j] * x[j];
        }
        if (abs(residual[i]) > maxResidual) {
            maxResidual = abs(residual[i]);
        }
    }

    double relativeError = maxResidual / abs(x[0]);

    cout << "Solution vector:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }

    cout << "Residual vector:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "residual[" << i << "] = " << residual[i] << endl;
    }

    cout << "Relative error: " << relativeError << endl;
}

int main() {
    vector<vector<double>> A = { {2.31, 31.49, 1.52},
                                {4.21, 22.42, 3.85},
                                {3.49, 4.85, 28.72} };

    vector<double> b = { 40.95, 30.24, 42.81 };

    gaussElimination(A, b);
}
