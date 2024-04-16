// user define works only for polynomial
#include <bits/stdc++.h>
using namespace std;

double f(double x, int arr[], int n)
{
    double result = 0;
    for (int i = 0; i <= n; i++)
    {
        double term = arr[i] * pow(x, i);
        result += term;
    }
    return result;
}

double g(double x, int arr[], int n)
{
    double result = 0;
    for (int i = 1; i <= n; i++)
    {
        double term = arr[i] * pow(x, i - 1) * i;
        result += term;
    }
    return result;
}

double newtonRaphsan(int arr[], int order, double x0, int n, double tol = 0.000001)
{
    int i = 0;
    while (i <= n)
    {
        double x1;
        x1 = x0 - (f(x0, arr, order) / g(x0, arr, order));
        x0 = x1;
        cout << "At iteration " << i << " x" << i << " : " << x1 << endl;
        i++;
        if (fabs(f(x1, arr, order)) < tol)
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
    int order;
    cout << "Enter order of equation: ";
    cin >> order;

    int arr[order + 1];

    for (int i = order; i >= 0; i--)
    {
        cout << "Enter coefficient of x^" << i << " with sign(+/-): ";
        cin >> arr[i];
    }
    int a = 0, b = a + 1;
    for (a = 0; a < 100; a++)
    {
        b = a + 1;
        if (f(a,arr,order) * f(b,arr,order) < 0)
        {
            break;
        }
    }

    cout << "Bounds are [a,b]  = [" << a << " , " << b << "]" << endl;
    int n;
    cout << "Enter number of iterations : " << endl;
    cin >> n;
    newtonRaphsan(arr,order,a,n);
    return 0;
}