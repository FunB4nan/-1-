#include <iostream>
#include <cmath>

using namespace std;
double f(double x) {
    return 1 / (pow(log10(x),2) + 1);
}

double trapezoidalIntegration(double a, double b, int n) {
    double h = (b - a) / n;
    double sum = h / 2 * (f(a) + f(b));
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        sum += f(x) * h;
    }
    return sum;
}

double simpsonIntegration(double a, double b, int n) {
    double h = (b - a) / (2 * n);
    double sum = h / 3 * (f(a) + f(b));
    for (int i = 1; i < 2 * n; i += 2) {
        double x = a + i * h;
        sum += 4 * f(x) * h / 3;
    }
    for (int i = 2; i < 2 * n - 1; i += 2) {
        double x = a + i * h;
        sum += 2 * f(x) * h / 3;
    }
    return sum;
}

int main() {
    double a = 1.0;
    double b = 2.835;
    int n = 1000;

    double result_trapezoidal = trapezoidalIntegration(a, b, n);
    double result_simpson = simpsonIntegration(a, b, n);

    cout << "Trapezoidal integration result: " << result_trapezoidal << endl;
    cout << "Simpson integration result: " << result_simpson << endl;

}
