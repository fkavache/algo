void rotateT(vector<vector<int>>& matrix) {
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}

void rotateInternal(vector<vector<int>>& mat, int s, int n) {
    if (n > 1) {
        int k = n - 1 + s;
        for (int j = s; j < n - 1; j++) {
            int i = s;
            int tmp = mat[i][j];
            for (int m = 0; m < 4; m++) {
                int ni = j;
                int nj = k - i;

                int tmp2 = mat[ni][nj];
                mat[ni][nj] = tmp;
                tmp = tmp2;

                i = ni;
                j = nj;
            }
        }

        rotateInternal(mat, s + 1, n - 1);
    }
}

void rotate(vector<vector<int>>& matrix) {
    rotateInternal(matrix, 0, matrix.size());
}

void print(vector<vector<int>> &matrix) {
    for (auto m: matrix) {
        for (auto i: m) {
            cout << i << ", ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> grid1 = {
            {1,  2,  3,  4,  5},
            {6,  7,  8,  9,  10},
            {11, 12, 13, 14, 15},
            {16, 17, 18, 19, 20},
            {21, 22, 23, 24, 25}
    };

    vector<vector<int>> grid2 = {
            {1,  2,  3},
            {4,  5,  6},
            {7,  8,  9},
    };

    vector<vector<int>> grid3 = {
            {1, 2},
            {3, 4}
    };

    rotateT(grid1);
    print(grid1);

    rotateT(grid2);
    print(grid2);

    rotateT(grid3);
    print(grid3);

    return 0;
}