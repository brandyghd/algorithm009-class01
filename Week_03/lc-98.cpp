//98. 验证二叉搜索树
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        return isValid(root,LONG_MIN,LONG_MAX);
    }
    bool isValid(TreeNode *root,long low,long high)
    {
        if(!root)
        {
            return true;
        }
        if(root && root -> val <= low)
        {
            return false;
        }
        if(root && root -> val >= high)
        {
            return false;
        }
        if(!isValid(root -> left,low,root -> val))
        {
            return false;
        }
        if(!isValid(root -> right,root -> val,high))
        {
            return false;
        }
        return true;
    }
};