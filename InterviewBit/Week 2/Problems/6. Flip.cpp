vector<int> flip(string A) {
    vector<int> result;

    int c = 0;
    int L = -1;
    int R = -1;
    int max = INT_MIN;
    for (int i = 0; i < A.length(); i++) {
        if (A[i] == '1') {
            if (c > 0) c--;
            else L = -1;
        } else if (A[i] == '0') {
            if (L == -1) L = i;
            R = i;
            c++;
            if (c > max) {
                max = c;
                result.clear();
                result.push_back(L + 1);
                result.push_back(R + 1);
            }
        }
    }

    return result;
}

int main() {
    vector<int> res = flip("000111011010000");

    cout << res[0] << ", " << res[1] << endl;

    return 0;
}
