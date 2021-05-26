int longestSubstring(string s, int k) {
    int n = s.length();

    if (n == 0) return 0;

    int freq[26] = {};
    for (char ch: s) freq[ch - 'a']++;

    for (int i = 0; i < n; i++) {
        if (freq[s[i] - 'a'] < k) {
            int curr1 = longestSubstring(s.substr(0, i),       k);
            int curr2 = longestSubstring(s.substr(i+1, n-i-1), k);
            return max(curr1, curr2);
        }
    }

    return n;
}

int maxUnique(string s) {
    bool f[26] = {};
    int  res   = 0;
    for (char ch: s) {
        if (!f[ch - 'a']) {
            res++;
            f[ch - 'a'] = true;
        }
    }
    return res;
}

int longestSubstringSW(string s, int k) {
    int f[26] = {};
    int n     = s.length();
    int mu    = maxUnique(s);
    int res   = 0;
    for (int i = 1; i <= mu; i++) {
        memset(f, 0, sizeof(f));
        int l  = 0, r  = 0, u  = 0, uf = 0;
        while (r < n) {
            if (u <= i) {
                int ch = s[r] - 'a';
                if (f[ch] == 0) u++;
                f[ch]++;
                if (f[ch] == k) uf++;
                r++;
            } else {
                int ch = s[l] - 'a';
                if (f[ch] == k) uf--;
                f[ch]--;
                if (f[ch] == 0) u--;
                l++;
            }
            if (u == i && u == uf) {
                res = max(res, r-l);
            }
        }
    }
    return res;
}

int main() {
    cout << longestSubstringSW("abababbdabcabc", 2) << " 7"  << endl;
    cout << longestSubstringSW("abcdefghijklmn", 2) << " 0"  << endl;
    cout << longestSubstringSW("abcdefghijklmn", 1) << " 14" << endl;
    cout << longestSubstringSW("abbbcaabxbbydd", 2) << " 3"  << endl;
    cout << longestSubstringSW("abbbcaabbbdd",   2) << " 7"  << endl;
    cout << longestSubstringSW("abbbcaabbbdd",   1) << " 12" << endl;
    cout << longestSubstringSW("ababbc",         2) << " 5"  << endl;
    cout << longestSubstringSW("aaabb",          3) << " 3"  << endl;
    cout << longestSubstringSW("a",              1) << " 1"  << endl;
    cout << longestSubstringSW("",               2) << " 0"  << endl;

    return 0;
}