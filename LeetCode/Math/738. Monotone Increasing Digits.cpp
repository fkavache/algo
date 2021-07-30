int monotoneIncreasingDigits(int n) {
    string nstr = to_string(n);
    int len =  nstr.length();

    string res = "";
    for (int i = 0; i < len - 1; i++) {
        if (nstr[i] > nstr[i + 1]) {
            int j = i;
            while (j > 0 && nstr[j] == nstr[j - 1]) j--;
            res = nstr.substr(0, j) + char(nstr[j] - 1) + string(len - j - 1, '9');
            break;
        }
    }

    return res == "" ? n : stoi(res);
}

int main() {
    cout << monotoneIncreasingDigits(12333342) << endl;
    cout << monotoneIncreasingDigits(12333332) << endl;
    cout << monotoneIncreasingDigits(99999999) << endl;
    cout << monotoneIncreasingDigits(10000) << endl;
    cout << monotoneIncreasingDigits(65) << endl;
    cout << monotoneIncreasingDigits(6) << endl;

    return 0;
}