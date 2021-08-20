bool isValid(vector<string> &A, int i, int j, vector<vector<bool>> &visited) {
    return (i >= 0 && i < A.size()) && (j >= 0 && j < A[0].length())
        && (A[i][j] == 'X') && (!visited[i][j]);
}

void blackInternal(vector<string> &A, int i, int j, vector<vector<bool>> &visited) {
    visited[i][j] = true;

    if (isValid(A, i, j + 1, visited)) blackInternal(A, i, j + 1, visited);
    if (isValid(A, i + 1, j, visited)) blackInternal(A, i + 1, j, visited);
    if (isValid(A, i, j - 1, visited)) blackInternal(A, i, j - 1, visited);
    if (isValid(A, i - 1, j, visited)) blackInternal(A, i - 1, j, visited);
}

int black(vector<string> &A) {
    int n = A.size();
    int m = A[0].length();
    int component = 0;
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (A[i][j] == 'X' && !visited[i][j]) {
                blackInternal(A, i, j, visited);
                component++;
            }
        }
    }

    return component;
}

int main() {
    vector<string> A1 = {
        "OOOXOOO",
        "OOXXOXO",
        "OXOOOXO",
        "OXXXXXO"
    };

    vector<string> A2 = {
        "OOOXOOO"
    };

    vector<string> A3 = {
        "XXX",
        "XXX",
        "XXX"
    };


    cout << black(A1) << endl;
    cout << black(A2) << endl;
    cout << black(A3) << endl;

    return 0;
}