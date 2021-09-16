bool isRouteInternal(vector<unordered_set<int>> &graph, int source, int target, unordered_set<int> &visited) {
    if (source == target) {
        return true;
    }

    visited.insert(source);

    for (int child: graph[source]) {
        if (visited.find(child) == visited.end()) {
            bool isRoute = isRouteInternal(graph, child, target, visited);
            if (isRoute) {
                return true;
            }
        }
    }

    return false;
}

// O(v) + o(e) - time
// O(v)        - space
bool isRoute(vector<unordered_set<int>> &graph, int source, int target) {
    unordered_set<int> visited;

    return isRouteInternal(graph, source, target, visited);
}

int main() {
    int N = 7;

    vector<unordered_set<int>> graph(N + 1);

    graph[1].insert(2);
    graph[1].insert(3);

    graph[2].insert(4);
    graph[2].insert(3);

    graph[3].insert(4);

    graph[4].insert(5);

    graph[5].insert(4);
    graph[5].insert(6);

    graph[7].insert(4);

    cout << isRoute(graph, 1, 6) << endl;
    cout << isRoute(graph, 1, 7) << endl;

    cout << isRoute(graph, 2, 5) << endl;
    cout << isRoute(graph, 2, 7) << endl;

    return 0;
}