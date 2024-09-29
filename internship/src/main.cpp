#include "multi_level_cache.h"
#include <iostream>

int main() {
    MultiLevelCache cache;
    cache.addCacheLevel(3, "LRU");  // L1 cache
    cache.addCacheLevel(2, "LFU");  // L2 cache

    // Test case 1: Insertion
    cache.put("a", "apple");
    cache.put("b", "banana");
    cache.put("c", "cherry");
    cache.displayCache();  // Should display 3 items in L1 cache

    // Test case 2: Access and move
    std::cout << "Accessing 'a': " << cache.get("a") << std::endl;
    cache.displayCache();  // 'a' should move to the top in L1

    // Test case 3: Eviction
    cache.put("d", "date");
    cache.displayCache();  // Should evict according to LRU in L1

    return 0;
}
