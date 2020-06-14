//74. 搜索二维矩阵
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m)
        {
            return 0;
        }
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;
        int middle = 0;
        while(left <= right)
        {
            middle = left + (right - left) / 2;
            int i = middle / n;
            int j = middle % n;
            if(target == matrix[i][j])
            {
                return true;
            }
            if(matrix[i][j] > target)
            {
                right = middle - 1;
            }
            else
            {
                left = middle + 1;
            }
        }
        return false;
    }
};