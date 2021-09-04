struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

// O(n) - time
// O(1) - space
int kthToLast(Node *head, int k) {
    auto i = head;
    auto j = head;
    for (int m = 0; m < k; m++) {
        j = j->next;
    }

    while (j) {
        i = i->next;
        j = j->next;
    }

    return i->val;
}

int main() {
    auto head = new Node(10, new Node(20, new Node(30, new Node(40, new Node(50, new Node(60, new Node(70)))))));

    cout << kthToLast(head, 4) << endl;

    return 0;
}