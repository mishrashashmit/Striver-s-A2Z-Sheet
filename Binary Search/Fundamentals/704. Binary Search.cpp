//ITERATIVE APPROACH
class Solution1 {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int low=0;
        int high=n-1;

        while(low<=high){
            int mid=(low+high)/2;
            if(target==nums[mid]) return mid;
            else if(target>nums[mid]) low=mid+1;
            else high=mid-1;
        }
        return -1;
    }
};

//RECURSIVE APPROACH
class Solution2 {
public:
    int binarySearch(vector<int>&arr, int low, int high, int target){
        if(low>high) return -1; //base case
        int mid=(low+high)/2;
        if(arr[mid]==target) return mid;
        else if(target>arr[mid]){
            return binarySearch(arr, mid+1, high, target);
        }
        else{
            return binarySearch(arr, low, mid-1, target);
        }
    }
    
    int search(vector<int>& nums, int target) {
        return binarySearch(nums, 0, (nums.size()-1), target);
    }
};
