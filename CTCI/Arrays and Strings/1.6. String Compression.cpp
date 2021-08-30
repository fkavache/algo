// O(n) - time
// O(n) - space
string stringCompression(string str) {
    string res = string(1, str[0]);
    int count = 1;
    for (int i = 1; i < str.length(); i++) {
        if (str[i] == str[i - 1]) {
            count++;
        } else {
            res += to_string(count) + str[i];
            count = 1;
        }
    }

    res += to_string(count);

    return res.length() > str.length() ? str : res;
}

int main() {
    cout << stringCompression("aabcccccaaa") << endl;
    cout << stringCompression("abcdefg") << endl;
    cout << stringCompression("aaaaaaaaa") << endl;
    cout << stringCompression("paale") << endl;
    cout << stringCompression("cccceeeefffggh") << endl;

    return 0;
}
