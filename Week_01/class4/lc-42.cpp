//42. 接雨水
class Solution {
public:
    int trap(vector<int>& height) {
        if(!height.size())
        {
            return 0;
        }
        
        vector<int> left(height.size()),right(height.size());
        int i,res = 0;
        left[0] = height[0];
        right[height.size() - 1] = height[height.size() - 1];
        for(i = 1;i < height.size();i++)//
        {
            left[i] = max(left[i - 1],height[i]);
        }
        for(i = height.size() - 2;i >= 0;i--)
        {
            right[i] = max(right[i + 1],height[i]);
        }
        for(i = 1;i < height.size() - 1;i++)
        {
            res += min(left[i],right[i]) - height[i];
        }
        return res;
    }
};
