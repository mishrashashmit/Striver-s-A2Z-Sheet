//app 1 :
//TC : O(N^3)
class Solution1 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();
        for(int i=0 ; i<n ; i++){
            for(int j=i ; j<n ; j++){
                int sum=0;
                //for subarray
                for(int k=i ; k<=j ; k++){
                    sum=sum+nums[k];
                }
                if(sum==k){
                    count++;
                }
            }
        }
        return count;
    }
};


//app2 :
//TC : O(N^2)
class Solution2 {
public:
    int subarraySum(vector<int>& nums, int k) {
        int count=0;
        int n=nums.size();

        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum=sum+nums[j];
                    if(sum==k){
                        count++;
                }
            }
        }
        return count;
    }
};


//app 3 :
// TC : O(N)
class Solution3 {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n=nums.size();
        unordered_map<int, int>mpp;
        mpp[0]=1;
        int preSum=0;
        int count=0;
        for(int i=0; i<n; i++){
            preSum+=nums[i];

            int remove=preSum-k;
            count+=mpp[remove];
            mpp[preSum]++;
        }
        return count;
    }
};
