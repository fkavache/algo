int maximumSwap(int num) {
    string str = to_string(num);
    int    len = str.length();

    int idx = -1;
    for (int i = 0; i < len - 1; i++) {
        if (idx != -1 && str[i] <= str[i + 1]) {
            if (str[i + 1] >= str[idx]) {
                idx = i + 1;
            }
        } else if (str[i] < str[i + 1]) {
            idx = i + 1;
        }
    }

    for (int i = 0; i <= idx; i++) {
        if (str[i] < str[idx]) {
            swap(str[i], str[idx]);
            break;
        }
    }

    return stoi(str);
}

int main() {
    cout << maximumSwap(2736) << endl;
    cout << maximumSwap(9973) << endl;
    cout << maximumSwap(0) << endl;
    cout << maximumSwap(65432811) << endl;
    cout << maximumSwap(9875216) << endl;
    cout << maximumSwap(4567111) << endl;
    cout << maximumSwap(99901) << endl;
    cout << maximumSwap(1993) << endl;

    return 0;
}