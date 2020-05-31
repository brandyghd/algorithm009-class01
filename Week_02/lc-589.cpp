//589. N叉树的前序遍历
class Solution {
public:
    vector<int> res;
    vector<int> preorder(Node* root)
    {
        if(!root)
        {
            return res;
        }
        Node *p = root;
        stack<Node*> s;
        s.push(p);
        while(!s.empty())
        {
            p = s.top();
            res.push_back(p -> val);
            s.pop();
            for(int i = p -> children.size() - 1;i >= 0;i--)
            {
                if(p -> children[i])
                {
                    s.push(p -> children[i]);
                }
            }
        }
        return res;
	}
};