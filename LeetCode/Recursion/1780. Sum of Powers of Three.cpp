bool checkPowersOfThreeInternal(int n, int i) {
    if (n == 0) return true;
    if (n < 0 || pow(3, i) > n) return false;

    return checkPowersOfThreeInternal(n - (int) pow(3, i), i + 1) || checkPowersOfThreeInternal(n, i + 1);
}

bool checkPowersOfThree(int n) {
    return n == 0 ? false : checkPowersOfThreeInternal(n, 0);
}

int main() {
    for (int i = 0; i <= 107; i++) {
        cout << i << ":" << checkPowersOfThree(i) << endl;
    }
    return 0;
}
