//app 1 :
//TC : O(n^2) ; SC : O(constant)
class Solution1 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        for(int i=0; i<n; i++){
            if(result.size()==0 || result[0]!=nums[i]){
                int count=0;
                for(int j=0; j<n; j++){
                    if(nums[j]==nums[i]){
                        count++;
                    }
                }
                    if(count>n/3){
                        result.push_back(nums[i]);
                    }
                if(result.size()==2) break;
            }
        }
        return result;
    }
};


//app 2 :
//TC : O(2N) ; SC : O(N)
class Solution2 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        unordered_map<int, int>freq;

        for(int x : nums){
            freq[x]++;
        }
        for(auto it : freq){
            if(it.second > (n/3)){
                result.push_back(it.first);
            }
        }
        return result;
    }
};

//app 3 : Eliminating the traversal in the map
//TC : O(N) + O(N)
class Solution3 {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        vector<int>result;
        unordered_map<int, int>freq;
        int minimumFreq=(n/3)+1;
        for(int x: nums){
            freq[x]++;
            if(freq[x]==minimumFreq){
                result.push_back(x);
            }
            if(result.size()==2){
                break;
            }
        }
        return result;
    }
};

//app 4 :
//TC : O(N) ; SC : O(constant)
class Solution {
public:

    vector<int> findingCandidates(vector<int>&nums){
        int n=nums.size();
        int cnt1=0;
        int cnt2=0;
        int el1=INT_MIN;
        int el2=INT_MIN;

        for(int x:nums){
            if(cnt1==0 && el2 != x){
                cnt1=1;
                el1=x;
            }
            else if(cnt2==0 && el1 != x){
                cnt2=1;
                el2=x;
            }
            else if(x==el1){
                cnt1++;
            }
            else if(x==el2){
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        return {el1, el2};
    }

    vector<int>manualChecking(vector<int>&nums, vector<int>&findingCandidates){
        int n=nums.size();
        int minimum=(n/3)+1;

        vector<int>result;
        int cnt1=0;
        int cnt2=0;

        for(int x:nums){
            if(x==findingCandidates[0]){
                cnt1++;
            }
            if(x==findingCandidates[1]){
                cnt2++;
            }
        }
            if(cnt1>=minimum){
                    result.push_back(findingCandidates[0]);
                }
            if(cnt2>=minimum && findingCandidates[1] != findingCandidates[0]){
                result.push_back(findingCandidates[1]);
            }
        return result;
    }


    vector<int> majorityElement(vector<int>& nums) {
        vector<int> candidates=findingCandidates(nums);
        vector<int>result=manualChecking(nums, candidates);
        return result;
    }
};
