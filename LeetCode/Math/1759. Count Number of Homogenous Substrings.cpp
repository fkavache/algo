#define mod 1000000007

int countHomogenous(string s) {
    int l = 0;
    int res = 0;
    for (int r = 0; r < s.length(); r++) {
        if (r > 0 && s[r] != s[r - 1]) l = r;
        res = (res + (r - l + 1)) %  mod;
    }

    return res % mod;
}

int main() {
    cout << countHomogenous("abbcccaa") << endl;
    cout << countHomogenous("xy") << endl;
    cout << countHomogenous("zzzzz") << endl;

    return 0;
}
