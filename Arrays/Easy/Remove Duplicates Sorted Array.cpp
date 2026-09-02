//When the problem requires us to return the modified vector
class Solution1 {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        /*app1 : using set
        TC : O(N log N), SC : O(N) for set*/
        set<int>st;
        for(int i=0; i<arr.size();i++){
            st.insert(arr[i]); //O(n log n)
        }
        int idx=0;
        for(auto it : st){
            arr[idx]=it; //O(N)
            idx++;
        }
        arr.resize(idx); //O(N) in worst case
        return arr;
    }
};

class Solution2 {
  public:
    vector<int> removeDuplicates(vector<int> &arr) {
        // code here
        /*app2 : using two pointer
        TC : O(N) , SC : O(1) */
        int i=0;
        for(int j=1; j<arr.size(); j++){
            if (arr[j] != arr[i]){
                arr[i+1]=arr[j];
                i++;
            }
        }
        arr.resize(i+1);
        return arr;
    }
};


//When we are required to return the number of unique elements
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int> st;
        for(int i=0; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        int index=0;
        for(auto it : st){
            nums[index]=it;
            index++;
        }
        return index;
    }
};

class Solution2 {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int firstPointer=0;
        for(int secondPointer=0; secondPointer<n; secondPointer++){
            if(nums[secondPointer]!=nums[firstPointer]){
                nums[firstPointer+1]=nums[secondPointer];
                firstPointer++;
            }
        }
        return firstPointer+1;
    }
};
