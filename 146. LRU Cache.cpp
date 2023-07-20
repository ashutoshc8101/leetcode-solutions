struct DListNode {
    int val;
    DListNode* next = NULL;
    DListNode* prev = NULL;
};

class LRUCache {
public:
    unordered_map<int, DListNode*> mp;
    int cap;
    int size = 0;
    DListNode* head = NULL;
    DListNode* tail = NULL;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (mp[key] == NULL) {
            return -1;
        }

        if (mp[key]->val == -1) {
            return -1;
        }

        DListNode* temp = mp[key];

        if (temp == head) {
            return temp->val;
        }

        if (tail == temp) {
            tail = tail->prev;
            tail->next = NULL;
        } else {
            temp->next->prev = temp->prev;   
        }

        if (temp->prev) {
            temp->prev->next = temp->next;
            temp->prev = NULL;
            temp->next = head;
            head->prev = temp;
            head = temp;
        }

        return mp[key]->val;
    }
    
    void put(int key, int value) {
        if (mp[key] != NULL && mp[key]->val != -1) {
            mp[key]->val = value;

            get(key);
            
            return;
        }

        DListNode* node = new DListNode();
        node->val = value;

        if (size == cap) {
            DListNode* temp = tail;
            if (tail == head) {
                tail = NULL;
                head = NULL;
            } else {
                tail = tail->prev;
                tail->next = NULL;
            }

            temp->val = -1;
            size--;
        }

        if (!head) {
            head = node;
            tail = node;
        } else {
            head->prev = node;
            node->next = head;
            head = node;
        }

        mp[key] = node;
        size++;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */