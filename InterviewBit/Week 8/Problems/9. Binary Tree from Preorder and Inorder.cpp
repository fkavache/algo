struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode* buildTreeInternal(vector<int> &A, map<int, int> &map, int &r, int s, int e) {
    if (s > e) {
        return nullptr;
    }

    TreeNode* root = new TreeNode(A[r]);

    int idx = map[A[r++]];

    root->left  = buildTreeInternal(A, map, r, s, idx - 1);
    root->right = buildTreeInternal(A, map, r, idx + 1, e);

    return root;
}

TreeNode* buildTree(vector<int> &A, vector<int> &B) {
    int n = B.size();
    int r = 0;
    map<int, int> map;

    for (int i = 0; i < n; i++) {
        map[B[i]] = i;
    }

    return buildTreeInternal(A, map, r, 0, n - 1);
}

int main() {
    vector<int> A = {1, 2, 3, 4, 5, 6, 7};
    vector<int> B = {3, 2, 4, 1, 6, 5, 7};

    auto res = buildTree(A, B);

    return 0;
