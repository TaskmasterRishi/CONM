#include <bits/stdc++.h>
using namespace std;

double f(double x)
{
    return pow(x, 3) + x - 1;
}

double g(double x)
{
    return 3 * x * x + 1;
}

double newtonRaphsan(double x0, int n, double tol = 0.000001)
{
    int i = 0;
    while (i <= n)
    {
        double x1;
        x1 = x0 - (f(x0) / g(x0));
        x0 = x1;
        cout << "At iteration " << i << " x" << i << " : " << x1 << endl;
        i++;
        if (fabs(f(x1)) < tol)
        {
            cout << "Root found : " << x1 << endl;
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
    
    cout << "Bounds are [a,b]  = [" << a << " , " << b << "]" << endl;
    int n;
    cout << "Enter number of iterations : " << endl;
    cin >> n;
    newtonRaphsan(a, n);
    return 0;
}