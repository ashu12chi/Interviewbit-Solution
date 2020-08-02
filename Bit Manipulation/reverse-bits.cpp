unsigned int Solution::reverse(unsigned int n) {
    uint32_t result= 0;
    for(int i=0; i<32; i++)
        result = (result<<1) + (n>>i &1);
    return result;
}
