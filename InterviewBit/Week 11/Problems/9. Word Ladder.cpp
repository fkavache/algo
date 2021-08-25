bool areStepping(string &A, string &B) {
    int c = 0;
    for (int i = 0; i < A.size(); i++) {
        if (A[i] != B[i]) {
            c++;
        }
        if (c > 1) return false;
    }
    return true;
}

int wordLadder(string A, string B, vector<string> &C) {
    unordered_map<string, unordered_set<string>> graph;
    unordered_set<string> visited;
    queue<string> q;

    C.push_back(A);
    C.push_back(B);

    int n = C.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (areStepping(C[i], C[j])) {
                graph[C[i]].insert(C[j]);
                graph[C[j]].insert(C[i]);
            }
        }
    }

    visited.insert(A);
    q.push(A);
    int left = 1;
    int level = 1;

    while (!q.empty()) {
        string curr = q.front();
        q.pop();

        if (curr == B) {
            return level;
        }

        for (string child: graph[curr]) {
            if (visited.find(child) == visited.end()) {
                q.push(child);
                visited.insert(child);
            }
        }

        left--;
        if (left == 0) {
            left = q.size();
            level++;
        }
    }

    return 0;
}
