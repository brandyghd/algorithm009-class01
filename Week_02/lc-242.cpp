//242. 有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> chars(26,0);
        if(s.size() != t.size())
            return false;
        for(int i = 0;i < s.size();i++)
        {
            ++chars[s[i] - 'a'];
            --chars[t[i] - 'a'];
        }
        for(int i = 0;i < 26;i++)
        {
            if(chars[i])
            {
                return false;
            }
        }
        return true;
    }
};