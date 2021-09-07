struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int x) : val(x), next(nullptr) {}
    Node(int x, Node *next) : val(x), next(next) {}
};

// O(A + B) - time
// O(1)     - space
Node *intersection(Node *first, Node *second) {
    auto fi = first;
    auto si = second;
    int  diff = 0;
    while (fi && si) {
        si = si->next;
        fi = fi->next;
    }

    auto rest = fi ? fi : si;

    while (rest) {
        diff++;
        rest = rest->next;
    }

    auto longer  = fi ? first : second;
    auto smaller = fi ? second : first;

    for (int i = 0; i < diff; i++) {
        longer = longer->next;
    }

    while (smaller && longer) {
        if (smaller == longer) {
            return smaller;
        }
        smaller = smaller->next;
        longer  = longer->next;
    }

    return nullptr;
}

int main() {
    auto f5 = new Node(5);
    auto f4 = new Node(4, f5);
    auto f3 = new Node(3, f4);
    auto f2 = new Node(2, f3);
    auto f1 = new Node(1, f2);
    auto first = new Node(100, f1);

    auto s5 = new Node(50, f3);
    auto s4 = new Node(40, s5);
    auto s3 = new Node(30, s4);
    auto s2 = new Node(20, s3);
    auto s1 = new Node(10, s2);
    auto second = new Node(200, s1);

    auto res = intersection(first, second);

    return 0;
}
