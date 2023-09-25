// https://leetcode.cn/problems/lfu-cache/description/?envType=daily-question&envId=2023-09-25

class LFUCache {
public:
    int capacity_{0};
    size_t size_{0};
    size_t minFreq{1};
    map<size_t, list<tuple<int, int, size_t>>> freqs_;
    map<int, list<tuple<int, int, size_t>>::iterator> keys_;
    LFUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if(!keys_.count(key)) return -1;

        auto& [k, v, freq] = *keys_[key];

        freqs_[freq + 1].splice(freqs_[freq + 1].end(), freqs_[freq], keys_[key]);

        if(minFreq == freq && freqs_[minFreq].empty()) minFreq++;
        freq++;
        return v;
    }
    
    void put(int key, int value) {
        if (get(key) != -1) {
            std::get<1>(*keys_[key]) = value;
        } else {
            if(size_ >= capacity_) {
                keys_.erase(std::get<0>(freqs_[minFreq].front()));
                freqs_[minFreq].pop_front();
            } else {
                size_++;
            }

            
            // keys_[key] = freqs_[minFreq = 1].emplace(freqs_[1].end(), key, value, 1);
            freqs_[minFreq = 1].push_back({key, value, 1});
            keys_[key] = prev(freqs_[1].end());
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */