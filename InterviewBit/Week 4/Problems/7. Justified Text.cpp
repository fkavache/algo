string fullJustifyGetLast(vector<string> line, int B) {
    int n = line.size();

    string res = line[0];
    for (int i = 1; i < n; i++) {
        res += ' ' + line[i];
    }

    return res + string(B - res.length(), ' ');
}

string fullJustifyGet(vector<string> line, int len, int B) {
    int n    = line.size();
    int rest = B - len;
    int sp   = (n == 1) ? rest : rest / (n - 1);
    int cr   = (n == 1) ? 0 : rest % (n - 1);

    string res = (n == 1) ? line[0] + string(sp, ' ') : line[0];
    for (int i = 1; i < n; i++) {
        res += string(sp + (cr != 0), ' ') + line[i];
        cr = (cr == 0) ? 0 : cr - 1;
    }
    return res;
}

vector<string> fullJustify(vector<string> &A, int B) {
    int n = A.size();
    vector<string> res;
    vector<string> line;

    if (n == 0) return res;

    int clen = 0;
    for (int i = 0; i < n; i++) {
        if (A[i].length() + clen + line.size() <= B) {
            line.push_back(A[i]);
            clen += A[i].length();
        } else {
            res.push_back(fullJustifyGet(line, clen, B));
            line.clear();
            clen = 0;
            i--;
        }
    }

    res.push_back(fullJustifyGetLast(line, B));

    return res;
}

int main() {
//    vector<string> A = {"What", "must", "be", "shall", "be."};
    vector<string> A = {"This", "is", "an", "example", "of", "text", "justification."};
    vector<string> res = fullJustify(A, 144);

    for (string &line: res) {
        cout << line << endl;
    }
    
    return 0;
}