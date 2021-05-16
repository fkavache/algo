string multiply(string A, string B) {
    int an = A.length();
    int bn = B.length();
    vector<int> vec((unsigned int)(an + bn));

    for (int i = bn - 1; i >= 0; i--) {
        int currB = B[i] - '0';
        for (int j = an - 1; j >= 0; j--) {
            int currA = A[j] - '0';
            vec[i + j + 1] += currB * currA;
        }
    }

    // normalize
    int carry = 0;
    string res;
    for (int i = vec.size() - 1; i >= 0; i--) {
        int curr = vec[i] + carry;
        res = to_string(curr % 10) + res;
        carry = curr / 10;
    }

    int i = 0;
    while (res.length() > 1 && res[i] == '0') res = res.substr(1);

    return res;
}

int main() {
    cout << "9801: " << multiply("99", "99") << endl;
    cout << "228:  " << multiply("19", "12") << endl;
    cout << "10:   " << multiply("10", "1") << endl;
    cout << "5:    " << multiply("5", "1") << endl;
    cout << "0:    " << multiply("0", "1455") << endl;
    return 0;
}