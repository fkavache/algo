vector<int> slidingMaximum(const vector<int> &A, int B) {
    deque<int> q;
    vector<int> res;

    for (int i = 0; i < A.size(); i++) {
        if (i >= B && q.front() == A[i - B]) {
            q.pop_front();
        }
        if (A[i] >= q.front()) {
            while (!q.empty() && A[i] > q.front()) {
                q.pop_front();
            }
            q.push_front(A[i]);
        } else {
            while (!q.empty() && A[i] > q.back()) {
                q.pop_back();
            }
            q.push_back(A[i]);
        }
        if (i >= B - 1) res.push_back(q.front());
    }
    return res;
}

int main() {
    vector<int> A = {1, 3, -1, -3, 5, 3, 6, 7};
    vector<int> res = slidingMaximum(A, 3);

    for (int i: res) {
        cout << i << ", ";
    }

    return 0;
}
