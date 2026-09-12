//app 1 : Brute
// TC : O(N^4 * log(M)) : SC : O(n^4) in worst case for quadruplets in set
class Solution1 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    for(int l=k+1; l<n; l++){
                        if(nums[i]+nums[j]+nums[k]+nums[l]==target){
                            vector<int>temp={
                                nums[i],
                                nums[j],
                                nums[k], 
                                nums[l]
                                };
                            sort(temp.begin(), temp.end());
                            st.insert(temp); //suppose M quadruplets
                        }
                    }
                }
            }
        }
        vector<vector<int>>ans(st.begin(), st.end());
        return ans;
    }
};

//app 2 : Hashing
//TC : O(N^3) hashing , with O(log M) set insertion overhead ;
//SC : O(N) for auxillary unordered_set
class Solution2 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        set<vector<int>>st;

        for(int first=0; first<n; first++){
            for(int second=first+1; second<n; second++){
                unordered_set<int>seen;
                for(int third=second+1; third<n; third++){
                    long long sum=nums[first]
                    +nums[second]
                    +nums[third];
                    long long fourth=(long long)target-sum;

                    if(seen.count(fourth)){
                        vector<int>temp={
                            nums[first],
                            nums[second],
                            nums[third],
                            (int)fourth
                            };
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    seen.insert(nums[third]);
                }
            }
        }
        return vector<vector<int>>(st.begin(), st.end());
    }
};

//app 3 : Sorting + two pointer
//TC : O(n^2*n)
//SC : O(no. of quads) : but this is to return to answer
class Solution3 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;

        for(int first=0; first<n; first++){
            if(first>0 && nums[first] == nums[first-1]) continue;
            for(int second=first+1; second<n; second++){
                if(second!=first+1 && nums[second]==nums[second-1]) continue;
                int third=second+1;
                int fourth=n-1;

                while(third<fourth){
                    long long sum=(long long)nums[first]
                    +nums[second]
                    +nums[third]
                    +nums[fourth];

                    if(sum==target){
                        vector<int>temp={nums[first],
                        nums[second],
                        nums[third],
                        nums[fourth]
                        };
                        ans.push_back(temp);
                        third++;
                        fourth--;

                        while(third<fourth && nums[third]==nums[third-1]) third++;
                        while(third<fourth && nums[fourth]==nums[fourth+1]) fourth--;
                    }
                    else if(sum<target) third++;
                    else fourth--;  
                }
            }
        }
        return ans;
    }
};
