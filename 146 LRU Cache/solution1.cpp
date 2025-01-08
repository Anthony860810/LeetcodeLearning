class Node {
    public:
        int key;
        int val;
        Node *next;
        Node *prev;
        Node(int input_key, int input_val) {
            key = input_key;
            val = input_val;
        };
};


class LRUCache {
private:
    struct Node *head;
    struct Node *tail;
    unordered_map<int, Node*> cache;
    int capacity;

public:
    LRUCache(int size) {
        head = new Node(0,0);
        tail = new Node(0,0);
        head->next = tail;
        tail->prev = head;
        capacity = size;
    }
    
    void remove_node_from_cur(Node *node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    void insert_node_to_tail(Node *node) {
        node->prev = tail->prev;
        node->next = tail;
        tail->prev->next = node;
        tail->prev = node;
    }

    int get(int key) {     
        if (cache.find(key) == cache.end())
            return -1;

        remove_node_from_cur(cache[key]);
        insert_node_to_tail(cache[key]);

        return cache[key]->val;
    }
    
    void put(int key, int value) {
        struct Node *node;
        struct Node *old_node = NULL;

        if (cache.find(key) != cache.end()) {
            cache[key]->val = value;
            remove_node_from_cur(cache[key]);
            insert_node_to_tail(cache[key]);
            return;
        }
        
        node = new Node(key, value);
        cache[key] = node;
        insert_node_to_tail(node);

        if (cache.size() > capacity) {
            old_node = head->next;
            cache.erase(old_node->key);
            remove_node_from_cur(old_node);
            delete old_node;
        }
    }
};
