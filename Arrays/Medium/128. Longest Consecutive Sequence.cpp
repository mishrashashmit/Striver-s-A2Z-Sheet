class Solution1 {
public:
    //TC : O(N^2) ; SC : O(1)
    bool linearSearch(vector<int>&arr, int num){
        int n=arr.size();{
            for(int i=0; i<n;i++){
                if(arr[i]==num){
                    return true;
                }
            }
            return false;
        }
    }
    int longestConsecutive(vector<int>& nums) {
        int longest=1;
        int n= nums.size();
        for(int i=0; i<n ; i++){
            int firstInSequence=nums[i];
            int seqCntr=1;
            while(linearSearch(nums, firstInSequence + 1)){
                firstInSequence= firstInSequence+1;
                seqCntr++;
            }
            longest=max(longest, seqCntr);
        }
        return longest;
    }
};


class Solution2 {
public:
    //TC : O(N log N) , SC = O(1)
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        int longest=1;
        int seqCntr=0;
        int lastSmaller=INT_MIN;

        for(int i=0; i<n; i++){
            //means this is the next element in sequence
            if(nums[i]-1==lastSmaller){ 
                seqCntr++;
                lastSmaller=nums[i];
                longest++;
            }
            //if the present element is same as the previous element
            else if(nums[i]==lastSmaller){

            }
            //if the present element is entirely a new element / does not follow the sequence
            else if(nums[i]!=lastSmaller){
                seqCntr=1;
                lastSmaller=nums[i];
            }
            longest=max(longest, seqCntr);
        }
        return longest;
    }
};


class Solution {
public:
    //TC : O(N); SC : O(N)
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        int seqCntr=0;
        int longest=1;
        unordered_set<int>st;

        if(n==0) return 0;

        for(int i=0; i<n ; i++){
            st.insert(nums[i]);
        }

        for(auto it : st){
            if(st.find(it -1)==st.end()){
                seqCntr=1;
                int firstInSequence=it;
                while(st.find(firstInSequence+1)!=st.end()){
                    firstInSequence=firstInSequence+1;
                    seqCntr++;
                }
                longest=max(longest, seqCntr);
            }
        }
        return longest;
    }
};
