#include "cache_level.h"
#include <iostream>

CacheLevel::CacheLevel(int size, const std::string& policy) : size(size), policy(policy) {}

std::string CacheLevel::get(const std::string& key) {
    if (cache.find(key) != cache.end()) {
        // Update LRU or LFU access order
        if (policy == "LRU") {
            access_order.remove(key);
            access_order.push_back(key);
        } else if (policy == "LFU") {
            frequency[key]++;
        }
        return cache[key].first;
    }
    return "";  // Cache miss
}

void CacheLevel::put(const std::string& key, const std::string& value) {
    if (cache.size() >= size) {
        evict();  // Evict an entry before inserting a new one
    }
    cache[key] = {value, 1};
    if (policy == "LRU") {
        access_order.push_back(key);
    } else if (policy == "LFU") {
        frequency[key] = 1;
    }
}

void CacheLevel::evict() {
    std::string evict_key;
    if (policy == "LRU") {
        evict_key = access_order.front();
        access_order.pop_front();
    } else if (policy == "LFU") {
        int min_freq = INT_MAX;
        for (const auto& pair : frequency) {
            if (pair.second < min_freq) {
                min_freq = pair.second;
                evict_key = pair.first;
            }
        }
        frequency.erase(evict_key);
    }
    cache.erase(evict_key);
}

void CacheLevel::display() {
    for (const auto& pair : cache) {
        std::cout << pair.first << " -> " << pair.second.first << std::endl;
    }
}
