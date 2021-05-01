
#define ll long long

bool inRange(int val, ll l, ll r) {
    return val > l && val < r;
}

bool isValidBSTInternalFast(TreeNode* root, ll l, ll r) {
    if (root && !root->left && !root->right) {
        return true;
    }

    if (root) {
        if (root->left && (root->left->val >= root->val
        || !inRange(root->left->val, l, r))) {
            return  false;
        }
        if (root->right && (root->right->val <= root->val
        || !inRange(root->right->val, l, r))) {
            return false;
        }
    } else {
        return false;
    }

    bool left  = root->left  ? isValidBSTInternalFast(root->left, l, root->val)  : true;
    bool right = root->right ? isValidBSTInternalFast(root->right, root->val, r) : true;

    return left && right;
}

bool isValidBSTInternal(TreeNode* root, ll l, ll r) {
    if (!root) {
        return true;
    }

    if (root->val <= l || root->val >= r) {
        return false;
    }

    bool left  = root->left  ? isValidBSTInternal(root->left, l, root->val)  : true;
    bool right = root->right ? isValidBSTInternal(root->right, root->val, r) : true;

    return left && right;
}

bool isValidBST(TreeNode* root) {
    return isValidBSTInternal(root, LLONG_MIN, LLONG_MAX);
}

int main() {
    auto r = new TreeNode(INT_MAX);
    auto root = new TreeNode(INT_MIN, nullptr, r);

    cout << isValidBST(root) << endl;

    return 0;
}
