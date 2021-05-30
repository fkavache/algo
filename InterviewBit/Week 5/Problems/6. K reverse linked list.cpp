struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reverseList(ListNode* A, int B) {
    auto h = A;
    while (h) {
        for (int i = 0; i < B / 2 + B % 2; i++) {
            auto c = h;
            for (int j = i; j < B - i - 1; j++) c = c->next;
            swap(h->val, c->val);
            h = h->next;
        }
        for (int i = 0; i < B / 2 && h; i++) h = h->next;
    }

    return A;
}

ListNode* reverseList(ListNode* A, int B) {
    ListNode* curr = A;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    int count = 0;
    while (count < B && curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if (curr) A->next = reverseList(curr, B);

    return prev;
}

int main() {
    auto hn5 = new ListNode(6);
    auto hn4 = new ListNode(5, hn5);
    auto hn3 = new ListNode(4, hn4);
    auto hn2 = new ListNode(3, hn3);
    auto hn1 = new ListNode(2, hn2);

    auto h = new ListNode(1, hn1);

    auto res = reverseList(h, 3);

    return 0;
}