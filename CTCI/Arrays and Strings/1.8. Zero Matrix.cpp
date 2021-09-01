void zeroRow(vector<vector<int>> &matrix, int i) {
    for (int j = 0; j < matrix[0].size(); j++) {
        matrix[i][j] = 0;
    }
}

void zeroCol(vector<vector<int>> &matrix, int j) {
    for (int i = 0; i < matrix.size(); i++) {
        matrix[i][j] = 0;
    }
}

// O(m * n)     - time
// O(max(m, n)) - space
void zeroMatrix(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    unordered_set<int> row;
    unordered_set<int> col;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == 0) {
                row.insert(i);
                col.insert(j);
            }
        }
    }

    for (int i: row) zeroRow(matrix, i);
    for (int j: col) zeroCol(matrix, j);
}

int main() {
    vector<vector<int>> matrix = {
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {1, 1, 1, 1, 1},
            {0, 1, 1, 1, 1},
    };

    zeroMatrix(matrix);

    for (auto e: matrix) {
        for (int i: e) {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}
