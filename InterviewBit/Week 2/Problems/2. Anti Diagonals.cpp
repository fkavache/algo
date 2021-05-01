vector<vector<int>> diagonal(vector<vector<int> > &A) {
    unsigned int n  = A.size();
    unsigned int vs = 2 * n -1;

    vector<vector<int> > result(vs);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i + j].push_back(A[i][j]);
        }
    }

    return result;
}

void printMatrix(vector<vector<int>> mat) {
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int> > A = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    printMatrix(diagonal(A));

    return 0;
}
