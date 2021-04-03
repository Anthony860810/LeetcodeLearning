bool isPalindrome(int x){
    if(x<0)
        return false;
    unsigned long reverse=0;
    int tmp=x;
    while(tmp){
       reverse*=10;
       reverse+=(tmp%10);
        tmp/=10;
    }
    return reverse==x;
}