void generateInternal(int n, int c, vector<string> &res, string sofar) {
    if (c < 0 || c > n) return;

    if (n == 0) {
        res.push_back(sofar);
        return;
    }

    generateInternal(n-1, c+1, res, sofar + "(");
    generateInternal(n-1, c-1, res, sofar + ")");
}

vector<string> generateParenthesis(int A) {
    vector<string> res;
    string sofar;

    generateInternal(2 * A, 0, res, sofar);

    return res;
}

int main() {
    vector<string> res = generateParenthesis(4);

    for (auto &e: res) {
        cout << e << " ";
    }

    return 0;
}
