int leastInterval(vector<char>& tasks, int n) {
    unordered_map<char, int> freq;
    vector<int> tmp;
    priority_queue<int> pq;

    for (char ch: tasks) freq[ch]++;
    for (auto e: freq) pq.push(e.second);

    int cd = n + 1;
    int res = 0;
    while (true) {
        if (cd == 0 || pq.empty()) {
            if (pq.empty()) res += cd;
            for (auto e: tmp) pq.push(e);
            tmp.clear();
            cd = n + 1;
        } else {
            int curr = pq.top();
            pq.pop();

            curr--;
            if (curr != 0) {
                tmp.push_back(curr);
            }
            res++;
            cd--;
        }
        if (pq.empty() && tmp.empty()) break;
    }

    return res;
}

int main() {
    vector<char> tasks1 = {'A','A','A','A','A','A','B','C','D','E','F','G'};
    vector<char> tasks2 = {'A','A','A','B', 'B', 'B'};

    cout << leastInterval(tasks1, 2) << endl;
    cout << leastInterval(tasks2, 2) << endl;
    cout << leastInterval(tasks2, 0) << endl;

    return 0;
}