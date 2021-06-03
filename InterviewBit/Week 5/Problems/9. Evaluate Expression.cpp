bool isOperand(const string &op) {
    return op == "+" || op == "-" || op == "*" || op == "/";
}

int getResult(const string &op, int a, int b) {
    if (op == "+") return a + b;
    if (op == "-") return a - b;
    if (op == "*") return a * b;

    return a / b;
}

int evalRPN(vector<string> &A) {
    int n = A.size();
    stack<int> s;

    for (int i = 0; i < n; i++) {
        if (isOperand(A[i])) {
            int a = s.top(); s.pop();
            int b = s.top(); s.pop();
        
            s.push(getResult(A[i], b, a));
        } else {
            s.push(stoi(A[i]));
        }
    }

    return s.top();
}

int main() {
    vector<string> A = {"5", "1", "2", "+", "4", "*", "+", "3", "-"};

    cout << evalRPN(A) << endl;

    return 0;
}