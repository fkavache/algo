string minWindow(string A, string B) {
    int    n   = A.size();
    int    u   = 0;
    string res = "";

    unordered_map<char, int> Bm;
    unordered_map<char, int> Am;

    for (char ch: B) Bm[ch]++;

    u = Bm.size();

    int l = 0, c = 0;
    for (int r = 0; r < n; r++) {
        char ch = A[r];
        Am[ch]++;
        if(Am[ch] == Bm[ch]) c++;
        if (c >= u) {
            while (Am[A[l]] != Bm[A[l]]) {
                Am[A[l]]--;
                l++;
            }

            if (r - l + 1 < res.length() || res.empty()) {
                res = A.substr(l, r - l + 1);
            }
        }
    }

    return res;
}

int main() {
    cout << minWindow("AAD_ABNC_OB_ABCX", "ABC") << endl;
    cout << minWindow("AAAAAA", "AA") << endl;

    return 0;
}