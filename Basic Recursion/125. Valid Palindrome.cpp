class Solution {
public:
    string toCompute(string s){
        for(char &c : s){
            c=tolower(c);
        }
        string result;
        for(char c : s){
            if(isalnum(c)){
                result+=c;
            }
        }
        return result;
    }
    bool isPalindrome(string s) {
        string res=toCompute(s);
        int n=res.size();
        int left=0;
        int right=n-1;
        while(left<=right){
            if(res[left]==res[right]){
                left++;
                right--;
            }

            else{
                return false;
            }
        }
        return true;
    }
};
