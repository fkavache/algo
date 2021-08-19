struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

TreeNode* sortedToBST(vector<int> &Av, int s, int e) {
    if (s > e) {
        return nullptr;
    }

    int mid = (s + e) / 2;
    TreeNode *node = new TreeNode(Av[mid]);

    node->left  = sortedToBST(Av, s, mid - 1);
    node->right = sortedToBST(Av, mid + 1, e);

    return node;
}

TreeNode* sortedListToBST(ListNode* A) {
    vector<int> Av;

    auto curr = A;
    while (curr) {
        Av.push_back(curr->val);
        curr = curr->next;
    }

    return sortedToBST(Av, 0, Av.size() - 1);
}

int main() {
    auto head = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5, new ListNode(6, new ListNode(7)))))));

    auto res = sortedListToBST(head);

    return 0;
}