// o(2^n) - time
// o(n)   - space
void parenthesesInternal(int N, int curr, string sofar, vector<string> &res){
    if (curr < 0 || curr > N || sofar.length() > 2 * N) return;

    if (curr == 0 && sofar.length() == 2 * N) {
        res.push_back(sofar);
    } else {
        parenthesesInternal(N, curr + 1, sofar + "(", res);
        parenthesesInternal(N, curr - 1, sofar + ")", res);
    }
}

vector<string> parentheses(int N){
    vector<string> res;

    parenthesesInternal(N, 0, "", res);

    return res;
}

int main() {
    vector<string> res = parentheses(3);

    for (auto e: res) {
        cout << e << endl;
    }

    return 0;
}
