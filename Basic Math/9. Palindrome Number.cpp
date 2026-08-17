class Solution {
public:
    bool isPalindrome(int x) {
        long long revN=0;
        int copy=x;
        if(copy<0) return false;
        while(copy!=0){
            int lastDigit=copy%10;
            copy/=10;
            revN=(revN*10)+lastDigit;
        }
        if (revN==x){
            return true;
        }
        else{
            return false;
        }
    }
};
