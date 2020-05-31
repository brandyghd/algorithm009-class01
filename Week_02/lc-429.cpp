//429. N叉树的层序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int> > res;
        if(!root) 
        {
            return res;
        }

        queue<Node*> q;
        q.push(root);
        Node *p;
        while(!q.empty())
        {
            vector<int> temp;
            int size = q.size();
            for(int i = 0;i < size;i++)
            {
                p = q.front();
                temp.push_back(p -> val);
                q.pop();
                for(int j = 0;j < p -> children.size();j++)
                {
                    q.push(p -> children[j]);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};