void permutationsInternal(string str, string sofar, vector<string> &res) {
    if (str.empty()) {
        res.push_back(sofar);
    }

    set<char> visited;

    for (int i = 0; i < str.length(); i++) {
        if (visited.find(str[i]) == visited.end()) {
            visited.insert(str[i]);
            permutationsInternal(str.substr(0, i) + str.substr(i + 1), sofar + str[i], res);
        }
    }
}

// o(m!) - time
// o(m)  - space
vector<string> permutations(string str) {
    vector<string> res;

    permutationsInternal(str, "", res);

    return res;
}

int main() {
    vector<string> res = permutations("aabb");

    for (auto e: res) {
        cout << e << endl;
    }

    return 0;
}
