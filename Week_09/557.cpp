//557. 反转字符串中的单词 III
class Solution {
public:
    string reverseWords(string s) {
        int i = 0,j = 0;
        for(;i < s.size();i++)
        {
            while(j < s.size() && s[j] != ' ')
            {
                j++;
            }
            reverse(s.begin() + i,s.begin() + j);
            
            while(j < s.size() && s[j] == ' ')
            {
                j++;
            }
            i = j - 1;
        }
        return s;
    }
};