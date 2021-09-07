struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

int getLen(Node *head) {
    int  len = 0;
    auto i   = head;
    while (i) {
        i = i->next;
        len++;
    }

    return len;
}

// O(n) - time (2n)
// O(1) - space
bool isPalindrome1(Node *head) {
    int len = getLen(head);

    if (len == 1) return true;

    Node *rev = nullptr;
    Node *cur = head;
    for (int i = 0; i < len / 2; i++) {
        auto tmp = cur->next;
        cur->next = rev;
        rev = cur;
        cur = tmp;
    }

    if (len & 1) cur = cur->next;

    for (int i = 0; i < len / 2; i++) {
        if (rev->val != cur->val) {
            return false;
        }
        rev = rev->next;
        cur = cur->next;
    }

    return true;
}

// O(n) - time (n)
// O(n) - space
bool isPalindrome2(Node *head) {
    auto slow = head;
    auto fast = head;

    stack<int> s;

    while (fast && fast->next) {
        s.push(slow->val);
        slow = slow->next;
        fast = fast->next->next;
    }

    if (fast) slow = slow->next;

    while (slow) {
        int val = s.top();
        s.pop();

        if (val != slow->val) {
            return false;
        }

        slow = slow->next;
    }

    return true;
}

int main() {
    auto head1 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(3, new Node(2, new Node(1)))))));
    auto head2 = new Node(1, new Node(2, new Node(3, new Node(4, new Node(8, new Node(2, new Node(1)))))));
    auto head3 = new Node(1, new Node(2, new Node(3, new Node(3, new Node(2, new Node(1))))));
    auto head4 = new Node(1, new Node(2));
    auto head5 = new Node(1, new Node(1));

    cout << isPalindrome2(head1) << isPalindrome1(head1) << endl;
    cout << isPalindrome2(head2) << isPalindrome1(head2) << endl;
    cout << isPalindrome2(head3) << isPalindrome1(head3) << endl;
    cout << isPalindrome2(head4) << isPalindrome1(head4) << endl;
    cout << isPalindrome2(head5) << isPalindrome1(head5) << endl;

    return 0;
}
