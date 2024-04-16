#include <bits/stdc++.h>
using namespace std;

double weddle(vector<double> &x, vector<double> &y)
{
    int n = x.size();
    double h = (x[1] - x[0]);
    double result = y[0] + y[n - 1];
    for (int i = 1; i < n - 1; i++)
    {
        if (i % 6 == 0)
            result += 2 * y[i];
        else if (i % 3 == 0)
            result += 6 * y[i];
        else if (i % 2 == 0)
            result += y[i];
        else
            result += 5 * y[i];
    }

    result = 3 * h * result / 10;
    return result;
}

int main()
{
    int n ;
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
    // x = {25, 25.1, 25.2, 25.3, 25.4, 25.5, 25.6};
    // y = {3.205, 3.217, 3.232, 3.245, 3.256, 3.268, 3.28};
    cout << "Weddle's rule : " << weddle(x, y) << endl;
    return 0;
}