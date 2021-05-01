bool cmpFnc(int a, int b){
    string f = to_string(a) + to_string(b);
    string s = to_string(b) + to_string(a);
    return f.compare(s) >= 1;
}

string largestSum(const vector<int> &A) {
    vector<int> B = A;

    string result;
    sort(B.begin(), B.end(), cmpFnc);

    for (int i : B) {
        result += to_string(i);
    }

    return result[0] == '0' ? "0" : result;
}

int main() {
    vector<int> A = {3, 30, 34, 5, 9};

    cout << largestSum(A) << endl;

    return 0;
}
