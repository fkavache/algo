bool onBorder(int N, int M, int i, int j) {
    return (i == 0 || i == N - 1 ) || (j == 0 || j == M - 1);
}

bool isValid(vector<vector<char>> &A, vector<vector<bool>> &visited, int i, int j) {
    return (i >= 0 && i < A.size()) && (j >= 0 && j < A[0].size()) && (A[i][j] == 'O') && (!visited[i][j]);
}

void regionsInternal(vector<vector<char>> &A, vector<vector<char>> &AC, vector<vector<bool>> &visited, vector<int> &dx, vector<int> &dy, int i, int j) {
    AC[i][j] = 'O';
    visited[i][j] = true;

    for (int k = 0; k < 4; k++) {
        if (isValid(A, visited, i + dx[k], j + dy[k])) {
            regionsInternal(A, AC, visited, dx, dy, i + dx[k], j + dy[k]);
        }
    }
}

void regions(vector<vector<char>> &A) {
    int N = A.size();
    int M = A[0].size();

    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, 1, 0, -1};

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    vector<vector<char>> AC(N, vector<char>(M, 'X'));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 'O' && !visited[i][j] && onBorder(N, M, i, j)) {
                regionsInternal(A, AC, visited, dx, dy, i, j);
            }
        }
    }

    A = AC;
}

int main() {
    vector<vector<char>> A1 = {
            {'X','X','X','X'},
            {'X','O','O','X'},
            {'X','X','O','X'},
            {'X','O','X','X'},
            {'X','X','O','O'},
    };

    vector<vector<char>> A2 = {
            {'X','O','X','X','X','X','O','O','X','X'},
            {'X','O','O','O','O','X','O','O','X','X'},
            {'O','X','X','O','O','X','X','X','O','O'},
            {'O','X','O','X','O','O','O','X','X','O'},
            {'O','X','O','O','X','X','O','O','X','X'},
            {'O','X','X','X','O','X','X','O','X','O'},
            {'O','O','X','X','X','X','O','X','O','O'}
    };

    vector<vector<char>> A3 = {
            {'X','O','O','O','X','O','X','X','X','X'},
            {'X','O','X','O','X','O','O','X','X','X'},
            {'X','X','X','O','O','O','X','O','X','O'},
            {'O','X','X','X','O','X','O','X','O','X'}
    };

    regions(A1);

    for (auto vec: A1) {
        for (auto e: vec) {
            cout << e << ", ";
        }
        cout << endl;
    }

    return 0;
}
