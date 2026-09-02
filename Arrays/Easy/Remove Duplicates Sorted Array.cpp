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
