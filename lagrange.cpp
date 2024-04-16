#include <bits/stdc++.h>
using namespace std;

double lagrange(vector<double> &x, vector<double> &y, double xi)
{
    int n = x.size();
    double result = 0;
    for (int i = 0; i < n; i++)
    {
        double term = 1;
        for (int j = 0; j < n; j++)
        {
            if (j == i)
            {
                continue;
            }
            else
            {
                term *= (xi - x[j]) / (x[i] - x[j]);
            }
        }
        result += term * y[i];
    }
    return result;
}

int main()
{
    int n;
    cout << "Enter the number of data points : " << endl;
    cin >> n;
    vector<double> x(n), y(n);
    for (int i = 0; i < n; i++)
    {
        cout << "X[" << i << "] : ";
        cin >> x[i];
        cout << "Y[" << i << "] : ";
        cin >> y[i];
    }
    double xi;
    cout << "Enter Interpolation value : ";
    cin >> xi;
    cout << "Lagrange's Interpolation : " << lagrange(x, y, xi) << endl;
    return 0;
}