void insert(unordered_set<string> &set, string val, int n) {
    if (val[0] != '0' && val.length() == n)
        set.insert(val);
}

unordered_set<string> numsSameInternal(int n, int k) {
    unordered_set<string> res;
    if (n == 1) {
        for (int i = 0; i < 10 - k; i++) res.insert(to_string(i));
        return res;
    }

    unordered_set<string> rec = numsSameInternal(n - 1, k);
    for (string i : rec) {
        int l = i[n-2] - '0';
        int f = i[0]   - '0';
        if (l + k < 10) insert(res, i + to_string(l + k), n);
        if (l - k >= 0) insert(res, i + to_string(l - k), n);
        if (f + k < 10) insert(res, to_string(f + k) + i, n);
        if (f - k >= 0) insert(res, to_string(f - k) + i, n);
    }

    return res;
}

vector<int> numsSameConsecDiff(int n, int k) {
    vector<int> res;

    unordered_set<string> rec_res = numsSameInternal(n, k);
    for (auto const &i: rec_res) res.push_back(stoi(i));

    return res;
}

int main() {
    vector<int> res = numsSameConsecDiff(2, 2);

    for (int re: res) cout << re << ", ";

    return 0;
}
