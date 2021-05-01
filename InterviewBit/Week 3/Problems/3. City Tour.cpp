#define ll  long long
#define mod 1000000007

int city_tour(int A, vector<int> &B) {
    vector<int> unvisited;
    const int   f_n       = 10000;
    int         v_n       = B.size();
    ll          fact[f_n] = {1};
    int         uv_n      = 0;
    ll          unn       = 1;
    ll          nn        = 1;
    ll          res       = 1;

    unvisited.push_back(B[0]- 1);
    for (int i = 1; i < v_n; i++) {
        unvisited.push_back(B[i] - B[i - 1] - 1);
    }
    unvisited.push_back(A - B[v_n - 1]);

    uv_n = unvisited.size();

    for (int i = 1; i < f_n; i++) {
        fact[i] = (i * fact[i - 1]) % mod;
    }

    for (int i = 0; i < uv_n; i++) {
        unn = (unn * fact[unvisited[i]]) % mod;
        if (i > 0 && i < uv_n - 1) {
            nn  = (nn  * (ll) (pow(2, unvisited[i] - 1))) % mod;
        }
    }

    res = (fact[A - v_n] * nn) % mod;
    res = (res * (ll) pow(unn, mod - 2)) % mod;

    return (int) res;
}

int main() {
    vector<int> B = {3};
    cout << city_tour(5, B) << endl;
    return 0;
}
