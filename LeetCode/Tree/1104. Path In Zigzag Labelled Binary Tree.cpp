void pathInternal(int label, int mn, vector<int> &res) {
    if (mn == -1) return;
    res.push_back(label);

    int prev = (int) (3 * pow(2, mn) - label - 1) / 2;
    pathInternal(prev, mn - 1, res);
}

vector<int> pathInZigZagTree(int label) {
    vector<int> res;

    int mn = (int) log2(label);
    pathInternal(label, mn, res);

    reverse(res.begin(), res.end());
    return res;
}

int main() {
    vector<int> res = pathInZigZagTree(26);

    for (int i: res) {
        cout << i << ", ";
    }
    return 0;
}
