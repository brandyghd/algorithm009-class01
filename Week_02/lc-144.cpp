//144. 二叉树的前序遍历
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur;
        cur = root;
        while(cur != NULL)
        {
            if(cur -> left == NULL)
            {
                res.push_back(cur -> val);
                cur = cur -> right;
            }
            else
            {
                TreeNode *temp = cur -> left;
                while(temp -> right != NULL && temp -> right != cur)
                {
                    temp = temp -> right;
                }
                if(temp -> right == NULL)
                {
                    res.push_back(cur -> val);
                    temp -> right = cur;
                    cur = cur -> left;
                }
                else
                {
                    temp -> right = NULL;
                    cur = cur -> right;
                }
            }
        }
        return res;
    }
};