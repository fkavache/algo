int largestRectangleArea(vector<int> &A) {
    int n = A.size() + 1;

    stack<int> s;
    A.push_back(0);

    int res = 0;
    for (int R = 0; R < n; R++) {
        while (!s.empty() && A[s.top()] >= A[R]) {
            int H = A[s.top()];
            s.pop();
            int W = s.empty() ? R : R - s.top() - 1;

            res = max(res, W * H);
        }
        s.push(R);
    }

    return res;
}

int main() {
    vector<int> A = {2, 1, 5, 6, 2, 3};

    cout << largestRectangleArea(A) << endl;

    return 0;
}
