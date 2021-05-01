vector<string> letterCombinationsInternal(unordered_map<char, string> &mapping, string digits) {
    vector<string> res;

    if (digits.length() == 0) {
        return res;
    }

    vector<string> rec = letterCombinationsInternal(mapping, digits.substr(1));
    if(rec.empty()) rec.emplace_back("");
    for (const string &str: rec) {
        string mp = mapping[digits[0]];
        for (char i : mp) {
            res.push_back(i + str);
        }

    }
    return res;
}

vector<string> letterCombinations(string digits) {
    unordered_map<char, string> mapping(1);
    mapping['2'] = "abc";
    mapping['3'] = "def";
    mapping['4'] = "ghi";
    mapping['5'] = "jkl";
    mapping['6'] = "mno";
    mapping['7'] = "pqrs";
    mapping['8'] = "tuv";
    mapping['9'] = "wxyz";
    return letterCombinationsInternal(mapping, digits);
}

int main() {
    vector<string> res = letterCombinations("22");

    for (string s: res) {
        cout << s << ", ";
    }
    cout << endl;

    return 0;
}
