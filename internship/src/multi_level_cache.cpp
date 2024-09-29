#include "multi_level_cache.h"
#include <iostream>

void MultiLevelCache::addCacheLevel(int size, const std::string& policy) {
    levels.emplace_back(size, policy);
}

std::string MultiLevelCache::get(const std::string& key) {
    for (CacheLevel& level : levels) {
        std::string value = level.get(key);
        if (!value.empty()) {
            return value;
        }
    }
    return "Cache miss";
}

void MultiLevelCache::put(const std::string& key, const std::string& value) {
    levels[0].put(key, value);  // Always insert in L1
}

void MultiLevelCache::displayCache() {
    for (int i = 0; i < levels.size(); ++i) {
        std::cout << "Cache Level " << i + 1 << ":\n";
        levels[i].display();
    }
}
