class Tree {
private:
    struct TreeNode {
        int val;
        int size;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int val) : val(val), left(nullptr), right(nullptr), size(1) {}
        TreeNode(int val, TreeNode *left, TreeNode *right) : val(val), left(left), right(right), size(1) {}
    };

    TreeNode *root;

    TreeNode *insertInternal(TreeNode *root, int val) {
        if (!root) {
            return new TreeNode(val);
        }

        root->size++;

        if (val < root->val) {
            root->left = insertInternal(root->left, val);
        } else  {
            root->right = insertInternal(root->right, val);
        }

        return root;
    }

    TreeNode *findInternal(TreeNode *root, int val) {
        if (!root) {
            return nullptr;
        }

        if (val < root->val) {
            return insertInternal(root->left, val);
        } else if (val > root->val){
            return insertInternal(root->right, val);
        }

        return root;
    }

    TreeNode *getRandomNodeInternal(TreeNode *root) {
        int size  = root->size;
        int lsize = root->left ? root->left->size : 0;

        int way = rand() % root->size;

        if (way < lsize) {
            return getRandomNodeInternal(root->left);
        } else if (way > lsize) {
            return getRandomNodeInternal(root->right);
        }

        return root;
    }

public:
    Tree() {
        root = nullptr;
    }

    void insert(int val) {
        root = insertInternal(root, val);
    }

    TreeNode *find(int val) {
        return findInternal(root, val);
    }

    TreeNode *getRandomNode() {
        return getRandomNodeInternal(root);
    }
};

int main() {
    unordered_map<int, int> freq;
    Tree btree;
    int N = 1000;

    for (int i = 0; i < N; i++) {
        btree.insert(rand() % N);
    }

    for (int i = 0; i < N; i++) {
        freq[btree.getRandomNode()->val]++;
    }

    return 0;
}