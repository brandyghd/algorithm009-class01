//347. 前 K 个高频元素
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> m;
        priority_queue<pair<int,int> > q;
        for(int i = 0;i < nums.size();i++)
        {
            m[nums[i]]++;//freq
        }
        for(unordered_map<int,int>::iterator it = m.begin();it != m.end();it++)
        {
            if(it->second)
            {
                q.push(make_pair(it->second,it->first));
            }
        }
        for(int i = 0;i < k;i++)
        {
            res.push_back(q.top().second);
            q.pop();
        }
        return res;
    }
};