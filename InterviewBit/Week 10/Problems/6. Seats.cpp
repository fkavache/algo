#define mod 10000003
#define ll long long

int seats(string A) {
    int n = A.length();

    vector<int> occ;

    for (int i = 0; i < n; i++) {
        if (A[i] == 'x') {
            occ.push_back(i);
        }
    }

    ll  res = 0;
    int mid = occ.size() / 2;
    for (int i = 0; i < occ.size(); i++) {
        res = (res + (abs(occ[mid] - occ[i]) - abs(i - mid))) % mod;
    }

    return (int) res;
}

int main() {
    cout << seats("....x..xx...x..") << endl;

    return 0;
}