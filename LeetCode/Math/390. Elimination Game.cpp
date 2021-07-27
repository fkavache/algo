int lastRemaining(int n) {
    int res = 1, step = 1;
    bool dir = true;

    while (n > 1) {
        if (dir) {
            res += step;
        } else {
            if (n & 1) res += step;
        }

        dir = !dir;
        step *= 2;
        n /= 2;
    }

    return res;
}

int main() {
    cout << lastRemaining(9)  << endl;
    cout << lastRemaining(10) << endl;
    cout << lastRemaining(20) << endl;
    cout << lastRemaining(21) << endl;

    return 0;
}

