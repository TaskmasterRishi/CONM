#include <bits/stdc++.h>
using namespace std;

double f(double x) {
    return pow(x, 3) + x * x - 1;
}

double g(double x) {
    return 1 / (sqrt(x + 1));
}

double iteration(double x0, int N, double tol) {
    double x1;
    int i = 0;
    while (i <= N) {
        x1 = g(x0);
        cout << "Iteration-" << i << ":\t x" << i << " = " << setw(10) << x1 << " and f(x" << i << ") = " << setw(10) << f(x1) << endl;
        x0 = x1;
        i++;
        if (fabs(f(x1)) < tol) {
            cout << "Root found with precision " << tol << ": " << x1 << endl;
            return x1;
        }
    }
    cout << "Root not found within " << N << " iterations." << endl;
    return x1;
}

int main() {
    double a, b, x0;
    int N, n;

    for (a = 0; a < 100; a++) {
        b = a + 1;
        if (f(a) * f(b) < 0) {
            break;
        }
    }
    cout << "Bounds are a: " << a << " b:" << b << endl;

    cout << "Enter initial guess within [" << a << ", " << b << "]: ";
    cin >> x0;
    if (x0 <= a || x0 >= b) {
        cout << "Initial guess is out of bound." << endl;
        return 1; 
    }

    cout << "Enter maximum number of iterations: ";
    cin >> N;
    cout << "Enter precision (number of decimal places): ";
    cin >> n;
    if (n <= 0) {
        cout << "Precision must be greater than 0. Using default precision of 6." << endl;
        n = 6;
    }
    double tol = pow(10, -n);
    cout << setprecision(n) << fixed;

    double root = iteration(x0, N, tol);

    return 0;
}
