int getGoodNum(vector<int> &A, int B) {
    int n = A.size();
    vector<int> freq(n + 1);

    int res = 0, l = 0, r = 0, u = 0;
    while (r < n) {
        if (freq[A[r]] == 0) u++;
        freq[A[r]]++;

        while (u > B) {
            freq[A[l]]--;
            if (freq[A[l]] == 0) u--;
            l++;
        }

        res += r - l + 1;
        r++;
    }

    return res;
}

int goodSubarrays(vector<int> &A, int B) {
    return getGoodNum(A, B) - getGoodNum(A, B - 1);
}

int main() {
//    vector<int> A = {1, 2, 1, 2, 1, 2, 1, 2, 3};
//    vector<int> A = {1, 1, 1, 1, 2, 2, 2, 2, 3};
    vector<int> A = {5, 3, 5, 1, 3};

    cout << goodSubarrays(A, 3) << endl;

    return 0;
}