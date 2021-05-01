int isPower(int A) {
    int sq = (int)sqrt(A);
    for (int i = sq; i >= 2; i--) {
        int x = A;
        while (x % i == 0) {
            x /= i;
            if (x == 1) {
                return 1;
            }
        }
    }
    return A == 1;
}

int isPower(int A) {
    for (int i = 2; i*i <= A; i++) {
        int c = log(A)/log(i);
        if (pow(i,c) == A) {
            return 1;
        }
    }

    return A == 1;
}

int main() {
    for (int i = 1; i <= 100; i++) {
        cout << i << ": " << isPower(i) << endl;
    }
    cout << 536870912 << ": " << isPower(536870912) << endl;

    return 0;
}
