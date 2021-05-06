string getReversed(string A) {
    reverse(A.begin(), A.end());
    return A;
}

string smallestPalindrome(string A) {
    unsigned int n = A.length();
    bool isEven    = false;
    bool isZeroes  = false;

    if (n == 0) return A;

    if (n % 2 == 0) {
        A.insert(n/2, "9");
        isEven = true;
        n++;
    }
    bool needsInc = true;
    for (int i = n/2 - 1; i >=0; i--) {
        if (A[n-i-1] < A[i]) {
            needsInc = false;
            break;
        }
        if (A[n-i-1] > A[i]) break;
    }

    string res = A.substr(0, n/2 + 1);
    if (needsInc) {
        for (int i = res.length() - 1; i >= 0; i--) {
            if (res[i] == '9') {
                res[i] = '0';
                if (i == 0) isZeroes = true;
            } else {
                res[i] = char(res[i] + 1);
                break;
            }
        }
    }

    res = res + getReversed(res.substr(0, res.length() - 1));

    if (isEven)   res = res.substr(0, n/2) + res.substr(n/2 + 1);
    if (isZeroes) res = "1" + res.substr(1) + "1";

    return res;
}

int main() {
    cout << smallestPalindrome("2345632") << endl;
    return 0;
}