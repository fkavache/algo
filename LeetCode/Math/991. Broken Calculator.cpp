int brokenCalc(int x, int y) {
    if (y <= x) return x - y;

    if (y % 2 == 0) {
        return brokenCalc(x, y / 2) + 1;
    } else {
        return brokenCalc(x, y + 1) + 1;
    }
}

int main() {
    cout << brokenCalc(7, 33) << endl;
    
    return 0;
}