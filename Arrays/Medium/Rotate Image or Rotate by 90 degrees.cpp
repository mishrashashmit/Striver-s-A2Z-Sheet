//app 1:
//TC = O(N^2) ; SC = O(N^2)
class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {

        int rows=matrix.size();
        int cols=matrix[0].size();
         vector<vector<int>> answer(rows, vector<int>(cols));

        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                answer[j][rows-1-i]=matrix[i][j];
            }
        }
        matrix=answer;
    }
};

//app 2:
//TC = O(N²) + O(N²) = O(N^2) ; SC = O(1)
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        //transpose : TC : O(N/2 * N/2)
        for(int i=0; i<rows; i++){
            for(int j=i+1; j<rows; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        //reverse : TC : (N*N/2)
        for(int i=0; i<rows; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};
