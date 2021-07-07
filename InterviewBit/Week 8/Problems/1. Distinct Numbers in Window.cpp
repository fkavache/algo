vector<int> dNums(vector<int> &A, int B) {
    unordered_map<int, int> freq;
    vector<int> res;
    int n = A.size();

    if (B > n) return res;

    int l = 0;
    for (int r = 0; r < n; r++) {
        freq[A[r]]++;
        if (r >= B) {
            freq[A[l]]--;
            if (freq[A[l]] == 0) {
                freq.erase(A[l]);
            }
            l++;
        }
        if (r >= B - 1) res.push_back(freq.size());
    }

    return res;
}

int main() {
    vector<int> A = {1, 2, 1, 3, 4, 3};

    vector<int> res = dNums(A, 3);

    for (int i: res) {
        cout << i << ", ";
    }

    return 0;
}