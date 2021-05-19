
#define ll long long

bool isplus(char c){
    return c == '+';
}

bool isminus(char c){
    return c == '-';
}

bool issign(char c){
    return isplus(c) || isminus(c);
}

int atoi2(const string A) {
    int n = A.length();

    bool flag = false;
    int  sign = 1;
    ll   res  = 0;
    for (int i = 0; i < n; i++) {
        if (!flag && isspace(A[i])) continue;
        if (issign(A[i])) {
            flag = true;
            if (isminus(A[i])) sign = -1;
        } else if (isdigit(A[i])) {
            flag = true;
            res = res * 10 + sign * (A[i] - '0');

            if (res > INT_MAX) res = INT_MAX;
            if (res < INT_MIN) res = INT_MIN;
        } else {
            break;
        }
    }

    return (int) res;
}

int main() {
    cout << atoi("+0 2114349630") << " " << atoi2("+0 2114349630") << endl;
    cout << atoi("    - 9d134")   << " " << atoi2("    - 9d134")   << endl;
    cout << atoi("    -9d223")    << " " << atoi2("    -9d223")    << endl;
    cout << atoi(" 245kjfh45")    << " " << atoi2(" 245kjfh45")    << endl;
    cout << atoi(" 9313 994")     << " " << atoi2(" 9313 994")     << endl;
    cout << atoi(" 9313994")      << " " << atoi2(" 9313994")      << endl;
    cout << atoi("+ 55567")       << " " << atoi2("+ 55567")       << endl;
    cout << atoi("- 55567")       << " " << atoi2("- 55567")       << endl;
    cout << atoi("   134")        << " " << atoi2("   134")        << endl;
    cout << atoi("aaa134")        << " " << atoi2("aaa134")        << endl;
    cout << atoi("    +7")        << " " << atoi2("    +7")        << endl;
    cout << atoi("9d134")         << " " << atoi2("9d134")         << endl;
    cout << atoi(" 0005")         << " " << atoi2(" 0005")         << endl;
    cout << atoi("-343f")         << " " << atoi2("-343f")         << endl;

    cout << atoi2("5121478262 ")        << endl;
    cout << atoi2("-54332872018247709") << endl;

    return 0;
}