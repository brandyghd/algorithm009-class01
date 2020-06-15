//126. 单词接龙 II
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordlist;
        unordered_set<string> visited;
        unordered_set<string> cur,next;
        unordered_map<string,vector<string> > tree;
        wordlist.insert(wordList.begin(),wordList.end());

        auto istarget = [&](const string& str)
        {
            return str == endWord;
        };

        auto generate = [&](const string& str)
        {
            unordered_set<string> result;

            for(int i = 0;i < str.size();i++)
            {
                string temp(str);
                for(char c = 'a';c <= 'z';c++)
                {
                    if(temp[i] == c)
                    {
                        continue;
                    }
                    swap(temp[i],c);
                    if(wordlist.count(temp) > 0 && !visited.count(temp))
                    {
                        result.insert(temp);
                    }
                    swap(temp[i],c);
                }
            }
            return result;
        };

        cur.insert(beginWord);
        int flag = 0;
        
        while(!cur.empty() && !flag)
        {
            for(const auto& word : cur)
            {
                visited.insert(word);
            }
            for(const auto &word : cur)
            {
                auto temp= generate(word);
                for(const auto& subword : temp)
                {
                    if(subword == endWord)
                    {
                        flag = true;
                    }
                    next.insert(subword);
                    tree[word].push_back(subword);
                }
            }

            cur.clear();
            swap(cur,next);
       }

        vector<vector<string> > result;
        if(flag)
        {
            vector<string> path;
            path.push_back(beginWord);
            gen(result,path,beginWord,endWord,tree);
        }
        return result;
    }

    void gen(vector<vector<string> >& result,vector<string>& path,string begin,string end,unordered_map<string,vector<string> >& tree)
    {
        if(begin == end)
        {
            result.push_back(path);
            return;
        }

        if(tree.count(begin) == 0)
        {
            return;
        }

        for(const auto& f : tree[begin])
        {
            path.push_back(f);
            gen(result,path,f,end,tree);
            path.pop_back();
        }
    }
};