bool isPalindrome(int x){
    if(x<0)
        return false;
    unsigned long reverse=0;
    int temp=x;
    while(temp){
       reverse*=10;
       reverse+=(temp%10);
        temp/=10;
    }
    return reverse==x;
}