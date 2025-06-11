class Node {
public:
    int key, val, freq;
    Node* prev;
    Node* next;

    Node(int _key, int _val) {
        key = _key;
        val = _val;
        freq = 1;
        prev = NULL;
        next = NULL;
    }
};

class DLL {
public:
    Node* head;
    Node* tail;
    int size;

    DLL() {
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addNode(Node* node) {
        Node* after = head->next;
        head->next = node;
        node->prev = head;
        node->next = after;
        after->prev = node;
        size++;
    }

    void deleteNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
        size--;
    }

    bool isEmpty() {
        return size == 0;
    }

    Node* removeLast() {
        if (isEmpty()) return NULL;
        Node* node = tail->prev;
        deleteNode(node);
        return node;
    }
};

class LFUCache {
public:
    int cap, minFreq;
    unordered_map<int, Node*> keyNode;
    unordered_map<int, DLL*> freqList;

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    void updateFreq(Node* node) {
        int freq = node->freq;
        freqList[freq]->deleteNode(node);

        if (freqList[freq]->isEmpty()) {
            if (minFreq == freq) minFreq++;
            delete freqList[freq];
            freqList.erase(freq);
        }

        node->freq++;
        if (freqList.find(node->freq) == freqList.end()) {
            freqList[node->freq] = new DLL();
        }
        freqList[node->freq]->addNode(node);
    }

    int get(int key) {
        if (keyNode.find(key) == keyNode.end()) return -1;

        Node* node = keyNode[key];
        updateFreq(node);
        return node->val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key];
            node->val = value;
            updateFreq(node);
        } else {
            if (keyNode.size() == cap) {
                Node* nodeToRemove = freqList[minFreq]->removeLast();
                keyNode.erase(nodeToRemove->key);
                delete nodeToRemove;
            }

            Node* newNode = new Node(key, value);
            minFreq = 1;
            if (freqList.find(1) == freqList.end()) {
                freqList[1] = new DLL();
            }
            freqList[1]->addNode(newNode);
            keyNode[key] = newNode;
        }
    }
};
