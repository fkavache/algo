int maxPoints(vector<int> &A, vector<int> &B) {
    int n = A.size();

    unordered_map<double, int> map;

    int res = 0;
    for (int i = 0; i < n; i++) {
        int curr = 0, same = 0;
        for (int j = i + 1; j < n; j++) {
            int x = A[j] - A[i];
            int y = B[j] - B[i];

            if (x == 0 && y == 0) {
                same++;
            } else {
                double slope = x == 0 ? INT_MAX : double(y) / x;
                curr = max(curr, ++map[slope]);
            }
        }

        res = max(res, curr + same + 1);
        map.clear();
    }

    return res;
}

int main() {
    vector<int> A = {-1, 0, 1, 2, 3, 3};
    vector<int> B = {1,  0, 1, 2, 3, 4};

    cout << maxPoints(A, B) << endl;

    return 0;
}

