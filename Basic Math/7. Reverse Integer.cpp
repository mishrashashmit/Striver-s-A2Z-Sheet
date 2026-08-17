class Solution {
public:
    int reverse(int x) {
        long long revN=0;
        while(x!=0){
            int lastDigit=x%10;
            x=x/10;
            revN=(revN*10)+lastDigit;
        }
        if(revN<INT_MIN || revN>INT_MAX){
            return 0;
        }
        return (int)revN;
    }
};
