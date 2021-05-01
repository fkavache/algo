struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void mergeInternal(ListNode *res, ListNode *l1, ListNode *l2) {
    if (!l1 && !l2) return;
    else {
        if (l1 && (!l2 || l1->val < l2->val)) {
            res->next =  new ListNode(l1->val);
            mergeInternal(res->next, l1->next, l2);
        } else {
            res->next =  new ListNode(l2->val);
            mergeInternal(res->next, l1, l2->next);
        }
    }
}

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    auto res = new ListNode();
    mergeInternal(res, l1, l2);
    return res->next;
}

int main() {
    auto l14 = new ListNode(8);
    auto l13 = new ListNode(6, l14);
    auto l12 = new ListNode(4, l13);
    auto l11 = new ListNode(2, l12);

    auto l24 = new ListNode(7);
    auto l23 = new ListNode(5, l24);
    auto l22 = new ListNode(3, l23);
    auto l21 = new ListNode(1, l22);

    auto res = mergeTwoLists(l11, l21);

    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }
    return 0;
}
