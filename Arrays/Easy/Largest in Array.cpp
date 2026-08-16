class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        
        
        //Using Loop : Tc : O(n), Sc : O(1)
        int largestNum=arr[0];
        for(int idx=0; idx < arr.size(); idx++){
            if(arr[idx]>largestNum){
                largestNum=arr[idx];
            }
        }
        return largestNum;
        
        //Using STL : Tc : O(1), Sc : O(1)
        /*int largestN = *max_element(arr.begin(), arr.end());
        return largestN;*/
        
    }
};
