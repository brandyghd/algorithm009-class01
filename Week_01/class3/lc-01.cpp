//1. 两数之和
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> res;
        unordered_map<int,int> temp;
        for(int i = 0;i < nums.size();i++)
        {
            if(temp.find(target - nums[i]) != temp.end())
            {
                return {temp[target - nums[i]] , i};
            }
            temp[nums[i]] = i;
        }
        return {};
    }
};