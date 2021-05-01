vector<vector<int>> spiralOrderMatrix(int A) {
    vector<vector<int>> mat(A, vector<int>(A));

    int min = 0;
    int max = A - 1;
    int num = 1;
    int i = 0;
    int j = 0;
    int d = 0;
    while (true) {
        mat[i][j] = num;

        if (num == A*A) break;
        if (d == 0) {
            j++;
            if (j == max) d++;
        } else if (d == 1) {
            i++;
            if (i == max) d++;
        } else if (d == 2) {
            j--;
            if (j == min) d++;
        } else if (d == 3) {
            i--;
            if (i == (min + 1)){
                d = 0;
                min++;
                max--;
            }
        }

        num++;
    }

    return mat;
}

vector<int> spiralOrderMatrixReversed(const vector<vector<int> > &A) {
    vector<int> result;

    int n = A[0].size();
    int m = A.size();

    int max_r = n - 1;
    int max_c = m - 1;
    int dir   = (n == 1) ? 1 : 0;
    int i     = 0;
    int j     = 0;
    int min   = 0;
    while (true) {
        if (result.size() == m*n) {
            break;
        }
        result.push_back(A[i][j]);

        if (dir == 0) {
            j++;
            if (j == max_r) dir++;
        } else if (dir == 1) {
            i++;
            if (i == max_c) dir++;
        } else if (dir == 2) {
            j--;
            if (j == min) dir++;
        } else if (dir == 3) {
            i--;
            if (i == min + 1) {
                dir = 0;
                max_r--;
                max_c--;
                min++;
            }
        }
    }
    return result;
}

void printMatrix(vector<vector<int>> &A) {
    for (int i = 0; i < A.size(); i++) {
        for (int j = 0; j < A[0].size(); j++) {
            cout << A[i][j] << ", ";
        }
        cout << endl;
    }
}

void printVector(vector<int> &A) {
    for (int i : A) {
        cout << i << ", ";
    }
    cout << endl;
}

int main() {
    vector<vector<int>> res = spiralOrderMatrix(5);
    vector<int> ser = spiralOrderMatrixReversed(res);

    printMatrix(res);
    printVector(ser);

    return 0;
}
