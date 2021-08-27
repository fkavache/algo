#include <bits/stdc++.h>

using namespace std;

// O(n) - time
// O(n) - space
bool checkPermutation1(string str1, string str2) {
    map<char, int> freq;

    for (char ch: str1) freq[ch]++;

    for (char ch: str2) {
        freq[ch]--;
        if (freq[ch] == 0) {
            freq.erase(ch);
        }
    }

    return freq.empty();
}

// O(nlogn) - time
// O(1)     - space
bool checkPermutation2(string str1, string str2) {
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());

    return str1 == str2;
}

int main() {
    cout << checkPermutation1("abcdefg", "defgabc")  << endl;
    cout << checkPermutation1("1234561", "1125634") << endl;
    cout << checkPermutation1("1234561", "1125633") << endl;

    return 0;
}
