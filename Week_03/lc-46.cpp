class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        dfs(0, nums.size() - 1, nums);
        return result;
    }

private:
    vector<vector<int>> result;
    void dfs(int begin, int end, vector<int>& nums) {
        if (begin == end) {
            result.emplace_back(nums);
        }
        for (int i = begin; i <= end; i++) {
            swap(nums[i], nums[begin]);
            dfs(begin + 1, end, nums);
            swap(nums[i], nums[begin]);
        }
    }
};
