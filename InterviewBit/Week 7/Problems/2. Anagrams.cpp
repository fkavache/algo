vector<vector<int>> anagrams(const vector<string> &A) {
    int n = A.size();

    vector<vector<int>> res;
    unordered_map<string, vector<int>> map;

    for (int i = 0; i < n; i++) {
        string curr = A[i];
        sort(curr.begin(), curr.end());
        map[curr].push_back(i + 1);
    }

    for (auto const &e: map) {
        res.push_back(e.second);
    }

    return res;
}

int main() {
    vector<string> A = {"cat", "dog", "god", "tac", "gdo", "odg", "abc", "cba"};
    vector<vector<int>> res = anagrams(A);

    for (auto e: res) {
        for (int i:e) {
            cout << i << ", ";
        }
        cout << endl;
    }

    return 0;
}

