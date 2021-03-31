int hammingWeight(uint32_t n) {
    int ans=0;
    while(n){
        int bit = n&1;
        n=n>>1;
        if(bit)
            ans+=1;
    }
    return ans;
}