bool buildOrderInternal(vector<unordered_set<int>> &graph, vector<int> &proc, vector<int> &result, int vertex) {
    if (proc[vertex] == 1) { // in progress
        return false;
    }

    proc[vertex] = 1;

    for (int child: graph[vertex]) {
        if (proc[child] != 2) { // not completed
            if (!buildOrderInternal(graph, proc, result, child)) {
                return false;
            }
        }
    }

    proc[vertex] = 2; //completed
    result.push_back(vertex);

    return true;
}

// o(v + e) - time
// o(v)     - space
vector<int> buildOrder(int N, vector<vector<int>> &dep) {
    vector<unordered_set<int>> graph(N);
    unordered_set<int>         vertices;
    vector<int>                proc(N, 0);
    vector<int>                result;

    for (int i = 0; i < N; i++) {
        vertices.insert(i);
    }

    for (int i = 0; i < dep.size(); i++) {
        graph[dep[i][1]].insert(dep[i][0]);
        vertices.erase(dep[i][0]);
    }

    // vertices with no dependants
    bool res = false;
    for (int i: vertices) {
        res = res || buildOrderInternal(graph, proc, result, i);
    }

    if (!res) result = {};

    return result;
}

int main() {
    vector<vector<int>> dep = {
            {1, 3},
            {4, 1},
            {2, 3},
            {5, 2},
            {2, 4},
            {0, 5},
//            {4, 0}, // cycle
    };

    vector<int> result = buildOrder(6, dep);

    for (int i: result) {
        cout << i << ", ";
    }

    return 0;
}