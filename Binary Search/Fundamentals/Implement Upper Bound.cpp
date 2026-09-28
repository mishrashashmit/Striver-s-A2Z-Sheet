class Solution1 {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]>target){
                return i;
            }
        }
        return n;
    }
};

class Solution2 {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>target){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};

class Solution3 {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        int ub=upper_bound(arr.begin(),arr.end(),target)-arr.begin();
        return ub;
    }
};
