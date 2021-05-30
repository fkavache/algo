
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* reorderListInternal(ListNode* A, int len) {
    auto h = A;

    if (len <= 2) {
        if (len == 1) A->next = nullptr;
        if (len == 2) A->next->next = nullptr;
        return A;
    }

    for (int i = 0; i < len-1; i++) h = h->next;

    auto next = A->next;
    A->next = h;
    h->next = reorderListInternal(next, len-2);

    return A;
}

ListNode* reorderList(ListNode* A) {
    auto h = A;

    int count = 0;
    while (h) {
        h = h->next;
        count++;
    }

    return reorderListInternal(A, count);
}

// ---------------------------------------------------------

int getLength(ListNode* A) {
    auto h = A;

    int len = 0;
    while (h) {
        h = h->next;
        len++;
    }
    return len;
}

ListNode* reorderList2(ListNode* A) {
    int len = getLength(A);

    ListNode* curr = A;
    ListNode* prev = nullptr;
    ListNode* next = nullptr;

    int mid = len / 2 + len % 2;
    while (mid > 0) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        mid--;
    }

    ListNode* carry = nullptr;
    if (len % 2 != 0) {
        carry = prev;
        prev = prev->next;
        carry->next = nullptr;
    }

    mid = len/2;
    ListNode* res = carry;
    ListNode* n1  = nullptr;
    ListNode* n2  = nullptr;
    while (mid > 0) {
        n1 = prev->next;
        n2 = curr->next;
        prev->next = curr;
        curr->next = res;
        res = prev;

        prev = n1;
        curr = n2;
        mid--;
    }

    return res;
}

int main() {
    auto hn5 = new ListNode(6);
    auto hn4 = new ListNode(5, hn5);
    auto hn3 = new ListNode(4, hn4);
    auto hn2 = new ListNode(3, hn3);
    auto hn1 = new ListNode(2, hn2);

    auto h = new ListNode(1, hn1);

    auto res = reorderList2(h);

    return 0;
}