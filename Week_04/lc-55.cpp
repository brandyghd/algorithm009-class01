//55. 跳跃游戏
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = nums[0];
        int n = nums.size();
        for(int i = 0;i < reach + 1;i++)
        {
            reach = max(reach,i + nums[i]);
            if(reach >= n - 1)
            {
                return true;
            }
        }
        return false;
    }
};