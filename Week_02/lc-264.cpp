//264. 丑数 II
class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long,vector<long>,greater<long> > a;
        long res = 1;
        for(int i = 1;i < n;i++)
        {
            a.push(res * 2);
            a.push(res * 3);
            a.push(res * 5);
            res = a.top();
            while(!a.empty() && res == a.top())
            {
                a.pop();
            }
        }
        return res;
    }
};