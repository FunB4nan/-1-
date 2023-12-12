#include <iostream>
#include <cmath>
#include <vector>

using namespace std;
double f(double x) {
    return 1 / (pow(log10(x),2) + 1);
}
double f2(double x, double y)
{
    return x * x / (1 + y * y);
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
double cubeSimpsonIntegration(double a, double b, double c, double d, int n, int m)
{
    double hx = (b - a) / (2 * n);
    double hy = (d - c) / (2 * m);
    double integral = 0;

    for (int i = 0; i < n - 1; i++)
    {
        double sum = 0;
        for (int j = 0; j < n - 1; j++)
        {
            sum += f2(a + hx * 2 * i, c + hy * 2 * j) + 4 * f2(a + hx * (2 * i + 1), c + hy * 2 * j) + 
                f2(a + hx * (2 * i + 2),c + hy * 2 * j) + 4 * f2(a + hx * 2 * i, c + hy * (2 * j + 1)) + 
                16 * f2(a + hx * (2 * i + 1), c + hy * (2 * j + 1)) + 4 * f2(a + hx * (2 * i + 2),c + hy * (2 * j + 1)) +
                f2(a + hx * 2 * i, c + hy * (2 * j + 2)) + 4 * f2(a + hx * (2 * i + 1), c + hy * (2 * j + 2)) +
                f2(a + hx * (2 * i + 2), c + hy * (2 * j + 2));
        }
        integral += sum;
    }
    return hx * hy / 9 * integral;
}
int main() {
    double a = 1.0;
    double b = 2.835;
    int n = 1000;
    int m = 1000;

    cout << "Trapezoidal integration result: " << trapezoidalIntegration(a, b, n) << endl;
    cout << "Simpson integration result: " << simpsonIntegration(a, b, n) << endl;
    cout << "Cube simpson integration result: " << cubeSimpsonIntegration(0, 0.4, 1.0, 2.0, n,m) << endl;
}
