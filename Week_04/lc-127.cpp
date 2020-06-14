//127. 单词接龙
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> l;
        unordered_set<string> visited;//访问过节点
        queue<string> cur;
        l.insert(wordList.begin(), wordList.end());
        auto istarget = [&](const string &s)//lambda匿名函数
        {
            return s == endWord;
        };
        auto wordextend = [&](const string &s)
        {
            vector<string> result;
            for(int i = 0;i < s.size();i++)
            {
                string newword(s);
                for(char c = 'a';c <= 'z';c++)
                {
                    if(c == newword[i])
                    {
                        continue;
                    }
                    swap(c,newword[i]);
                    if((l.count(newword) > 0) && !visited.count(newword))
                    {
                        result.push_back(newword);
                        visited.insert(newword);
                    }
                    swap(c,newword[i]);
                }
            }
            return result;
        };

        cur.push(beginWord);
        int size = cur.size();
        int level = 0;
        bool found = 0;
        while(!cur.empty() && !found)
        {
            ++level;
            size = cur.size();
            for(int i = 0;(i < size) && !found;i++)
            {
                string str = cur.front();
                cur.pop();

                const auto& newresult = wordextend(str);
                for(auto res : newresult)
                {
                    cur.push(res);
                    if(istarget(res))
                    {
                        found = 1;
                        break;
                    }
                    cur.push(res);
                }
            }
        }
        if(found) 
        {
            return level + 1;
        }
        else return 0;
    }
};