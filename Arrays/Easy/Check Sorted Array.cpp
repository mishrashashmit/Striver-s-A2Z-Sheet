class Solution {
  public:
  //TC : O(N) , SC : O(1)
    bool isSorted(vector<int>& arr) {
        // code here
        for(int i=1; i<arr.size(); i++){
            if(arr[i-1]>arr[i]){ //if any one pair is not sorted return false
                return false;
            }
        }
        return true;
    }
};
