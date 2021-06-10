void letterInternal(string A, string sofar, map<char, string> &map, vector<string> &res) {
    if (A.length() == 0) {
        res.push_back(sofar);
        return;
    }

    string curr = map[A[0]];
    for (int i = 0; i < curr.length(); i++) {
        letterInternal(A.substr(1), sofar + curr[i], map, res);
    }
}

vector<string> letterCombinations(string A) {
    map<char, string> map;
    vector<string> res;

    map['0'] = "0";
    map['1'] = "1";
    map['2'] = "abc";
    map['3'] = "def";
    map['4'] = "ghi";
    map['5'] = "jkl";
    map['6'] = "mno";
    map['7'] = "pqrs";
    map['8'] = "tuv";
    map['9'] = "wxyz";

    letterInternal(A, "", map, res);

    return res;
}

int main() {
    vector<string> res = letterCombinations("1");

    for (auto &s: res) {
        cout << s << ", ";
    }
    return 0;
}
