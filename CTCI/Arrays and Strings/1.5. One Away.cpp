// O(n) - time
// O(1) - space
bool oneAwayInternal(string str1, string str2) {
    int n1 = str1.length();
    int n2 = str2.length();

    bool sameLen = (n1 == n2);
    bool mismatch = false;
    int i = 0, j = 0;
    while (i < str1.length()) {
        if (str1[i] == str2[j]) {
            i++; j++;
        } else {
            if (mismatch) return false;
            mismatch = true;
            if (sameLen) i++;
            j++;
        }
    }

    return true;
}

bool oneAway(string str1, string str2) {
    return str1.length() < str2.length()
        ? oneAwayInternal(str1, str2)
        : oneAwayInternal(str2, str1);
}

int main() {
    cout << oneAway("pale",  "pal")  << endl;
    cout << oneAway("pale",  "ple")  << endl;
    cout << oneAway("pales", "pale") << endl;
    cout << oneAway("paale", "pale") << endl;
    cout << oneAway("pale",  "bale") << endl;
    cout << oneAway("pale",  "pake") << endl;

    cout << oneAway("pale",  "pakl") << endl;
    cout << oneAway("pale",  "bake") << endl;
    cout << oneAway("pale",  "bak")  << endl;
    cout << oneAway("pale",  "ba")   << endl;

    return 0;
}
