struct Node {
    map<char, Node *> mp;
    int freq;
};

void prefixAdd(Node *root, string s, int i) {
    if (i < s.length()) {

        if (root->mp.find(s[i]) == root->mp.end()) {
            root->mp[s[i]] = new Node();
        }

        root->mp[s[i]]->freq++;

        prefixAdd(root->mp[s[i]], s, i + 1);
    }
}

string prefixRes(Node *root, string str) {
    string res = "";

    for (char ch: str) {
        if (root->freq == 1) break;
        res += ch;
        root = root->mp[ch];
    }

    return res;
}

vector<string> prefix(vector<string> &A) {
    vector<string> res;

    Node *root = new Node();

    for (string s: A) {
        prefixAdd(root, s, 0);
    }

    for (string s: A) {
        res.push_back(prefixRes(root, s));
    }

    return res;
}

int main() {
    vector<string> A = {"zebra", "dog", "duck", "dot"};

    vector<string> res = prefix(A);

    for (auto i: res) {
        cout << i << ",";
    }

    return 0;
}