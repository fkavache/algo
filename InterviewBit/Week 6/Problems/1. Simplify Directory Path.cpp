
bool isDir(char ch) {
    return ch == '/';
}

bool isParent(const string &s) {
    return s == "..";
}

bool isPath(const string &s) {
    return !s.empty() && s != ".";
}

string simplifyPath2(string A) {
    int n = A.length() + 1;

    A.append("/");

    string cur = "";
    string res = "";
    int bn = 0;
    for (int i = n-1; i >= 0; i--) {
        if (isDir(A[i])) {
            if (isParent(cur)) {
                bn++;
            } else if (isPath(cur) && bn == 0) {
                res.append(cur);
                res.append("/");
            } else if (isPath(cur) && bn > 0) {
                bn--;
            }
            cur.clear();
        } else {
            cur.append(1, A[i]);
        }
    }

    reverse(res.begin(), res.end());
    return res.empty() ? "/" : res;
}

int main() {
    cout << simplifyPath2("/home/")             << " /home"    << endl;
    cout << simplifyPath2("/a/./b/../../c/")    << " /c"       << endl;
    cout << simplifyPath2("/a/..")              << " /"        << endl;
    cout << simplifyPath2("/a/../")             << " /"        << endl;
    cout << simplifyPath2("/../../../../../a")  << " /a"       << endl;
    cout << simplifyPath2("/a/./b/./c/./d/")    << " /a/b/c/d" << endl;
    cout << simplifyPath2("/a/../.././../../.") << " /"        << endl;
    cout << simplifyPath2("/a//b//c//////d")    << " /a/b/c/d" << endl;

    return 0;
}
