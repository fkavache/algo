
class LRUCache {
private:
    unordered_map<int, int> lru;
    unordered_map<int, int> lru_time;
    int now, sz;
    int getLeast();
public:
    LRUCache(int capacity);
    int get(int key);
    void set(int key, int value);
};

LRUCache::LRUCache(int capacity) {
    lru.clear();
    lru_time.clear();

    now  = 0;
    sz = capacity;
}

int LRUCache::get(int key) {
    int result = -1;

    now++;
    if (lru.find(key) != lru.end()) {
        lru_time[key] = now;
        result = lru[key];
    }

    return result;
}

int LRUCache::getLeast() {
    int mn = INT_MAX;
    int key = -1;
    for (auto const &e: lru_time) {
        if (e.second < mn) {
            mn = e.second;
            key = e.first;
        }
    }

    return key;
}

void LRUCache::set(int key, int value) {
    now++;
    lru[key] = value;
    lru_time[key] = now;
    if (lru.size() > sz) {
        int pkey = getLeast();
        lru.erase(pkey);
        lru_time.erase(pkey);
    }
}

int main() {
    LRUCache lru(2);

    lru.set(1, 10);
    lru.set(5, 12);

    cout << lru.get(5)  << endl;
    cout << lru.get(1)  << endl;
    cout << lru.get(10) << endl;

    lru.set(6, 14);

    cout << lru.get(5) << endl;

    return 0;
}