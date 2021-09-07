struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

// O(n) - time
// O(n) - space
Node *sumListInternal(Node *first, Node *second, int carry) {
    if (!first && !second) {
        return carry ? new Node(1) : nullptr;
    }

    auto res = new Node();
    int val;

    if (!first) {
        val = second->val + carry;
        res->next = sumListInternal(first, second->next, val / 10);
    } else if (!second) {
        val = first->val + carry;
        res->next = sumListInternal(first->next, second, val / 10);
    } else {
        val = first->val + second->val + carry;
        res->next = sumListInternal(first->next, second->next, val / 10);
    }

    res->val = val % 10;
    return res;
}

Node *sumList(Node *first, Node *second) {
    return sumListInternal(first, second, 0);
}

int main() {
    auto first  = new Node(1, new Node(2, new Node(9, new Node(9, new Node(9, new Node(9))))));
    auto second = new Node(1, new Node(2, new Node(9)));

    auto res = sumList(first, second);

    return 0;
}