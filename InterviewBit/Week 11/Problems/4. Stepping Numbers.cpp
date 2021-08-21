bool isValid(int sofar, int A, int B) {
    return sofar >= A && sofar <= B;
}

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------

vector<int> stepNum1(int A, int B) {
    vector<vector<int>> graph(10);
    vector<int> res;
    queue<int> q;

    graph[0] = {1};
    for (int i = 1; i < 9; i++) {
        graph[i] = {i - 1, i + 1};
    }
    graph[9] = {8};

    if (A == 0) res.push_back(0);
    for (int i = 1; i <= 9; i++) {
        q.push(i);
    }

    while (!q.empty()) {
        int curr = q.front();
        q.pop();

        if (isValid(curr, A, B)) {
            res.push_back(curr);
        }

        for (int e: graph[curr % 10]) {
            int sofar = curr * 10 + e;
            if (sofar <= B) {
                q.push(sofar);
            }
        }
    }

    return res;
}

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------

void stepNumInternal(vector<vector<int>> &graph, int root, int sofar, int A, int B, vector<int> &res) {
    if (isValid(sofar, A, B)) {
        res.push_back(sofar);
    }

    for (int e: graph[root]) {
        int recSofar = sofar * 10 + e;
        if (recSofar <= B) {
            stepNumInternal(graph, e, recSofar, A, B, res);
        }
    }
}

vector<int> stepNum2(int A, int B) {
    vector<vector<int>> graph(10);
    vector<int> res;

    graph[0] = {1};
    for (int i = 1; i < 9; i++) {
        graph[i] = {i - 1, i + 1};
    }
    graph[9] = {8};

    if (A == 0) res.push_back(0);
    for (int i = 1; i <= 9; i++) {
        stepNumInternal(graph, i, i, A, B, res);
    }

    sort(res.begin(), res.end());
    return res;
}

// ----------------------------------------------------------------------------------------------------
// ----------------------------------------------------------------------------------------------------

int main() {
    int A = 10;
    int B = 900;

    vector<int> res = stepNum2(A, B);

    for (int e: res) {
        cout << e << ", ";
    }

    return 0;
}