//1010. 总持续时间可被 60 整除的歌曲
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        if(time.size() < 2)
        {
            return 0;
        }
        vector<int> a(60,0);
        int res = 0;
        for(int i = 0;i < time.size();i++)
        {
            res += a[(60 - time[i] % 60) % 60];
            a[time[i] % 60] ++;
        }
        return res;
    }
};