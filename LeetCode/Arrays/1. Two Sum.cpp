vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map(1);
    vector<int> res(2);

    for (int i = 0; i < nums.size(); i++) {
        if (map.find(nums[i]) != map.end()) {
            res[0] = map[nums[i]];
            res[1] = i;
            break;
        }
        map[target - nums[i]] = i;
    }

    return res;
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
//    vector<int> nums = {3, 2, 4};
//    vector<int> nums = {2, 7, 11, 15, 3, 4};
//    vector<int> nums = {3, 3};

    vector<int> res = twoSum(nums, 9);
    cout << res[0] << ", " << res[1] << endl;
    return 0;
}
