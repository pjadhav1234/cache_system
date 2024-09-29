#ifndef MULTI_LEVEL_CACHE_H
#define MULTI_LEVEL_CACHE_H

#include "cache_level.h"
#include <vector>

class MultiLevelCache {
public:
    void addCacheLevel(int size, const std::string& policy);
    std::string get(const std::string& key);
    void put(const std::string& key, const std::string& value);
    void displayCache();

private:
    std::vector<CacheLevel> levels;
};

#endif
