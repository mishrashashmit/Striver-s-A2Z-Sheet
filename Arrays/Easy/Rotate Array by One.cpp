class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
      //TC : O(N) ' SC :O(1)
        int n=arr.size();
        int temp=arr[n-1];
        for(int j=n-2; j>=0;j--){
            arr[j+1]=arr[j];
        }
        arr[0]=temp;
    }
};
