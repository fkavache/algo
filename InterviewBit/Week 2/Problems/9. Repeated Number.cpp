vector<int> repeatedNumber(const vector<int> &A) {
    long long diff1 = 0;
    long long diff2 = 0;
    for (int i = 0; i < A.size(); i++) {
        diff1 += (i + 1);
        diff1 -= (long long)A[i];
        diff2 += ((long long)(i + 1) * (long long)(i + 1));
        diff2 -= ((long long)A[i]    * (long long)A[i]);
    }

    vector<int> res(2);
    res[0] = (int) ((diff2 - diff1 * diff1) / (2 * diff1));
    res[1] = (int) diff1 + res[0];

    return res;
}

int main() {
    vector<int> A = {5, 3, 2, 5, 4};

    vector<int> res = repeatedNumber(A);

    cout << res[0] << ", " << res[1] << endl;

    return 0;
}


