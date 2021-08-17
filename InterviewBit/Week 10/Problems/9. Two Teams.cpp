int teamsInternal(int v, unordered_map<int, unordered_set<int>> &graph, unordered_set<int> &visited, vector<int> &colors) {
    visited.insert(v);

    for (int child: graph[v]) {
        if (colors[v] == colors[child]) return 0;
        colors[child] = colors[v] == 1 ? 2 : 1;

        if (visited.find(child) == visited.end()) {
            int rec = teamsInternal(child, graph, visited, colors);
            if (rec == 0) {
                return 0;
            }
        }
    }

    return 1;
}

int teams2(int A, vector<vector<int>> &B) {
    unordered_map<int, unordered_set<int>> graph;

    for (int i = 0; i < B.size(); i++) {
        graph[B[i][0]].insert(B[i][1]);
        graph[B[i][1]].insert(B[i][0]);
    }

    unordered_set<int> visited;
    vector<int> colors(A + 1, -1);

    for (int i = 1; i <= A; i++) {
        if (visited.find(i) == visited.end()) {
            colors[i] = 1;
            int rec = teamsInternal(i, graph, visited, colors);
            if (rec == 0) {
                return 0;
            }
        }
    }

    return 1;
}

// ---------------------------------------------------------------
// ---------------------------------------------------------------

int teams1(int A, vector<vector<int>> &B) {
    unordered_map<int, unordered_set<int>> graph;

    for (int i = 0; i < B.size(); i++) {
        graph[B[i][0]].insert(B[i][1]);
        graph[B[i][1]].insert(B[i][0]);
    }

    unordered_set<int> visited;
    vector<int> colors(A + 1, -1);
    for (int i = 1; i <= A; i++) {
        if (visited.find(i) == visited.end()) {
            queue<int> q;
            q.push(i);
            colors[i] = 1;

            visited.insert(i);
            while (!q.empty()) {
                int curr = q.front();
                q.pop();

                if (colors[curr] == -1) {
                    colors[curr] = 1;
                }

                for (int child: graph[curr]) {
                    if (colors[curr] == colors[child]) return 0;
                    colors[child] = colors[curr] == 1 ? 2 : 1;

                    if (visited.find(child) == visited.end()) {
                        q.push(child);
                        visited.insert(child);
                    }
                }

            }
        }
    }

    return 1;
}

int main() {
    vector<vector<int>> B1 = {
        {1, 2},
        {2, 3},
        {1, 5},
        {2, 4}
    };

    vector<vector<int>> B2 = {
        {1, 4},
        {3, 1},
        {4, 3},
        {2, 1}
    };

    cout << teams2(5, B1) << endl;
    cout << teams2(4, B2) << endl;

    return 0;
}