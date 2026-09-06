//app 1:
//TC = O(rows*cols)*(rows+cols) + (rows*cols) ≈ O(N^3)
class Solution1 {
public:
        void markRow(vector<vector<int>>&matrix, int row){
            int cols=matrix[0].size();
            for(int col=0; col<cols; col++){
                if(matrix[row][col]!=0){
                    matrix[row][col]=-1;
                }
            }
        }

        void markCol(vector<vector<int>>&matrix, int col){
            int rows=matrix.size();
            for(int row=0; row<rows; row++){
                if(matrix[row][col]!=0){
                    matrix[row][col]=-1;
                }
            }
        }

    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        //first traversal for finding 0s
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(matrix[row][col]==0){
                    markRow(matrix, row);
                    markCol(matrix, col);
                }
            }
        }

        //for marking the row and col as 0
        for(int row=0; row<rows; row++){
            for(int col=0; col<cols; col++){
                if(matrix[row][col]==-1){
                    matrix[row][col]=0;
                }
            }
        }
    }
};

//app 2:
//TC = 2 O(nOfRows * nOfCols); SC = O(N) + O(M)
class Solution{
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int nOfRows=matrix.size();
        int nOfCols=matrix[0].size();

        vector<int>markedRow(nOfRows, 0);
        vector<int>markedCol(nOfCols, 0);

        for(int i=0; i<nOfRows; i++){
            for(int j=0; j<nOfCols; j++){
                if(matrix[i][j]==0){
                    markedRow[i]=1;
                    markedCol[j]=1;
                }
            }
        }

        for(int i=0; i<nOfRows; i++){
            for(int j=0; j<nOfCols; j++){
                if(markedRow[i] || markedCol[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};

//app 3 :
// 
class Solution3 {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
    }
};
