#include <bits/stdc++.h>
using namespace std;

double fun(double x, const int f[], int n)
{
    double result = 0;
    for (int i = 0; i <= n; i++)
    {
        double term = f[i] * pow(x, i);
        result += term;
    }
    return result;
}

void bisection(double a, double b, const int f[], int n, double tol = 0.01)
{
    if (fun(a, f, n) * fun(b, f, n) >= 0)
    {
        cout << "Bounds are not correct" << endl;
        exit(0);
    }

    double c = a;

    cout.width(10);
    cout << "a";
    cout.width(10);
    cout << "b";
    cout.width(10);
    cout << "f(a)";
    cout.width(10);
    cout << "f(b)";
    cout.width(10);
    cout << "c";
    cout.width(10);
    cout << "f(c)" << endl;

    while ((b - a) >= tol)
    {
        c = (b + a) / 2;
        cout.width(10);
        cout << a;
        cout.width(10);
        cout << b;
        cout.width(10);
        cout << fun(a, f, n);
        cout.width(10);
        cout << fun(b, f, n);
        cout.width(10);
        cout << c;
        cout.width(10);
        cout << fun(c, f, n) << endl;

        if (fun(c, f, n) == 0)
        {
            break;
        }
        else if (fun(c, f, n) * fun(a, f, n) < 0)
        {
            b = c;
        }
        else
        {
            a = c;
        }
    }

    cout << "Root : " << c << endl;
}

int main()
{
    int n;
    cout << "Enter order of equation: ";
    cin >> n;

    int f1[n + 1];

    for (int i = n; i >= 0; i--)
    {
        cout << "Enter coefficient of x^" << i << " with sign(+/-): ";
        cin >> f1[i];
    }

    double a, b;

    for (a =0; a <= 100; a++)
    {
        b = a + 1;
        if (fun(a, f1, n) * fun(b, f1, n) < 0)
        {
            break;
        }
    }

    bisection(a, b, f1, n);

    return 0;
}