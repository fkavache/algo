bool indexValid(const string &str, const string &reg, int sIdx, int eIdx) {
    return str[sIdx] == reg[eIdx] || reg[eIdx] == '.';
}

bool isMatchInternal(const string &str, const string &reg, int sIdx, int eIdx, vector<vector<int>> &dp) {
    if (sIdx == 0 && eIdx == 0) return true;
    if (sIdx < 0 || eIdx < 0)   return false;

    if (dp[sIdx][eIdx] != INT_MAX) {
        return (bool) dp[sIdx][eIdx];
    }

    if (indexValid(str, reg, sIdx - 1, eIdx - 1)) {
        return isMatchInternal(str, reg, sIdx - 1, eIdx - 1, dp);
    } else if (reg[eIdx - 1] == '*') {
        bool matches = (indexValid(str, reg, sIdx - 1, eIdx - 2))
                       && isMatchInternal(str, reg, sIdx - 1, eIdx, dp);

        if (!matches) {
            matches = isMatchInternal(str, reg, sIdx, eIdx - 2, dp);
        }

        if(matches) {
            dp[sIdx][eIdx] = matches;
            return matches;
        }
    }

    dp[sIdx][eIdx] = 0;
    return false;
}

bool isMatch(string str, string reg) {
    int sIdx = str.length();
    int eIdx = reg.length();

    vector<vector<int>> dp(sIdx + 1, vector<int>(eIdx + 1, INT_MAX));

    return isMatchInternal(str, reg, str.length(), reg.length(), dp);
}

int main() {
    cout << isMatch("baaaaaabaaaabaaaaababababbaab", "..a*aa*a.aba* a*bab*") << endl;

    return 0;
}