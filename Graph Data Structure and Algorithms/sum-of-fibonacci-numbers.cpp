int Solution::fibsum(int A) {
    vector<int> fib;
    fib.push_back(1);
    fib.push_back(2);
    int a = 1;
    int b = 2;
    while(true)
    {
        int c = a+b;
        if(c>A)
            break;
        fib.push_back(c);
        a = b;
        b = c;
    }
    int soln=0;
    int index = fib.size()-1;
    while(A!=0){
        if (fib[index] <= A) {
            soln++;
            A = A-fib[index];
        }
        index--;
    }
    return soln;
}
