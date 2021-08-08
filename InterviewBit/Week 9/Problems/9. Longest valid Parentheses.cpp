int longestValidParentheses(string A) {
    int n = A.size();

    stack<int> s;
    s.push(-1);

    int res  = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == '(') {
            s.push(i);
        } else {
            s.pop();
            if (!s.empty()) {
                res = max(res, i - s.top());
            } else {
                s.push(i);
            }
        }
    }

    return res;
}

int main() {
    cout << longestValidParentheses("(()") << endl;
    cout << longestValidParentheses("))))()())))") << endl;
    cout << longestValidParentheses("()") << endl;
    cout << longestValidParentheses("(") << endl;
    cout << longestValidParentheses("()()()()()") << endl;

    return 0;
}