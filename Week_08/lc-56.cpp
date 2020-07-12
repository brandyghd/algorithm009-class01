//56. 合并区间
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > res;
        if(!intervals.size())
        {
            return res;
        }
        sort(intervals.begin(),intervals.end());

        for(int i = 0;i < intervals.size();i++)
        {

            int L = intervals[i][0];
            int R = intervals[i][1];
            if(!res.size() || res.back()[1] < L)
            {
                res.push_back({L,R});
            }
            else
            {
                res.back()[1] = max(res.back()[1],R);
            }
        }
        return res;
    }
};