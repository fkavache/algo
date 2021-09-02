// O(n) - time
// O(1) - space
bool isRotation(string str1, string str2) {
    if (str1.length() != str2.length())
        return false;

    str2 += str2;

    return str2.find(str1) != -1;
}

int main() {
    cout << isRotation("waterbottle", "ttlewaterbo")  << endl;
    cout << isRotation("waterbottle", "bottlewater")  << endl;
    cout << isRotation("waterbottle", "ttlewaterboo") << endl;

    return 0;
}
