//1013. 将数组分成和相等的三个部分
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int total = accumulate(A.begin(),A.end(),0);
        if(total % 3)
        {
            return false;
        }
        int s = 0,count = 0;

        for(int i = 0;i < A.size();i++)
        {
            s += A[i];
            if(s == total / 3)
            {
                s = 0;
                count++;
                if(count == 2 && i != A.size() - 1)
                {
                    return true;
                }
            }
        }
        return false;
    }
};