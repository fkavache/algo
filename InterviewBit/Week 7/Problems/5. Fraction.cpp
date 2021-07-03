#define ll long long

int fractionRec(ll A, ll B, string &res, map<ll, int> &map, int &d) {
    ll nA = 10 * A;
    if (A == 0) return -1;
    if (map.find(nA) != map.end()) return map[nA];

    res += to_string(nA / B);
    map[nA] = d++;

    return fractionRec(nA % B, B, res, map, d);
}

string fractionInternal(ll A, ll B) {
    map<ll, int> map;
    string l = to_string(A / B);
    string r = "";
    int    d = 0;

    int idx = fractionRec(A % B, B, r, map, d);
    if (idx != -1) {
        r = r.substr(0, idx) + "(" + r.substr(idx) + ")";
    }

    return r.empty() ? l : l + "." + r;
}

string fractionToDecimal(int A, int B) {
    string res = fractionInternal(abs((ll) A), abs((ll) B));
    if ((A < 0 && B >= 0) || (A > 0 && B < 0)){
        res = "-" + res;
    }
    return res;
}

int main() {
    cout << fractionToDecimal(-1, INT_MIN) << endl;
    cout << fractionToDecimal(INT_MIN, -1) << endl;
    cout << fractionToDecimal(1, 105)      << endl;
    cout << fractionToDecimal(1, 100)      << endl;
    cout << fractionToDecimal(87, 22)      << endl;
    cout << fractionToDecimal(10, -2)      << endl;
    cout << fractionToDecimal(359, 7)      << endl;
    cout << fractionToDecimal(10, 5)       << endl;
    cout << fractionToDecimal(10, 2)       << endl;
    cout << fractionToDecimal(0, -2)       << endl;
    cout << fractionToDecimal(-1, 2)       << endl;

    return 0;
}
