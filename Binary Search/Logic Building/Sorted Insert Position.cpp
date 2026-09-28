class Solution1 {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        for(int i=0; i<n; i++){
            if(arr[i]>=k){
                return i;
            }
        }
        return n;
    }
};

class Solution2 {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int n=arr.size();
        int low=0;
        int high=n-1;
        int ans=n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]>=k){
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

class Solution {
  public:
    int searchInsertK(vector<int> &arr, int k) {
        // code here
        int reqIdx=lower_bound(arr.begin(),arr.end(),k)-arr.begin();
        return reqIdx;
    }
};
