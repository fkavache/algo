int tripleStepInternal(int N, vector<int> &memo) {
    if (N < 0) {
        return 0;
    }

    if (N == 0) {
        return 1;
    }

    if (memo[N] != -1) {
        return memo[N];
    }

    int res = 0;
    res += tripleStepInternal(N - 1, memo);
    res += tripleStepInternal(N - 2, memo);
    res += tripleStepInternal(N - 3, memo);

    memo[N] = res;

    return res;
}

// o(n) - time
// o(n) - space
int tripleStep1(int N) {
    vector<int> memo(N + 1, -1);

    return tripleStepInternal(N, memo);
}

// o(n) - time
// o(1) - space
int tripleStep2(int N) {
    int a = 0;
    int b = 0;
    int c = 1;

    for (int i = 1; i <= N; i++) {
        int d = a + b + c;
        a = b;
        b = c;
        c = d;
    }

    return c;
}

int main() {

    cout << tripleStep1(2)  <<  " " << tripleStep2(2)  << endl;
    cout << tripleStep1(4)  <<  " " << tripleStep2(4)  << endl;
    cout << tripleStep1(10) <<  " " << tripleStep2(10) << endl;
    cout << tripleStep1(1)  <<  " " << tripleStep2(1)  << endl;
    cout << tripleStep1(50) <<  " " << tripleStep2(50) << endl;

    return 0;
}
