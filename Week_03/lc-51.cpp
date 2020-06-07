class Solution {
    vector<vector<string>> res;//存结果
    vector<string> tmp;//存棋盘
public:
    vector<vector<string>> solveNQueens(int n) {
        string line(n,'.');//既然一行一行试，那就一行一行存
        solveNQueens(line, 0, n);//从第0行开始
        return res;
    }

private:
    //试某一行
    void solveNQueens(string& line, int row, int n)
    {
        if(tmp.size() == n)//棋盘绘制够n行存进结果，不用继续试了
        {
            res.push_back(tmp);
            return;
        }
        for(int i = 0; i < n; ++i)//一格一格，每格都要试
        {
            if(checkAll(row, i, n))     //符合条件了
            {
                line[i] = 'Q';          //就把当前试的这一格放皇后
                tmp.push_back(line);    //然后把这一行绘制进棋盘
                line[i] = '.';          //棋盘的下一行应该是没有皇后的
                solveNQueens(line, row + 1, n);//去试下一行
                tmp.pop_back();         //接下来要去试下一格，刚才绘制进去的那一行删掉
            }
        }
    }

    //暴力检查条件
    bool checkAll(int row, int col, int n)
    {
        for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i,--j)//左上方
        {
            if(tmp[i][j] == 'Q')
                return false;
        }
        for(int i = row - 1; i >= 0; --i)//正上方
        {
            if(tmp[i][col] == 'Q')
                return false;
        }
        for(int i = row -1, j = col + 1; i >= 0 && j < n; --i, ++j)//右上方
        {
            if(tmp[i][j] == 'Q')
                return false;
        }
        return true;
    }

    //修改后的检查条件，内存消耗更小了
    bool checkAll(int row, int col, int n)
    {
        for(int i = 1; i <= row ; ++i)
        {
            if(col - i >= 0 && tmp[row - i][col - i] == 'Q')
                return false;
            if(col + i < n && tmp[row - i][col + i] == 'Q')
                return false;
            if(tmp[row - i][col] == 'Q')
                return false;
        }
        return true;
    }
};