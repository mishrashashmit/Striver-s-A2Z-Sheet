//app 1 :
//TC : O(n3logn) ; SC : O(n3)​
class Solution1 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){ //O(n^3)
                    if(nums[i]+nums[j]+nums[k]==0){
                        vector<int>temp={nums[i], nums[j], nums[k]};
                        sort(temp.begin(), temp.end()); //O(1)
                        st.insert(temp); //O(log n)
                    }
                }
            }
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//app 2 : 
//  TC : O(n^2 * log(no of unique triplets))
class Solution2 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        set<vector<int>>st;
        unordered_set<int>seen;

        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int third= -(nums[i]+nums[j]);
                    if(seen.find(third) != seen.end()){
                        vector<int>temp={nums[i], nums[j], third};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                seen.insert(nums[j]);
            }
            seen.clear();
        }
        vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};

//app 3 : 
// TC : O(nlogm + n^2) ; SC : O(1)
class Solution3 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int sum;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>>ans;
        //first element
        for(int i=0; i<n; i++){
            //skip same first element
            if( i> 0 && nums[i]==nums[i-1]) continue;

            //two pointers
            int left=i+1;
            int right=n-1;

            while(left < right){
                sum=nums[i]+nums[left]+nums[right];

                if(sum==0){
                    ans.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                //skip same left
                while(left<right && nums[left]== nums[left-1]) left++;
                //skip same right
                while(left<right && nums[right] == nums[right+1]) right--;
                }
                else if(sum<0) left++;
                else right--;
            }
        }
        return ans;
    }
};
