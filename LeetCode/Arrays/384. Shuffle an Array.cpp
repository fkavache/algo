class Solution {
private:
    vector<int> A;
public:
    Solution(vector<int>& nums) {
        A = nums;
    }

    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return A;
    }

    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res = A;

        for (int i = 0; i < A.size(); i++) {
            int j = rand() % res.size();
            swap(res[i], res[j]);
        }

        return res;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6};

    Solution* obj = new Solution(nums);
    vector<int> param_1 = obj->reset();
    vector<int> param_2 = obj->shuffle();

    return 0;
}