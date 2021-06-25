struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void pathSumInternal(TreeNode* root, map<int, int> &map, int t, int p, int &res) {
    if (!root) return;

    p += root->val;
    if (map.find(p - t) != map.end()) {
        res += map[p - t];
    }

    map[p]++;
    pathSumInternal(root->left,  map, t, p, res);
    pathSumInternal(root->right, map, t, p, res);
    map[p]--;
}

int pathSum(TreeNode* root, int targetSum) {
    map<int, int> map;
    int res = 0;
    map[0] = 1;

    pathSumInternal(root, map, targetSum, 0, res);

    return res;
}

int main() {
    return 0;
}
