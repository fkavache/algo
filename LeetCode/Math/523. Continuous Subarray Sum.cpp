bool isValidSum(unordered_map<int, int> &map, int sum, int i) {
    return map.find(sum) != map.end() && (i - map[sum] >= 2);
}

void sumUpdate(unordered_map<int, int> &map, int sum, int i) {
    if (map.find(sum) == map.end()) {
        map[sum] = i;
    }
}

bool checkSubarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> map;

    int sum = 0;
    map[sum] = -1;
    for (int i = 0; i < nums.size(); i++) {
        sum = (sum + nums[i]) % k;
        if (isValidSum(map, sum, i)) {
            return true;
        }
        sumUpdate(map, sum, i);
    }

    return false;
}

int main() {
    vector<int> A1 = {23, 2, 4, 6, 7};
    vector<int> A2 = {23, 2, 6, 4, 7};
    vector<int> A3 = {23, 2, 6, 4, 7};
    vector<int> A4 = {5, 0, 0, 0};
    vector<int> A5 = {2, 4, 3};
    vector<int> A6 = {1, 0};

    cout << checkSubarraySum(A1, 6)  << endl;
    cout << checkSubarraySum(A2, 6)  << endl;
    cout << checkSubarraySum(A3, 13) << endl;
    cout << checkSubarraySum(A4, 3)  << endl;
    cout << checkSubarraySum(A5, 6)  << endl;
    cout << checkSubarraySum(A6, 2)  << endl;

    return 0;
}
