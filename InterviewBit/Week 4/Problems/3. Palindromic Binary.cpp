string getReversed(string str) {
    reverse(str.begin(), str.end());
    return str;
}

int binPalindrome(int A) {
    int len = 1;
    int n   = 1;
    int k   = 0;
    while (true) {
        if ((n + pow(2, k)) > A) break;
        len++;
        n += (int) pow(2, k);
        k += len % 2;
    }

    auto half = (unsigned int ) (len / 2 + len % 2 - 1);
    string bin = "1" + string(half, '0');
    for (int i = 0; i < A-n; i++) {
        for (int j = bin.length() - 1; j >= 0; j--) {
            if (bin[j] == '0') {
                bin[j] = '1';
                break;
            } else {
                bin[j] = '0';
            }
        }
    }
    bin = (len % 2 == 0)
            ? bin + getReversed(bin)
            : bin + getReversed(bin.substr(0, bin.length() - 1));

    int res = 0;
    for (int i = bin.length() - 1; i >= 0; i--) {
        res <<= 1;
        if (bin[i] == '1') res |= 1;
    }

    return res;
}

int main() {
    for (int i = 1; i < 20; i++) {
        cout << i << ": " << binPalindrome(i) << endl;
    }
    return 0;
}