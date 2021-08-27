// O(n) - time
// O(n) - space
bool isUnique1(string str) {
    map<char, int> freq;

    for (char ch: str) {
        freq[ch]++;
        if (freq[ch] > 1) return false;
    }

    return true;
}

// O(nlogn) - time
// O(1)     - space
bool isUnique2(string str) {
    sort(str.begin(), str.end());

    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == str[i + 1]) return false;
    }

    return true;
}

int main() {
    cout << isUnique1("abcdefg")  << endl;
    cout << isUnique1("abcdefga") << endl;
    cout << isUnique1("12345678") << endl;
    cout << isUnique1("12342678") << endl;

    return 0;
}
