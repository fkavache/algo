
void insert(vector<bool> &v, vector<int> &res, int i, int idx) {
    if (i != 1) res[idx + i] = i;

    res[idx] = i;
    v[i] = true;
}

void remove(vector<bool> &v, vector<int> &res, int i, int idx) {
    if (i != 1) res[idx + i] = 0;

    res[idx] = 0;
    v[i] = false;
}

vector<int> constructInternal(int n, int idx, vector<bool> &v, vector<int> &res) {
    if (idx == res.size()) {
        return res;
    }

    if (res[idx] != 0) return constructInternal(n, idx + 1, v, res);
    for (int i = n; i > 0; i--) {
        if (!v[i]) {
            if (i == 1 || (idx + i < res.size() && res[idx + i] == 0)) {
                insert(v, res, i, idx);

                vector<int> rec = constructInternal(n, idx + 1, v, res);
                if (!rec.empty()) return rec;

                remove(v, res, i, idx);
            }
        }
    }

    return vector<int>();
}

vector<int> constructDistancedSequence(int n) {
    vector<int> res(n * 2 - 1);
    vector<bool> v(n + 1);

    return constructInternal(n, 0, v, res);
}

int main() {
    vector<int> res = constructDistancedSequence(7);

    for (int i: res) {
        cout << i << ", ";
    }

    return 0;
}