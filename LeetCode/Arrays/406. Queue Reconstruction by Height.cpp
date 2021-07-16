bool cmp1(vector<int> a, vector<int> b) {
    if (a[0] != b[0]) {
        return a > b;
    }
    return a[1] < b[1];
}

vector<vector<int>> reconstructQueue1(vector<vector<int>>& people) {
    int n = people.size();
    vector<vector<int>> res;

    sort(people.begin(), people.end(), cmp1);

    for (auto e: people) {
        res.insert(res.begin() + e[1], e);
    }

    return res;
}

// -------------------------------------------------------------------
// -------------------------------------------------------------------

bool cmp2(vector<int> a, vector<int> b) {
    if (a[0] != b[0]) {
        return a[0] < b[0];
    }
    return a[1] > b[1];
}

int getIndex(vector<vector<int>>& res, int from) {
    for (int i = 0; i < res.size(); i++) {
        if (res[i].empty()) {
            if (from == 0) return i;
            else from--;
        }
    }
    return -1;
}

vector<vector<int>> reconstructQueue2(vector<vector<int>>& people) {
    int n = people.size();
    vector<vector<int>> res(n);

    sort(people.begin(), people.end(), cmp2);

    for (int i = 0; i < n; i++) {
        res[getIndex(res, people[i][1])] = people[i];
    }

    return res;
}

int main() {
    vector<vector<int>> people = {
        {7,0}, {4,4}, {7,1}, {5,0}, {6,1}, {5,2}
    };

    vector<vector<int>> res1 = reconstructQueue1(people);
    vector<vector<int>> res2 = reconstructQueue2(people);

    for (auto e: res1) cout << "[" << e[0] << ", " << e[1] << "], ";

    cout << endl;

    for (auto e: res2) cout << "[" << e[0] << ", " << e[1] << "], ";

    return 0;
}