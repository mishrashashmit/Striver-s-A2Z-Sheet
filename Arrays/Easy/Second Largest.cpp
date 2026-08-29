class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        
        //app1- TC : O(nlogn)
        //sort and return (n-2)th element
        
        
        //app2- TC: O(N+N)
        //first pass
        /*int largest=arr[0];
        for(int i=0; i <arr.size(); i++){
            if(arr[i]>largest)
                largest=arr[i];
        }
        //second pass
        int slargest=INT_MIN;
        for(int i=0; i<arr.size(); i++){
        if(arr[i]!=largest && arr[i]>slargest)
            slargest=arr[i];
        }
        if(slargest == INT_MIN) //when all elements are equal
            return -1;
        else{
            return slargest;
        }*/
        
        
        //app3-TC O(N)
        if(arr.size()<2) return -1;
        
        int largest=INT_MIN;
        int slargest=INT_MIN;
        for(int i=0; i<arr.size();i++){
            if(arr[i]>largest){
                slargest=largest;
                largest=arr[i];
            }
            else if(arr[i]>slargest && arr[i] < largest)
                slargest=arr[i];
        }
        if(slargest==INT_MIN){
            return -1;
        }
        else{
            return slargest;
        }
    }
};
