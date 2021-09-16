struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int val): val(val), left(nullptr), right(nullptr){}
    TreeNode(int val, TreeNode *left, TreeNode *right): val(val), left(left), right(right){}
};

TreeNode *constructInternal(vector<int> &A, int s, int e) {
    if (s > e) {
        return nullptr;
    }

    int mid = (s + e) / 2;
    auto root = new TreeNode(A[mid]);

    root->left  = constructInternal(A, s, mid - 1);
    root->right = constructInternal(A, mid + 1, e);

    return root;
}

// O(n)      - time
// O(log(n)) - space
TreeNode *construct(vector<int> &A) {
    return constructInternal(A, 0, A.size() - 1);
}

int main() {
    vector<int> A = {0, 1, 2, 3, 4, 5, 6, 7, 8};

    auto res = construct(A);

    return 0;
}