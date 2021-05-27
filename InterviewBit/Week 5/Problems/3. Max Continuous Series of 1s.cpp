vector<int> maxOne(vector<int> &A, int B) {
    int n = A.size();
    vector<int> res;

    int l = 0;
    int b = B;
    int res_idx = 0;
    int res_len = 0;
    for (int r = 0; r < n; r++) {
        if (A[r] == 0) {
            b--;
        }
        while (b < 0) {
            if (A[l] == 0) b++;
            l++;
        }
        if (r - l + 1 > res_len) {
            res_len = r - l + 1;
            res_idx = l;
        }
    }

    for (int i = res_idx; i < res_idx + res_len; i++) {
        res.push_back(i);
    }

    return res;
}

int main() {
    vector<int> A = {1, 1, 0, 1, 1, 0, 0, 1, 1, 1};

    vector<int> res = maxOne(A, 1);
    for(int i: res) {
        cout << i << ", ";
    }

    return 0;
}