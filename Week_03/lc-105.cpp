//105. 从前序与中序遍历序列构造二叉树
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int size = preorder.size();
        if (size == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int ptr1 = 0, ptr2 = 0;
        TreeNode* node = root;
        unordered_map<int, TreeNode*> val2node;
        val2node[root->val] = root;
        while (ptr1 < size - 1) {
            while (preorder[ptr1] != inorder[ptr2]) {
                node->left = new TreeNode(preorder[++ptr1]);
                node = node->left;
                val2node[node->val] = node;
            }
            if (ptr1 == size - 1)
                break;
            while (val2node.find(inorder[ptr2]) != val2node.end()) {
                ++ptr2;
            }
            node = val2node[inorder[ptr2 - 1]];
            node->right = new TreeNode(preorder[++ptr1]);
            node = node->right;
            val2node[node->val] = node;
        }
        
        return root;
    }
};