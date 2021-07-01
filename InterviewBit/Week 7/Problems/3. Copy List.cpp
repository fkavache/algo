struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

RandomListNode* copyInternal(RandomListNode* A, unordered_map<RandomListNode*, RandomListNode*> &map) {
    if (!A) return A;

    auto nn = new RandomListNode(A->label);
    nn->next = copyInternal(A->next, map);

    map[A] = nn;

    return nn;
}

RandomListNode* copyRandomList(RandomListNode* A) {
    unordered_map<RandomListNode*, RandomListNode*> map;

    auto nn = copyInternal(A, map);

    auto tmp = A;
    while (tmp){
        map[tmp]->random = map[tmp->random];
        tmp = tmp->next;
    }

    return nn;
}

int main() {
    return 0;
}
