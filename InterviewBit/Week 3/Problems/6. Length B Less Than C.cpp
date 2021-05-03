int lengthBLessC(vector<int> &A, int B, int C) {
    string cstr = to_string(C);
    int    n    = A.size();
    int    res  = 0;

    unordered_set<int> set;
    unordered_map<int, int> less(0);
    for (int i = 0; i <= 9; i++)
        for (int j = 0; j < n; j++)
            less[i] += (A[j] < i);

    for (int j = 0; j < n; j++)
        set.insert(A[j]);

    if (cstr.length() > B && n > 0) {
        int ls = (A[0] == 0 && B != 1) ? n - 1 : n;
        return int(ls * pow(n, B-1));
    } else if (cstr.length() < B || n == 0) {
        return 0;
    }

    for (int i = 0; i < cstr.length(); i++) {
        int digit = cstr[i] - '0';
        int ls    = less[digit];

        ls -= (i == 0 && A[0] == 0 && B != 1);

        res += int(ls * pow(n, (B - i - 1)));
        if (set.find(digit) == set.end()) break;
    }

    return res;
}

int main() {
    vector<int> A = {};
    cout << lengthBLessC(A, 0, 0) << endl;

    vector<int> A1 = {2, 3, 5, 6, 7, 9};
    cout << lengthBLessC(A1, 5, 42950) << endl;

    return 0;
}