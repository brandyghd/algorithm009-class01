class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int curNum = nums[0];
        int count = 1;
        int len = nums.size();
        for (int i = 1; i < len; ++i)
        {
            if (count == 0)
            {
                curNum = nums[i]; 
                count = 1;
            }
            else
            {
                if (nums[i] != curNum) count--;
                else count++;
            }
        }

        return curNum;
    }
};