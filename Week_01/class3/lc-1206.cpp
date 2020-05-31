//1206. 设计跳表
class Node
{
public:
    Node *right,*down;
    int val;
    Node(Node *right,Node *down,int val):right(right),down(down),val(val) {}
};

class Skiplist {
private:
    Node *head;
public:
    Skiplist() {
        head = new Node(NULL,NULL,-1);
    }
    
    bool search(int target) {
        Node *p = head;
        while(p)
        {
            while(p -> right && target > p -> right -> val)
            {
                p  = p -> right;
            }
            if(!p -> right || target < p -> right -> val)
            {
                p = p -> down;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
    
    void add(int num) {
        stack<Node *> temp;
        Node *p = head;
        while(p)
        {
            while(p -> right && num > p -> right -> val)
            {
                p = p -> right;
            }
            temp.push(p);
            p = p -> down;
        }

        int flag = 1;//随机往上层插入新节点
        Node *newDownNode = NULL;
        Node *last = NULL;
        while(flag && !temp.empty())
        {
            last = temp.top();
            temp.pop();
            last -> right = new Node(last -> right,newDownNode,num);
            newDownNode = last -> right;
            flag = (rand() & 1);
        }
        if(flag)
        {
            head = new Node(new Node(NULL,newDownNode,num),head,-1);//??
        }
    }
    
    bool erase(int num) {
        Node *p = head;
        int find = 0;
        while(p)
        {
            while(p -> right && num > p -> right -> val)
            {
                p = p -> right;
            }
            if(!p -> right || p -> right ->val > num)
            {
                p = p -> down;
            }
            else
            {
                find = 1;
                p -> right = p -> right -> right;
                p = p -> down;
            }
        }
        return find;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */