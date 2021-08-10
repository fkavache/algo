class Solution {
private:
    unordered_map<int, vector<int>> freq;
public:
    Solution(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            freq[nums[i]].push_back(i);
        }
    }

    int pick(int target) {
        int randIdx = rand() % freq[target].size();

        return freq[target][randIdx];
    }
};

int main() {
    return 0;
}