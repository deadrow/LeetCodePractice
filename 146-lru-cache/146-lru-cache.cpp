struct Node
{
    Node(int k, int v) : key(k), val(v) {}
    
    int key;
    int val;
    Node* prev{nullptr};
    Node* next{nullptr};
};

class DoublyLinkedList
{
public:
    DoublyLinkedList()
    {
        // Init with dummy nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }
    
    void pushFront(Node* node)
    {
        head->next->prev = node;
        node->next = head->next;
        
        node->prev = head;
        head->next = node;
    }
    
    void removeNode(Node* node)
    {
        node->next->prev = node->prev;
        node->prev->next = node->next;
    }
    
    Node* popTailNode()
    {
        Node* res = tail->prev;
        removeNode(res);
        return res;
    }
    
private:
    Node* head{nullptr};
    Node* tail{nullptr};
};

class LRUCache {
public:
    DoublyLinkedList lru;
    unordered_map<int, Node*> cache;
    int capacity{0};
    int size{0};
    
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    void moveToFront(Node* node)
    {
        lru.removeNode(node);
        lru.pushFront(node);
    }
    
    int get(int key) {
        if(cache.find(key) != cache.end())
        {
            Node* node = cache[key];
            moveToFront(node);
            return node->val;
        }

        return -1;
    }
    
    void put(int key, int value) {
        Node* node = nullptr;
        if(cache.find(key) != cache.end())
        {
            node = cache[key];
            node->val = value;
            moveToFront(node);
        }
        else
        {
            // if lru is full, remove last element
            if(size >= capacity)
            {
                Node* lastNode = lru.popTailNode();
                cache.erase(lastNode->key);
            }

            node = new Node(key, value);
            lru.pushFront(node);
            
            size++;
        }
        
        cache[key] = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */