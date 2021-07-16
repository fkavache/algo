bool getN(int b, int &N) {
    N = 0;
    while ((128 & b) == 128) {
        b <<= 1;
        N++;
    }

    N = (N == 1) ? 5 : N;
    N = (N == 0) ? 1 : N;

    return N <= 4;
}

bool checkByte(int b) {
    return (192 & b) == 128;
}

bool validUtf8(vector<int>& data) {
    int n = data.size();

    int i = 0;
    while (i < n) {
        int nb = 0;
        bool nchk = getN(data[i], nb);
        if (!nchk || i + nb > n) return false;
        int j = 0;
        while (j < nb - 1) {
            bool chk = checkByte(data[j + i + 1]);
            if (!chk) return false;
            j++;
        }
        i += nb;
    }

    return true;
}

int main() {
    vector<int> A1 = {197, 130, 1};
    vector<int> A2 = {235, 140, 4};
    vector<int> A3 = {225, 130, 129};
    vector<int> A4 = {241, 130, 129, 129, 225, 130, 129, 177};
    vector<int> A5 = {241, 130, 129, 129, 225, 130, 129, 1};
    vector<int> A6 = {177};
    vector<int> A7 = {1};

    cout << validUtf8(A1) << endl;
    cout << validUtf8(A2) << endl;
    cout << validUtf8(A3) << endl;
    cout << validUtf8(A4) << endl;
    cout << validUtf8(A5) << endl;
    cout << validUtf8(A6) << endl;
    cout << validUtf8(A7) << endl;

    return 0;
}