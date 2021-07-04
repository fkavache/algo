vector<int> findSubstring(string A, const vector<string> &B) {
    int len = B[0].length();
    int an  = A.length();
    int n   = B.size();
    int sn  = n * len;

    unordered_map<string, int> map;
    vector<int> res;

    for (int i = 0; i < n; i++) map[B[i]]++;
    for (int i = 0; i < an; i++) {
        unordered_map<string, int> mp = map;
        int j = i;
        while (!mp.empty()) {
            string curr = A.substr(j, len);
            if (mp.find(curr) != mp.end()) {
                mp[curr]--;
                if (mp[curr] == 0) mp.erase(curr);
                j += len;
            } else {
                break;
            }
        }

        if (j - i == sn) res.push_back(i);
    }

    return res;
}

int main() {
    vector<string> B = {"foo", "bar"};
    vector<int> res = findSubstring("barfoothefoobarman", B);

    for (int i: res) {
        cout << i << ", ";
    }

    return 0;
}
