int LDNodesInternal(vector<unordered_set<int>> &graph, int root, int &res) {
    if (graph[root].empty()) {
        return 1;
    }

    int max1 = 0;
    int max2 = 0;
    for (int child: graph[root]) {
        int recD = LDNodesInternal(graph, child, res);
        if (recD > max1) {
            max2 = max1;
            max1 = recD;
        } else if (recD > max2) {
            max2 = recD;
        }
    }

    res = max(res, max1 + max2);

    return max1 + 1;
}

int LDNodes(vector<int> &A) {
    int root = -1;
    int res  = 0;
    int N    = A.size();
    vector<unordered_set<int>> graph(N);

    for (int i = 0; i < N; i++) {
        if (A[i] == -1) {
            root = i;
        } else {
            graph[A[i]].insert(i);
        }
    }

    LDNodesInternal(graph, root, res);

    return res;
}

int main() {
    vector<int> A1 = {-1, 0, 0, 0, 3};
    vector<int> A2 = {-1, 0, 0, 0, 2, 2, 4, 5, 6, 7};
    vector<int> A3 = {-1, 0};

    cout << LDNodes(A1) << endl;
    cout << LDNodes(A2) << endl;
    cout << LDNodes(A3) << endl;

    return 0;
}