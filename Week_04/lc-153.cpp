//153. 寻找旋转排序数组中的最小值
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right)
        {
            int middle = left + (right - left) / 2;

            if(nums[middle] > nums[right])//zuo youxu
            {
                left = middle + 1;
            }
            else//you youxu
            {
                right = middle;
            }
        }
        return nums[left];
    }
};