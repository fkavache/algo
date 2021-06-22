int minTimeInternal(int root, int n, vector<bool> &A, vector<vector<int>> &g, vector<bool> &v) {
    v[root] = true;

    int res = 0;
    for (auto &i: g[root]) {
        if (!v[i]) {
            res += minTimeInternal(i, n, A, g, v);
        }
    }

    if (res == 0) return A[root] ? 2 : 0;

    return res + 2;
}

int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    vector<vector<int>> g(n + 1);
    vector<bool> v(n + 1);

    for (auto &edge: edges) {
        g[edge[0]].push_back(edge[1]);
        g[edge[1]].push_back(edge[0]);
    }

    int res = minTimeInternal(0, n, hasApple, g, v);
    return res != 0 ? res - 2 : 0;
}

int main() {
    vector<vector<int>> edges = {{0,1}, {0,2}, {1,4}, {1,5}, {2,3}, {2,6}};
    vector<bool> hasApple = {false, false, true, false, false, true, false};

    cout << minTime(7, edges, hasApple);

    return 0;
}
