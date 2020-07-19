//917. 仅仅反转字母
class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0;
        int j = S.size() - 1;
        while(i < j)
        {
            while(!isalpha(S[i]) && i < S.size())
            {
                i++;
            }
            while(!isalpha(S[j]) && j > 0)
            {
                j--;
            }
            while(isalpha(S[i]) && isalpha(S[j]) && i < j)
            {
                swap(S[i],S[j]);
                i++;
                j--;
            }
        }
        return S;
    }
};