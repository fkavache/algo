// o(m!) - time
// o(m)  - space
vector<string> permutations1(string str) {
    vector<string> res;

    if (str.empty()) {
        res.push_back("");
    }

    for (int i = 0; i < str.length(); i++) {
        auto recRes = permutations1(str.substr(0, i) + str.substr(i + 1));
        for (auto e: recRes) {
            res.push_back(str[i] + e);
        }
    }

    return res;
}

// ----------------------------------------------------------------------

void permutations2Internal(string str, string sofar, vector<string> &res) {
    if (str.empty()) {
        res.push_back(sofar);
    }

    for (int i = 0; i < str.length(); i++) {
        permutations2Internal(str.substr(0, i) + str.substr(i + 1), sofar + str[i], res);
    }
}

// o(m!) - time
// o(m)  - space
vector<string> permutations2(string str) {
    vector<string> res;

    permutations2Internal(str, "", res);

    return res;
}

int main() {

    vector<string> res = permutations2("abcd");

    for (auto e: res) {
        cout << e << endl;
    }

    return 0;
}
