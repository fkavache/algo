// O(nlogn) - time
// O(1)     - space
bool palindromePermutation1(string str) {
    sort(str.begin(), str.end());

    bool odd = true;
    int oddCount = 0;
    for (int i = 0; i < str.length() - 1; i++) {
        if (str[i] == str[i + 1]) {
            odd = !odd;
        } else {
            oddCount += odd;
            odd = true;
        }
    }

    oddCount += odd;
    return oddCount < 2;
}

// O(n) - time
// O(n) - space
bool palindromePermutation2(string str) {
    set<char> s;

    for (char ch: str) {
        if (s.find(ch) == s.end()) {
            s.insert(ch);
        } else {
            s.erase(ch);
        }
    }

    return s.size() < 2;
}

int main() {
    cout << palindromePermutation1("aabbccdd") << endl;
    cout << palindromePermutation1("aabbccxdd") << endl;
    cout << palindromePermutation1("aabbcxdd") << endl;
    cout << palindromePermutation1("aabbcccdd") << endl;
    cout << palindromePermutation1("abc") << endl;
    cout << palindromePermutation1("abb") << endl;

    return 0;
}
