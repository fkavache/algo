vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int r = mat.size();
    int c = mat[0].size();

    vector<int> res;

    bool d = true;
    int i = 0, j = 0;
    while (true) {
        res.push_back(mat[i][j]);
        if (res.size() == r * c) break;
        if (d) {
            i--; j++;
            if (i < 0 || j >= c) d = !d;
            if (j >= c) {
                i+=2; j--;
            } else if (i < 0) {
                i++;
            }
        } else {
            i++; j--;
            if (i >= r || j < 0) d = !d;
            if (i >= r) {
                j+=2; i--;
            } else if (j < 0) {
                j++;
            }
        }
    }

    return res;
}

void print(vector<int> vec) {
    for (int e: vec) cout << e << ", ";
    cout << endl;
}

int main() {
    vector<vector<int>> mat1 = {
            {1,  2,  3,  4,  5,  6},
            {7,  8,  9,  10, 11, 12},
            {13, 14, 15, 16, 17, 18},
            {19, 20, 21, 22, 23, 24}
    };

    vector<vector<int>> mat2 = {
            {1,  2,  3},
            {4,  5,  6},
            {7,  8,  9},
            {10, 11, 12},
    };

    vector<vector<int>> mat3 = {
            {1,  2,  3, 4, 5, 6},
    };

    print(findDiagonalOrder(mat1));
    print(findDiagonalOrder(mat2));
    print(findDiagonalOrder(mat3));

    return 0;
}