
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeInternal(map<int, int> &map, vector<int>& post, int &r, int s, int e) {
    if (s > e) return nullptr;

    auto node = new TreeNode(post[r]);

    int idx = map[post[r--]];

    node->right = buildTreeInternal(map, post, r, idx + 1, e);
    node->left  = buildTreeInternal(map, post, r, s, idx - 1);

    return node;
}

TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    map<int, int> map;
    int n = inorder.size();
    int r = n - 1;

    for (int i = 0; i < n; i++) {
        map[inorder[i]] = i;
    }

    return buildTreeInternal(map, postorder, r, 0, n - 1);
}

int main() {
    vector<int> post = {9, 15, 7, 20, 3};
    vector<int> in   = {9, 3, 15, 20, 7};

    auto res = buildTree(in, post);

    return 0;
}
