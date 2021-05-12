class NumMatrix {
public:
    vector<vector<int>> arr;
    NumMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        arr.push_back(vector<int>(m+1,0));
        for(int i=1;i<n+1;i++){
            arr.push_back(vector<int>(1,0));
            for(int j=1;j<m+1;j++){
                arr[i].push_back(matrix[i-1][j-1]+arr[i][j-1]+arr[i-1][j]-arr[i-1][j-1]);
            }
        }
        // for(auto x:arr){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        // row1--;
        // col1--;
        row2++;
        col2++;
        return arr[row2][col2]+arr[row1][col1]-arr[row1][col2]-arr[row2][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
