class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        dfs(nums, 0);
        return ans;
    }

    void dfs(vector<int> nums, int idx) {
        int n = nums.size();
        if (idx == n) ans.emplace_back(nums);

        unordered_set<int> s;
        for (int i = idx; i < n; ++i) {
            if (s.find(nums[i]) != s.end()) continue; //剪枝
            s.insert(nums[i]);

            vector<int> tmp = nums;
            swap(tmp[idx], tmp[i]);
            dfs(tmp, idx + 1);  
        }
    }
};
