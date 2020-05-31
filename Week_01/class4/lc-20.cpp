//20. 有效的括号
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char> temp = {
            {'(',')'},
            {'{','}'},
            {'[',']'}
        };
        if(s.size() == 0)
        {
            return true;
        }
        if(s.size() % 2)
        {
            return false;
        }
        stack<char> ss;
        for(int i = 0;i < s.size();i++)
        {
            if(ss.empty())
            {
                ss.push(s[i]);
            }
            else if(temp[ss.top()] != s[i])
            {
                ss.push(s[i]);
            }
            else
            {
                ss.pop();
            }
        }
        return ss.empty();
    }
};