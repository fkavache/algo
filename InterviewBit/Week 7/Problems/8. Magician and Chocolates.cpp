int nchoc(int A, vector<int> &B) {
    priority_queue<int> q(B.begin(), B.end());

    int res = 0;
    for (int i = 0; i < A; i++) {
        int curr = q.top();
        q.pop();
        q.push(curr / 2);
        res = (res + curr % mod) % mod;
    }

    return res ;
}

int main() {
    vector<int> B = {2147483647, 2000000014, 2147483647};

    cout << nchoc(10, B) << endl;

    return 0;
}