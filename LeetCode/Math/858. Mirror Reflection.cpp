int mirrorReflection(int p, int q) {
    int np = p;
    int nq = q;

    int uRefl = 0;
    int rRefl = 0;

    while (np != nq) {
        nq += q;
        rRefl++;
        if (nq > np) {
            np += p;
            uRefl++;
        }
    }

    if (rRefl % 2 == 0) {
        if (uRefl % 2 == 0) return 1;
        return 0;
    } else {
        if (uRefl % 2 == 0) return 2;
        return 1;
    }
}

int main() {

    cout << mirrorReflection(2, 2) << endl;
    cout << mirrorReflection(2, 2) << endl;
    cout << mirrorReflection(2, 1) << endl;
    cout << mirrorReflection(3, 1) << endl;
    cout << mirrorReflection(3, 2) << endl;

    return 0;
}