bool prerequisitesInternal(vector<vector<int>> &graph, int root, vector<int> &visited) {
    if (visited[root] == 1) { // in process
        return false;
    }

    visited[root] = 1; // now processing
    for (int child: graph[root]) {
        if (visited[child] != 2) {
            if (!prerequisitesInternal(graph, child, visited)) {
                return false;
            }
        }
    }
    visited[root] = 2; // done processing

    return true;
}

int prerequisites(int A, vector<int> &B, vector<int> &C) {
    vector<vector<int>> graph(A + 1);
    vector<int> visited(A + 1, 0);
    unordered_set<int> set;

    for (int i = 1; i <= A; i++) {
        set.insert(i);
    }

    for (int i = 0; i < C.size(); i++) {
        graph[B[i]].push_back(C[i]);
        set.erase(C[i]);
    }

    for (int v: set) {
        if (!prerequisitesInternal(graph, v, visited)) {
            return false;
        }
    }

    return !set.empty();
}

int main() {
    int         A1 = 3;
    vector<int> B1 = {1, 2};
    vector<int> C1 = {2, 3};

    int         A2 = 2;
    vector<int> B2 = {1, 2};
    vector<int> C2 = {2, 1};

    cout << prerequisites(A1, B1, C1) << endl;
    cout << prerequisites(A2, B2, C2) << endl;

    return 0;
}