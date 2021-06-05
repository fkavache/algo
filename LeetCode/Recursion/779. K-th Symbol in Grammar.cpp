int kthInternal(int len, int k) {
    if (len <= 2) return k - 1;

    int chunk = len / 4;
    int CN = (k - 1) / chunk + 1;

    if (CN == 3) return kthInternal(len / 2, k - 1 * chunk);
    if (CN == 4) return kthInternal(len / 2, k - 3 * chunk);

    return kthInternal(len / 2, k);
}

int kthGrammar(int n, int k) {
    return kthInternal(1 << (n-1), k);
}

int main() {
    cout << kthGrammar(3, 1) << endl;

    return 0;
}