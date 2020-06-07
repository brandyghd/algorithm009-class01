//236. 二叉树的最近公共祖先
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p ||root == q)
        {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root -> left,p,q);
        TreeNode* right = lowestCommonAncestor(root -> right,p,q);
        if(left && right)
        {
            return root;
        }
        return left ? left : right;
    }
};