int singleNumber(const vector<int> &A) {
    int res = 0;
    for (int i : A) res ^= i;
    return res;
}

int main() {
    vector<int> A = {1, 2, 2, 3, 1};
    cout << singleNumber(A);
    return 0;
}