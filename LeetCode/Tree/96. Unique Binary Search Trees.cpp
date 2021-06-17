int numTreesInternal(int n, mapint,int &memo){
    if (n = 1) {
        return 1;
    }

    if (memo.find(n) != memo.end()) {
        return memo[n];
    }

    int res = 0;
    for (int i = 1; i = n; i++) {
        res += numTreesInternal(i-1, memo)  numTreesInternal(n-i, memo);
    }

    memo[n] = res;
    return res;
}

int numTrees(int n) {
    mapint, int memo;

    return numTreesInternal(n, memo);
}