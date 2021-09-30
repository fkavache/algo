// o(2^n) - time
// o(n)   - space
void hanoi(int n, stack<int> &orig, stack<int> &tmp, stack<int> &dest) {
    if (n <= 0) return;

    hanoi(n - 1, orig, dest, tmp);

    dest.push(orig.top());
    orig.pop();

    hanoi(n - 1, tmp, orig, dest);
}

int main() {
    int n = 10;
    stack<int> orig, tmp, dest;

    for (int i = n; i > 0; i--) {
        orig.push(i);
    }

    hanoi(n, orig, tmp, dest);

    return 0;
}
