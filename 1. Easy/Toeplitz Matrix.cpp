class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                for(int k = i, l = j; k < m && l < n; k++, l++) {
                    if(matrix[k][l] != matrix[i][j]) return false;
                }
            }
        }
        return true;
    }
};
