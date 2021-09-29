// o(log(min(a, b))) - time
// o(log(min(a, b))) - space
int multiplyInternal(int a, int b, vector<int> &memo) {
    if (a == 0) return 0;
    if (a == 1) return b;

    if (memo[a] == -1) {
        int res1 = multiplyInternal(a >> 1, b, memo);
        int res2 = res1;
        if (a & 1) {
            res2 = multiplyInternal(a - (a >> 1), b, memo);
        }

        memo[a] = res1 + res2;
    }
    
    return memo[a];
}

int multiply(int a, int b) {
    int aa = min(a, b);
    int bb = max(a, b);

    vector<int> memo(aa + 1, -1);

    return multiplyInternal(aa, bb, memo);
}

int main() {
    cout << multiply(51, 10) << endl;
    cout << multiply(5, 10)  << endl;
    cout << multiply(51, 1)  << endl;
    cout << multiply(2, 3)   << endl;
    cout << multiply(9, 3)   << endl;
    cout << multiply(0, 3)   << endl;

    return 0;
}
