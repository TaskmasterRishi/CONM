#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<double>> &mat) {
    for (int i = 0; i < mat.size(); ++i) {
        for (int j = 0; j < mat[i].size(); ++j) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

void GaussJordon(vector<vector<double>> &mat) {
    int rows = mat.size();
    int cols = mat[0].size();

    int minDim = min(rows, cols);

    for (int i = 0; i < minDim; i++) {
        int maxIndex = i;
        for (int k = i + 1; k < rows; k++) {
            if (abs(mat[k][i]) > abs(mat[maxIndex][i])) {
                maxIndex = k;
            }
        }
        if (maxIndex != i) {
            swap(mat[i], mat[maxIndex]);
        }

        if (mat[i][i] == 0) {
            cerr << "Matrix is singular. Gauss-Jordan elimination cannot proceed." << endl;
            return;
        }

        double divisor = mat[i][i];
        for (int k = 0; k < cols; k++) {
            mat[i][k] /= divisor;
        }

        for (int j = 0; j < rows; j++) {
            if (j != i) {
                double multiplier = mat[j][i];
                for (int k = 0; k < cols; k++) {
                    mat[j][k] -= multiplier * mat[i][k];
                }
            }
        }
    }
}

int main() {
    int rows, cols;

    cout << "Enter the number of equations: ";
    cin >> rows;
    cout << "Enter the order of polynomial: ";
    cin >> cols;

    if (rows <= 0 || cols <= 0) {
        cout << "Invalid dimensions. Please enter positive integers." << endl;
        return 1; 
    }

    vector<vector<double>> mat(rows, vector<double>(cols, 0));

    cout << "Enter the elements of the matrix (" << rows << "x" << cols << "):" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << "Enter element at position (" << i << ", " << j << "): ";
            cin >> mat[i][j];
        }
    }

    GaussJordon(mat);

    cout << "The matrix after Gauss-Jordan elimination:" << endl;
    printMatrix(mat);

    return 0;
}
