#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void gaussElimination(double A[3][3], double B[3], double* x) {
    for (int i = 0; i < 3; i++) {
        int maxRow = i;
        for (int k = i + 1; k < 3; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        swap(A[maxRow], A[i]);
        swap(B[maxRow], B[i]);

        for (int k = i + 1; k < 3; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < 3; j++) {
                A[k][j] -= factor * A[i][j];
            }
            B[k] -= factor * B[i];
        }
    }

    for (int i = 2; i >= 0; i--) {
        x[i] = B[i];
        for (int j = i + 1; j < 3; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }

    cout << "Solution vector:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "x[" << i << "] = " << x[i] << endl;
    }



    /*cout << "Relative error: " << relativeError << endl;*/
}
void residualVector(double A[3][3], double B[3], double x[3])
{
    double residual[3];
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
    cout << "Residual vector:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "residual[" << i << "] = " << residual[i] << endl;
    }
    cout << "max residual = " << maxResidual << endl;
}
void relativeError(double A[3][3], double x[3])
{
    double b[3];
    for (int i = 0; i < 3; i++)
    {
        b[i] = 0;
        for (int j = 0; j < 3; j++)
        {
            b[i] += A[i][j] * x[j];
        }
    }
    double _x[3];
    for (int i = 0; i < 3; i++) {
        int maxRow = i;
        for (int k = i + 1; k < 3; k++) {
            if (abs(A[k][i]) > abs(A[maxRow][i])) {
                maxRow = k;
            }
        }
        swap(A[maxRow], A[i]);
        swap(b[maxRow], b[i]);

        for (int k = i + 1; k < 3; k++) {
            double factor = A[k][i] / A[i][i];
            for (int j = i; j < 3; j++) {
                A[k][j] -= factor * A[i][j];
            }
            b[k] -= factor * b[i];
        }
    }

    for (int i = 2; i >= 0; i--) {
        _x[i] = b[i];
        for (int j = i + 1; j < 3; j++) {
            _x[i] -= A[i][j] * _x[j];
        }
        _x[i] /= A[i][i];
    }
    cout << "Solution vector:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << "x[" << i << "] = " << _x[i] << endl;
    }
    double maxX = 0.0;
    double maxGap = 0.0;
    for (int i = 0; i < 3; i++)
    {
        if (abs(_x[i] - x[i]) > maxGap)
        {
            maxGap = abs(_x[i] - x[i]);
        }
        if (abs(x[i]) > maxX)
        {
            maxX = x[i];
        }
    }
    cout << "Relative error: " << maxGap / maxX << endl;
}
int main() {
    double A[3][3] = { {2.31, 31.49, 1.52},
                                {4.21, 22.42, 3.85},
                                {3.49, 4.85, 28.72} };;
    double b[3] = { 40.95, 30.24, 42.81 };
    double x[3];
    gaussElimination(A, b, x);
    residualVector(A, b, x);
    relativeError(A, x);
}
