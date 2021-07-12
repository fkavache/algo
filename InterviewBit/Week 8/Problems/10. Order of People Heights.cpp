void segmentTree(vector<pair<int, int>> &A, vector<int> &segTree, int lo, int hi, int pos) {
    if (lo == hi) {
        segTree[pos] = (A[lo].first != 0);
        return;
    }

    int mid = (lo + hi) / 2;
    segmentTree(A, segTree, lo, mid, 2 * pos + 1);
    segmentTree(A, segTree, mid + 1, hi, 2 * pos + 2);

    segTree[pos] = segTree[2 * pos + 1] + segTree[2 * pos + 2];
}

int queryInternal(vector<int> &segTree, int pos, int lo, int hi, int target) {
    if (lo == hi) return lo;

    int l = segTree[2 * pos + 1];

    int mid = (lo + hi) / 2;
    if (target >= l) {
        return queryInternal(segTree, 2 * pos + 2, mid + 1, hi, target - l);
    } else {
        return queryInternal(segTree, 2 * pos + 1, lo, mid, target);
    }
}

int query(vector<int> &segTree, int n, int target) {
    return queryInternal(segTree, 0, 0, n - 1, target);
}

void update(vector<int> &segTree, int lo, int hi, int pos, int target) {
    segTree[pos]--;
    if (lo == hi) return;

    int mid = (lo + hi) / 2;
    if (target <= mid) {
        update(segTree, lo, mid, 2 * pos + 1, target);
    } else {
        update(segTree, mid + 1, hi, 2 * pos + 2, target);
    }
}

vector<int> order(vector<int> &A, vector<int> &B) {
    int n  = A.size();
    int nn = 0;

    int pow = (int) log2(n);
    if (1 << pow == n) {
        nn = (1 << (pow + 1)) - 1;
    } else {
        nn = (1 << (pow + 2)) - 1;
    }

    vector<pair<int, int>> p(n);
    vector<int> res(n);
    vector<int> segTree(nn);

    for (int i = 0; i < n; i++) {
        p[i] = {A[i], B[i]};
    }

    sort(p.begin(), p.end());

    segmentTree(p, segTree, 0, n - 1, 0);

    for (int i = 0; i < n; i++) {
        int idx = query(segTree, n, p[i].second);
        res[idx] = p[i].first;
        update(segTree, 0, n - 1, 0, idx);
    }

    return res;
}


int main() {
    vector<int> A = {5, 3, 2, 6, 1, 4};
    vector<int> B = {0, 1, 2, 0, 3, 2};

    vector<int> res = order(A, B);

    for (auto i: res) {
        cout << i << ", ";
    }

    return 0;
}