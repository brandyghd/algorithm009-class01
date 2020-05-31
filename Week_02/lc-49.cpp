//49. 字母异位词分组
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string> > res;
        unordered_map<string,int> t_map;
        string temp;
        for(int i = 0,j = 0;i < strs.size();i++)
        {
            temp = strs[i];
            sort(temp.begin(),temp.end());
            if(t_map.find(temp) == t_map.end())
            {
                vector<string> a(1,strs[i]);
                res.push_back(a);
                t_map[temp] = j++;
            }
            else
            {
                res[t_map[temp]].push_back(strs[i]);
            }
        }
        return res;
    }
};