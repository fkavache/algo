vector<string> wordBreakInternal(string A, unordered_set<string> &set, int idx, vector<vector<string>> &dp) {
    int n = A.length();

    vector<string> res;

    if (!dp[idx].empty()) {
        return dp[idx];
    }

    if (idx == n) {
        return res;
    } else {
        string curr;
        for (int i = idx; i < n; i++) {
            curr += A[i];
            if (set.find(curr) != set.end()) {
                vector<string> rec = wordBreakInternal(A, set, i + 1, dp);
                for (auto &e: rec) {
                    res.push_back(curr + " " + e);
                }

                if (i == n - 1) {
                    res.push_back(curr);
                }
            }
        }
    }

    dp[idx] = res;
    return res;
}

vector<string> wordBreak(string A, vector<string> &B) {
    sort(B.begin(), B.end());
    vector<vector<string>> dp(A.length() + 1);
    unordered_set<string> set;

    for (auto &e: B) {
        set.insert(e);
    }

    vector<string> res = wordBreakInternal(A, set, 0, dp);

    sort(res.begin(), res.end());

    return res;
}

int main() {
    vector<string> B1 = {"bababbbb", "bbbabaa", "abbb", "a", "aabbaab", "b", "babaabbbb", "aa", "bb"};
    vector<string> B2 = {"c", "cs", "a", "sa", "d"};

    vector<string> res1 = wordBreak("aabbbabaaabbbabaabaab", B1);
    vector<string> res2 = wordBreak("csad", B2);

    for (auto &e: res2) {
        cout << e << ", ";
    }

    return 0;
}
