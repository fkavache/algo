string longestPalindromeDP(string A) {
    int n = A.length();
    vector<vector<int>> dp(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        if (i < n - 1)
            dp[i][i + 1] = A[i] == A[i + 1];
    }

    string res(1, A[0]);
    int step = 1;
    while (step < n) {
        int i = 0;
        int j = step;
        while (j < n) {
            dp[i][j] = dp[i][j] || (dp[i + 1][j - 1] && (A[i] == A[j]));
            if (dp[i][j] && j - i + 1 > res.length()){
                res = A.substr(i, j - i + 1);
            }
            i++; j++;
        }
        step++;
    }

    return res;
}

// -----------------------------------------------------------

string expand(string A, int i, int j) {
    int n = A.length();

    string res;
    if (A[i] == A[j]) {
        while (i > 0 && j < n - 1) {
            if (A[i - 1] == A[j + 1]) {
                i--;
                j++;
            } else break;
        }
        if (j - i + 1 > res.length()) {
            res = A.substr(i, j - i + 1);
        }
    }

    return res;
}

string longestPalindrome(string A) {
    int n = A.length();

    string res;
    for (int i = 0; i < n; i++) {
        string res1 = expand(A, i, i);
        string res2 = expand(A, i, i + 1);

        if (res1.length() > res.length()) res = res1;
        if (res2.length() > res.length()) res = res2;
    }

    return res;
}

int main() {
    cout << longestPalindrome("caccbcbaabacabaccacaaccaccaaccbbcbcbbaacabccbcccbbacbbacbccaccaacaccbbcc") << endl;
    cout << longestPalindrome("abbcccbbbcaaccbababcbcabca") << endl;
    cout << longestPalindrome("abcdefghhgfedcba") << endl;
    cout << longestPalindrome("abbcccbbbc") << endl;
    cout << longestPalindrome("abcdefgh") << endl;
    cout << longestPalindrome("aaba") << endl;
    cout << longestPalindrome("caba") << endl;
    cout << longestPalindrome("abb") << endl;
    cout << longestPalindrome("cddc") << endl;
    cout << longestPalindrome("bb") << endl;
    cout << longestPalindrome("ab") << endl;
    cout << longestPalindrome("b") << endl;
    cout << longestPalindrome("") << endl;
    
    return 0;
}