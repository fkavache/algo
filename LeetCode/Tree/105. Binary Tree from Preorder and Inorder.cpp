
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeInternal(map<int, int> &map, vector<int>& pre, int &r, int s, int e) {
    if (s > e) return nullptr;

    auto node = new TreeNode(pre[r]);

    int idx = map[pre[r++]];

    node->left  = buildTreeInternal(map, pre, r, s, idx - 1);
    node->right = buildTreeInternal(map, pre, r, idx + 1, e);

    return node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    map<int, int> map;
    int r = 0;

    for (int i = 0; i < inorder.size(); i++) {
        map[inorder[i]] = i;
    }

    return buildTreeInternal(map, preorder, r, 0, inorder.size() - 1);
}

int main() {
    vector<int> pre = {1, 2, 4, 5, 8, 9, 3, 6, 10, 7};
    vector<int> in  = {4, 2, 5, 8, 9, 1, 6, 10, 3, 7};

//    vector<int> pre = {2, 4, 5, 8, 9};
//    vector<int> in  = {4, 2, 5, 8, 9};

//    vector<int> pre = {1, 2, 4, 8, 9, 5, 10, 11, 3, 6, 12, 15, 7, 14, 15};
//    vector<int> in  = {8, 4, 9, 2, 10, 5, 11, 1, 12, 6, 15, 3, 14, 7, 15};

    auto res = buildTree(pre, in);

    return 0;
}
