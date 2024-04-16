#include <bits/stdc++.h>
using namespace std;

vector<double> GaussSeidel(const vector<vector<double>> &mat, const vector<double> &b, double tol = 1e-6, int maxIter = 1000) {
    int n = mat.size();
    vector<double> x(n, 0); 

    for (int iter = 0; iter < maxIter; ++iter) {
        vector<double> x_new(n);
        for (int i = 0; i < n; ++i) {
            double sigma = 0.0;
            for (int j = 0; j < n; ++j) {
                if (j != i) {
                    sigma += mat[i][j] * x[j];
                }
            }
            x_new[i] = (b[i] - sigma) / mat[i][i];
        }

        double error = 0.0;
        for (int i = 0; i < n; ++i) {
            error += abs(x_new[i] - x[i]);
        }
        if (error < tol) {
            cout << "Converged after " << iter + 1 << " iterations." << endl;
            return x_new;
        }

        x = x_new; 
    }

    cout << "Maximum number of iterations reached." << endl;
    return x;
}

int main() {
    int n;
    cout << "Enter the number of equations: ";
    cin >> n;

    vector<vector<double>> mat(n, vector<double>(n));
    vector<double> b(n);

    cout << "Enter the coefficients of the equations:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Equation " << i + 1 << ": ";
        for (int j = 0; j < n; ++j) {
            cin >> mat[i][j];
        }
        cout << "Enter the constant term for equation " << i + 1 << ": ";
        cin >> b[i];
    }

    vector<double> solution = GaussSeidel(mat, b);
    cout << "Solution:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "x" << i + 1 << " = " << solution[i] << endl;
    }

    return 0;
}
