vector<int> strStrLps(const string B){
    vector<int> lps(B.size());
    int i = 0;
    int j = 1;
    while (j < B.size()) {
        if (B[i] == B[j]) {
            lps[j] = i + 1;
            i++;
            j++;
        } else {
            if (i == 0) {
                lps[j] = 0;
                j++;
            } else {
                i = lps[i - 1];
            }

        }
    }
    return lps;
}

int strStr(const string A, const string B) {
    if (B.size() == 0 || A.size() == 0) return -1;

    vector<int> lps = strStrLps(B);

    int i = 0;
    int j = 0;
    while (i < A.size()) {
        if (A[i] == B[j]) {
            i++;
            j++;
        } else {
            if (j == 0) {
                i++;
            } else {
                j = lps[j-1];
            }
        }

        if (j == B.size()) return i - j;
    }
    return -1;
}

int main() {
    cout << strStr("xxxbbbbbba", "bba") << endl;
    cout << strStr("abcd", "abcd") << endl;
    cout << strStr("abcde", "abcd") << endl;
    cout << strStr("This is an easy problem", "easy") << endl;
    cout << strStr("This is an easy problem", "") << endl;
    cout << strStr("", "") << endl;
    cout << strStr("bbaabbbbbaabbaabbbbbbabbbabaabbbabbabbbbababbbabbabaaababbbaabaaaba", "babaaa") << endl;
    cout << strStr("aabaaaababaabbbabbabbbaabababaaaaaababaaabbabbabbabbaaaabbbbbbaabbabbbbbabababbaaabbaabbbababbb", "bba") << endl;
    cout << strStr("aabaaaababaa", "bba") << endl;

    return 0;
}