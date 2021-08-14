int meetingRooms(vector<vector<int>> &A) {
    int n = A.size();

    vector<pair<int, int>> comb;
    for (auto i: A) {
        comb.push_back(make_pair(i[0], 1));
        comb.push_back(make_pair(i[1], 0));
    }

    sort(comb.begin(), comb.end());

    int c   = 0;
    int res = c;
    for (int i = 0; i < n * 2; i++) {
        c = comb[i].second == 1 ? c + 1 : c - 1;
        res = max(res, c);
    }

    return res;
}

int main() {
    vector<vector<int>> A = {
        {7,  10},
        {4,  19},
        {19, 26},
        {14, 16},
        {13, 18},
        {16, 21},
    };

    cout << meetingRooms(A) << endl;

    return 0;
}