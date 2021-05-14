string longestCommonPrefix(vector<string> &A) {
    int n = A.size();
    string res;

    sort(A.begin(), A.end());

    string c1 = A[0];
    string c2 = A[n-1];
    for (int j = 0; j < min(c1.length(), c2.length()); j++) {
        if (c1[j] == c2[j]) res += c1[j];
        else break;
    }

    return res;
}

int main() {
//    vector<string> A = {"abcdefgh", "aefghijk", "abcefgh"};
//    vector<string> A = {"abab", "ab", "abcd"};
    vector<string> A = {"abcdefgh", "abcefgh"};
    cout << longestCommonPrefix(A) << endl;
    return 0;
}
