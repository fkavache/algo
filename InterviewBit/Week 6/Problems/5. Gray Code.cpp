vector<int> grayCode(int A) {
    if (A == 1) return {0, 1};

    vector<int> rec = grayCode(A - 1);

    for (int i = rec.size() - 1; i >= 0; i--) {
        rec.push_back(rec[i] + (1 << (A - 1)));
    }

    return rec;
}

void grayCodeInternal(int len, int c, vector<int> &res) {
    if (c == len) return;

    res.push_back(c ^ (c >> 1));
    grayCodeInternal(len, c + 1, res);
}

vector<int> grayCode2(int A) {
    vector<int> res;
    
    grayCodeInternal(1 << A, 0, res);
    return res;
}

int main() {
    vector<int> res = grayCode2(4);

    for (int e: res) {
        cout << e << ", ";
    }

    return 0;
}
