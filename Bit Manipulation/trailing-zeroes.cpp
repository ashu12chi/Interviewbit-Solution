int Solution::solve(int A) {
    return log2(A & (-A));
}
