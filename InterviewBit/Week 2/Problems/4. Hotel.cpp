bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    vector<pair<int, int>> result;
    int n = arrive.size();

    for (int i = 0; i < n; i++) {
        result.push_back(make_pair(arrive[i], 1));
        result.push_back(make_pair(depart[i], 0));
    }

    sort(result.begin(), result.end());

    int c = 0;
    for (int i = 0; i < result.size(); i++) {
        if (result[i].second == 1) {
            c++;
            if (c > K) return false;
        } else {
            c--;
        }
    }

    return true;
}

int main() {
    vector<int> arrive = {1, 3, 5};
    vector<int> depart = {2, 6, 8};

    cout << hotel(arrive, depart, 1) << endl;

    return 0;
}