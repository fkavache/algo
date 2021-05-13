vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> res;
    if (n == 1) return {1, 2, 3, 4, 5, 6, 7, 8, 9};

    vector<int> rec = numsSameConsecDiff(n - 1, k);
    for (int i : rec) {
        int l = i % 10;
        if (l + k >= 0 && l + k < 10)           res.push_back(i * 10 + l + k);
        if (l - k >= 0 && l - k < 10 && k != 0) res.push_back(i * 10 + l - k);
    }
    return res;
}

int main() {
    vector<int> res = numsSameConsecDiff(2, 1);
    for (int i: res) {
        cout << i << ", ";
    }
    return 0;
}
