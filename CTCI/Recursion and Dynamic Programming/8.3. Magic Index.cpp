// o(log(n)) - time
// o(1)      - space
int magicIndex1(vector<int> &A) {
    int l = 0;
    int r = A.size() - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        if (A[mid] > mid) {
            r = mid - 1;
        } else if (A[mid] < mid) {
            l = mid + 1;
        } else {
            return mid;
        }
    }

    return -1;
}

// o(n)      - time
// o(log(n)) - space
int magicIndex2Internal(vector<int> &A, int l, int r) {
    if (l > r) {
        return -1;
    }

    int mid = (l + r) / 2;

    if (A[mid] == mid) {
        return mid;
    }

    int res = magicIndex2Internal(A, l, min(A[mid], mid - 1));
    if (res > -1) {
        return res;
    }

    return magicIndex2Internal(A, max(A[mid], mid + 1), r);
}

int magicIndex2(vector<int> &A) {
    return magicIndex2Internal(A, 0, A.size() - 1);
}

int main() {
    vector<int> A = {-2, -1, 1, 1, 1, 1, 1, 3, 4, 5, 10, 17, 18, 19, 110};

    cout << magicIndex1(A) << endl;
    cout << magicIndex2(A) << endl;

    return 0;
}
