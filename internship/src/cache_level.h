#ifndef CACHE_LEVEL_H
#define CACHE_LEVEL_H

#include <unordered_map>
#include <list>
#include <string>

class CacheLevel {
public:
    CacheLevel(int size, const std::string& policy);
    std::string get(const std::string& key);
    void put(const std::string& key, const std::string& value);
    void display();

private:
    int size;
    std::string policy;
    std::unordered_map<std::string, std::pair<std::string, int>> cache;  // key -> {value, frequency}
    std::list<std::string> access_order;  // For LRU
    std::unordered_map<std::string, int> frequency;  // For LFU
    void evict();
};

#endif
