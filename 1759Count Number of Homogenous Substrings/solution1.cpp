class Solution {
public:
    void recursiveHomogenousCount(char priv, char cur, int *total_count, int *tmp) {
        if(priv == cur)
            *tmp+=1;
        else
            *tmp = 1;
        *total_count += *tmp;
    }

    int countHomogenous(string s) {
        int total_count=1;
        int tmp = 1;
        int mod = pow(10, 9)+7;
        for(int i=1; i < s.length(); i++) {
            recursiveHomogenousCount(s[i-1], s[i], &total_count, &tmp);
            total_count = total_count % mod;

        }
        return total_count;

    }
};