class Node {
public:
    int key, val;
    Node* prev;
    Node* next;
    Node(int _key, int _val) {
        key = _key;
        val = _val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    map<int, Node*> mpp;
    int cap;
    Node *head, *tail;

    // Delete a node from the list
    void deletenode(Node* node) {
        Node* prevnode = node->prev;
        Node* nextnode = node->next;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
    }

    // Insert a node right after head
    void insertafterhead(Node* node) {
        Node* after = head->next;
        head->next = node;
        node->prev = head;
        node->next = after;
        after->prev = node;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (mpp.find(key) == mpp.end()) return -1;
        Node* node = mpp[key];
        deletenode(node);
        insertafterhead(node);
        return node->val;
    }

    void put(int key, int value) {
        if (mpp.find(key) != mpp.end()) {
            Node* node = mpp[key];
            node->val = value;
            deletenode(node);
            insertafterhead(node);
        } else {
            if (mpp.size() == cap) {
                Node* nodeToDelete = tail->prev;
                mpp.erase(nodeToDelete->key);
                deletenode(nodeToDelete);
                delete nodeToDelete;
            }
            Node* node = new Node(key, value);
            mpp[key] = node;
            insertafterhead(node);
        }
    }
};
