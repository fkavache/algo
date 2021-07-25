vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    vector<int> res;
    multiset<int> st;

    for (auto e: nums1) st.insert(e);

    for (int i = 0; i < n; i++) {
        auto it = st.upper_bound(nums2[i]);

        if (it != st.end()) {
            res.push_back(*it);
            st.erase(it);
        } else {
            res.push_back(*st.begin());
            st.erase(st.begin());
        }
    }

    return res;
}

int main() {
    vector<int> nums1 = {2, 0, 4, 1, 2};
    vector<int> nums2 = {1, 3, 0, 0, 2};

    vector<int> res = advantageCount(nums1, nums2);

    for (int e: res) {
        cout << e << ", ";
    }

    return 0;
}