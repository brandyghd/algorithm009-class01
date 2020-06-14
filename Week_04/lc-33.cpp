//33. 搜索旋转排序数组
class Solution {
public:
    int bsearch(vector<int>& nums,int target,int low,int high)
    {
        if(low > high)
        {
            return -1;
        }
        int middle = low + (high - low) / 2;
        if(nums[middle] == target)
        {
            return middle;
        }
        if(nums[low] <= nums[middle])
        {
            if(target >= nums[low] && target < nums[middle])
            {
                return bsearch(nums,target,low,middle - 1);
            }
            return bsearch(nums,target,middle + 1,high);
        }
        else
        {
            if(target > nums[middle] && target <= nums[high])
            {
                return bsearch(nums,target,middle + 1,high);
            }
            return bsearch(nums,target,low,middle - 1);
        }
    }
    int search(vector<int>& nums, int target) {
        return bsearch(nums,target,0,nums.size() - 1);
    }
};