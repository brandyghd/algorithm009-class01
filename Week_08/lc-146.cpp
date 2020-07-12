//146. LRU缓存机制
struct LRUlistnode
{
    int key;
    LRUlistnode *pre,*next;
    LRUlistnode(int k) : key(k),pre(NULL),next(NULL) {}
};

class LRUCache {
private:
    LRUlistnode *head,*tail;
    int capacity;
    int size;
    unordered_map<int,pair<int,LRUlistnode*> > LRUmap;
public:
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        size = 0;
        this -> capacity = capacity;
    }
    
    int get(int key) {
        if(!LRUmap.count(key))
        {
            return -1;
        }
        else
        {
            LRUlistnode *p = LRUmap[key].second;
            if(p -> next && p -> pre)
            {
                p -> pre -> next = p -> next;
                p -> next -> pre = p -> pre;
                p -> pre = tail;
                tail -> next = p;
                p -> next = NULL;
                tail = p;
            }
            else if(p -> next)
            {
                head = p -> next;
                head -> pre = NULL;
                p -> pre = tail;
                tail -> next = p;
                tail = p;
                tail -> next = NULL;
            }
            return LRUmap[key].first;
        }
    }
    
    void put(int key, int value) {
        if(!LRUmap.count(key))
        {
            LRUlistnode *p = new LRUlistnode(key);
            if(!tail)
            {
                tail = p;
                head = p;
            }
            else
            {
                p -> next = NULL;
                p -> pre = tail;
                tail -> next = p;
                tail = p;
            }
            pair<int,LRUlistnode *> node;
            node = make_pair(value,p);
            LRUmap[key]  = node;
            size ++;
            if(size > capacity)
            {
                LRUmap.erase(head -> key);
                LRUlistnode *q = head;
                head = q -> next;
                head -> pre = NULL;
                delete q;
            }
        }
        else
        {
            LRUmap[key].first = value;
            LRUlistnode *p = LRUmap[key].second;
            if(p -> next && p -> pre)
            {
                p -> pre -> next = p -> next;
                p -> next -> pre = p -> pre;
                p -> pre = tail;
                tail -> next = p;
                p -> next = NULL;
                tail = p;
            }
            else if(p -> next)
            {
                head = p -> next;
                head -> pre = NULL;
                p -> pre = tail;
                tail -> next = p;
                tail = p;
                tail -> next = NULL;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */