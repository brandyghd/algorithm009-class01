//94. 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode *cur,*temp;
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
                temp = cur -> left;
                while(temp -> right != NULL && temp -> right != cur)
                {
                    temp = temp -> right;
                }
                if(temp -> right == NULL)
                {
                    temp -> right = cur;
                    cur = cur -> left;
                }
                else
                {
                    res.push_back(cur -> val);
                    temp -> right = NULL;
                    cur = cur -> right;
                }
            }
        }
        return res;
    }
};