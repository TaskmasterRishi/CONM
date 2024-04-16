#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return pow(x, 3) - 2*x - 5;
}

double secant(double x0, double x1, int n, double tol = 0.000001)
{
    int i = 0;
    while (i <= n)
    {
        double x2;
        x2 = x1 - ((x1 - x0) * (f(x1)) / (f(x1) - f(x0)));
        x0 = x1;
        x1 = x2;
        cout << "At iteration " << i << " x" << i+2 << " : " << x2 <<endl;
        i++;
        if (fabs(f(x2)) < tol)
        {
            cout << "Root found : " << x2 << endl;
            return x1;
        }
    }
    cout << "Root is not found within " << n << " itrstion :" << endl;
    return 0;
}

int main()
{
    int a = 0, b = a + 1;
    for (a = 0; a < 100; a++)
    {
        b = a + 1;
        if (f(a) * f(b) < 0)
        {
            break;
        }
    }
    cout<<"Equation f(x) = x^3 - 2x - 5"<<endl;
    cout << "Bounds are [a,b]  = [" << a << " , " << b << "]" << endl;
    int n;
    cout << "Enter number of iterations : " << endl;
    cin >> n;
    secant(a,b, n);
    return 0;
}