string overlap(string s, string l) {
    int slen = s.length();
    int llen = l.length();

    string res = s + l;
    for (int i = 1; i < min(slen, llen); i++) {
        if (s.substr(slen - i, i) == l.substr(0, i)) {
            res = s + l.substr(i);
        }
    }

    return res;
}

string mergeString(string a, string b, int &olap) {
    string s = a.length() > b.length() ? b : a;
    string l = a.length() > b.length() ? a : b;

    if (l.find(s) != -1) {
        olap = a.length();
        return a;
    }

    string olap1 = overlap(s, l);
    string olap2 = overlap(l, s);

    string res = olap1.length() < olap2.length() ? olap1 : olap2;

    olap = s.length() + l.length() - res.length();

    return res;
}

int scs(vector<string> &A) {
    while (A.size() > 1) {
        int maxOlap = INT_MIN;
        int l = 0, r = 0;
        string merge;

        for (int i = 0; i < A.size(); i++) {
            for (int j = i + 1; j < A.size(); j++) {
                int olap = 0;

                string curr = mergeString(A[i], A[j], olap);
                if (olap >= maxOlap) {
                    maxOlap = olap;
                    merge = curr;
                    l = i; r = j;
                }
            }
        }

        swap(A[l], merge);
        swap(A[r], A[A.size() - 1]);
        A.pop_back();
    }

    return A[0].length();
}

int main() {
    vector<string> A1 = {"abcde", "cdef", "fghi", "de"};
    vector<string> A2 = {"fevlutui", "ilxfntf", "whiade", "idehwakceipb", "lkgvxeb"};

    cout << scs(A1) << endl;
    cout << scs(A2) << endl;

    return 0;
}

