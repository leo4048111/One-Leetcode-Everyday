// https://leetcode.cn/problems/lru-cache/description/?envType=daily-question&envId=2023-09-24

class LRUCache{
public:
int capacity_;
int size_{0};
map<int, list<tuple<int, int>>::iterator> data_;
list<tuple<int, int>> keys_;


LRUCache(int capacity) {
    capacity_ = capacity;
}

int get(int key) {
    if(data_.find(key) == data_.end()) {
        return -1;
    }

    auto it = data_[key];

    keys_.splice(keys_.begin(), keys_, it);

    return get<1>(*it);
}

 void put(int key, int value) {
    if(data_.find(key) != data_.end()) {
        auto it = data_[key];
        *it = {key, value};
        keys_.splice(keys_.begin(), keys_, it);
    } else if(size_ >= capacity_) {
        auto k2move = get<0>(keys_.back());
        data_.erase(k2move);
        keys_.pop_back();
        keys_.push_front({key, value});
        data_[key] = keys_.begin();
    } else {
        keys_.push_front({key, value});
        data_[key] = keys_.begin();
        size_++;
    }
}};