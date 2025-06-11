class LFUCache {
public:
    int cap, minFreq;
    unordered_map<int, pair<int, int>> keyToValFreq; // key -> {val, freq}
    unordered_map<int, list<int>> freqToKeys;        // freq -> keys with that freq
    unordered_map<int, list<int>::iterator> keyToIter; // key -> iterator in freqToKeys

    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (keyToValFreq.find(key) == keyToValFreq.end()) return -1;

        // Get current value and freq
        int val = keyToValFreq[key].first;
        int freq = keyToValFreq[key].second;

        // Remove key from current freq list
        freqToKeys[freq].erase(keyToIter[key]);
        if (freqToKeys[freq].empty()) {
            freqToKeys.erase(freq);
            if (minFreq == freq) minFreq++;
        }

        // Add key to next freq list
        freqToKeys[freq + 1].push_front(key);
        keyToIter[key] = freqToKeys[freq + 1].begin();

        // Update freq
        keyToValFreq[key].second++;

        return val;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        // If key exists, update its value and frequency
        if (keyToValFreq.find(key) != keyToValFreq.end()) {
            keyToValFreq[key].first = value;
            get(key); // update frequency via get logic
            return;
        }

        // If cache is full, evict least frequently used key
        if (keyToValFreq.size() == cap) {
            int keyToEvict = freqToKeys[minFreq].back();
            freqToKeys[minFreq].pop_back();
            if (freqToKeys[minFreq].empty()) freqToKeys.erase(minFreq);

            keyToValFreq.erase(keyToEvict);
            keyToIter.erase(keyToEvict);
        }

        // Insert new key
        keyToValFreq[key] = {value, 1};
        freqToKeys[1].push_front(key);
        keyToIter[key] = freqToKeys[1].begin();
        minFreq = 1;
    }
};
