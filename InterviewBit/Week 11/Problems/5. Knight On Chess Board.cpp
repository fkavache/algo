bool isValid(int A, int B, int i, int j, vector<vector<bool>> &visited) {
    return (i >= 1 && i <= A) && (j >= 1 && j <= B) && (!visited[i][j]);
}

void insert(int i, int j, queue<pair<int, int>> &q, vector<vector<bool>> &visited) {
    visited[i][j] = true;
    q.push(make_pair(i, j));
}

int knight(int A, int B, int C, int D, int E, int F) {
    queue<pair<int, int>> q;
    vector<vector<bool>> visited(A + 1, vector<bool>(B + 1, false));

    vector<int> dx = {-2, -1, -2, -1,  2,  1, 2, 1};
    vector<int> dy = {-1, -2,  1,  2 ,-1, -2, 1, 2};

    q.push(make_pair(C, D));
    visited[C][D] = true;

    int level = 0;
    int left  = 1;

    while (!q.empty()) {
        auto curr = q.front();
        int i = curr.first;
        int j = curr.second;
        q.pop();

        if (i == E && j == F) {
            return level;
        }

        for (int k = 0; k < 8; k++) {
            if (isValid(A, B, i + dx[k], j + dy[k], visited)) {
                insert(i + dx[k], j + dy[k], q, visited);
            }
        }

        left--;
        if (left == 0) {
            left = q.size();
            level++;
        }
    }

    return -1;
}

int main() {

    cout << knight(8, 8, 1, 7, 8, 8) << endl;
    cout << knight(8, 8, 8, 8, 8, 8) << endl;
    cout << knight(8, 8, 1, 1, 8, 8) << endl;

    return 0;
}