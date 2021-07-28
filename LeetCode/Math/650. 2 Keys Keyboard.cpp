bool isPrime(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int getFactor(int n) {
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0 && isPrime(i)) {
            return i;
        }
    }
    return n;
}

int minSteps(int n) {
    int res = 0;

    while (n > 1) {
        int factor = getFactor(n);
        res += factor;
        n /= factor;
    }

    return res;
}

int main() {
    cout << minSteps(5) << endl;
    cout << minSteps(36) << endl;
    cout << minSteps(7) << endl;
    cout << minSteps(10) << endl;

    return 0;
}

