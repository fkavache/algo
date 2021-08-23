struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

UndirectedGraphNode *cloneGraphInternal(UndirectedGraphNode *node, unordered_map<int, UndirectedGraphNode *> &created) {

    auto nn = new UndirectedGraphNode(node->label);

    created[nn->label] = nn;

    for (auto child: node->neighbors) {
        if (created.find(child->label) == created.end()) {
            nn->neighbors.push_back(cloneGraphInternal(child, created));
        } else {
            nn->neighbors.push_back(created[child->label]);
        }
    }

    return nn;
}

UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
    unordered_map<int, UndirectedGraphNode *> created;

    return cloneGraphInternal(node, created);
}

int main() {
    return 0;
}
