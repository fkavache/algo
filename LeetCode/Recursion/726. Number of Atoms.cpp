string countOfAtoms(string formula) {
    int n = formula.length();

    unordered_map<string, int> freq(1);
    priority_queue<string, vector<string>, greater<>> pq;
    stack<int> stack;

    stack.push(1);

    int    num = -1;
    string curr;
    for (int i = n-1; i >= 0; i--) {
        char ch = formula[i];
        if (ch == ')' && num != -1) {
            stack.push(num * stack.top());
            num = -1;
        } else if (ch == '(' && stack.size() > 1) {
            stack.pop();
        } else if (isdigit(ch)) {
            num = (num == -1) ? (ch - '0') : (ch - '0') * 10 + num;
        } else if (islower(ch)) {
            curr.insert(0, 1, ch);
        } else if (isupper(ch)) {
            curr.insert(0, 1, ch);
            freq[curr] += (num == -1) ? stack.top() : num * stack.top();
            num = -1;
            curr = "";
        }
    }

    for (auto const &pair: freq) {
        string each;
        each.append(pair.first);
        if (pair.second > 1) {
            each.append(to_string(pair.second));
        }
        pq.push(each);
    }

    string res;
    while (!pq.empty()) {
        res.append(pq.top());
        pq.pop();
    }

    return res;
}

int main() {
    cout << countOfAtoms("") << endl;
    cout << countOfAtoms("H20") << endl;
    cout << countOfAtoms("Mg(OH)2") << endl;
    cout << countOfAtoms("Mg(H2O)N") << endl;
    cout << countOfAtoms("K4(ON(SO3)2)2") << endl;
    cout << countOfAtoms("(FnnFnn3O33Abb9HaP2)") << endl;
    cout << countOfAtoms("Fnn(Fnn3O33Abb9(HaP2)3)4") << endl;
    cout << countOfAtoms("(Fnn(Fnn3O33Abb9(HaP2)3)4)10") << endl;
    return 0;
}