int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0;
	int ans = INT_MIN;
	for (int i = 0; i < size(A); i++) {
	    sum += A[i];
	    if (sum < A[i]) {
	        sum = A[i];
	    }
		ans = max(ans, sum);
	}

	return ans;
}

int main() {
    vector<int> A = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    
    cout << maxSubArray(A) << endl;
    
    return 0;
}