// O(nlogn) - time
// O(1)     - space
string URLify(string str, int len) {
    int extra = str.length() - len;

    for (int i = len - 1; i >= 0; i--) {
        if (str[i] != ' ') {
            str[i + extra] = str[i];
        } else {
            str[i + extra - 2] = '%';
            str[i + extra - 1] = '2';
            str[i + extra]     = '0';
            extra -= 2;
        }
    }

    return str;
}

int main() {
    cout << URLify("Mr John Smith    ", 13) << endl;
    cout << URLify("a b c    ", 5)          << endl;
    cout << URLify("      ", 2)             << endl;

    return 0;
}