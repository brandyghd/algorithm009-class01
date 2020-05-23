//26. 删除排序数组中的重复项
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(!nums.size())
        {
            return 0;
        }
        int i = 0;
        for(int j = 0;j < nums.size();j++)
        {
            if(nums[i] != nums[j])
            {
                nums[++i] = nums[j];
            }
        }
        return i + 1;
    }
};