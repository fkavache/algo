struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void addTwoNumbersInternal(ListNode *l1, ListNode *l2, ListNode *res, int r) {
    if (l1 == nullptr && l2 == nullptr && r == 0) {
        return;
    }

    int curr = (l1 == nullptr) ? 0 : l1->val;
    curr    += (l2 == nullptr) ? 0 : l2->val;
    curr    += r;
    res->next = new ListNode(curr % 10);

    addTwoNumbersInternal((l1 == nullptr) ? l1 : l1->next, (l2 == nullptr) ? l2 : l2->next, res->next, curr >= 10);
}

ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
    auto res = new ListNode();

    addTwoNumbersInternal(l1, l2, res, 0);

    return res->next;
}

int main() {
//    auto l13 = new ListNode(3);
//    auto l12 = new ListNode(4, l13);
//    auto l11 = new ListNode(2, l12);
//
//    auto l23 = new ListNode(4);
//    auto l22 = new ListNode(6, l23);
//    auto l21 = new ListNode(5, l22);
//
//    auto res = addTwoNumbers(l11, l21);

// -------------------------------------

//    auto l1 = new ListNode(0);
//    auto l2 = new ListNode(0);
//
//    auto res = addTwoNumbers(l1, l2);

// -------------------------------------

//    auto l14 = new ListNode(9);
//    auto l13 = new ListNode(9, l14);
//    auto l12 = new ListNode(9, l13);
//    auto l11 = new ListNode(9, l12);
//
//    auto l22 = new ListNode(9);
//    auto l21 = new ListNode(9, l22);
//
//    auto res = addTwoNumbers(l11, l21);

// -------------------------------------

    auto l14 = new ListNode(9);
    auto l13 = new ListNode(9, l14);
    auto l12 = new ListNode(9, l13);
    auto l11 = new ListNode(9, l12);

    auto l21 = new ListNode(1);

    auto res = addTwoNumbers(l11, l21);

    while (res != nullptr) {
        cout << res->val;
        res = res->next;
    }

    return 0;
}
