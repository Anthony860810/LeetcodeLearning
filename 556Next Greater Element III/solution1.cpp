class Solution {
public:
    void Swap(char &a, char &b){
        char temp=a;
        a=b;
        b=temp;
    }
    int nextGreaterElement(int n) {
        string s = to_string(n);
        int len= s.size()-1;
        int pivot = len;
        // find ascending
        for(; pivot>0 ; pivot--){
            if(s[pivot]>s[pivot-1]){
                break;
            }
        }
        if(pivot<=0){
            return -1;
        }
        //find close number swap
        int close;
        int min=10;
        for(int j=pivot ; j<=len ; j++){
            if(s[j]-s[pivot-1]>0 && s[j]-s[pivot]<min){
                close = j;
                min = s[j]-s[pivot];
            }
        }
        Swap(s[pivot-1], s[close]);
        sort(s.begin()+pivot, s.end(), less<char>());
        long long res = stoll(s);
        return res > INT_MAX ? -1 : res;
    }
};