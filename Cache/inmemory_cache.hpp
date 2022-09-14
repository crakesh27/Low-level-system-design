//
//  inmemory_cache.hpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#ifndef inmemory_cache_hpp
#define inmemory_cache_hpp

#include "storage.hpp"
#include "eviction_policy.hpp"

class Cache{

    private:
    Storage storage;
    EvictionPolicy *evictionPolicy;

    public:
    Cache(Storage storage, EvictionPolicy *evictionPolicy);

    void put(int key, int value);

    int get(int key);

};

#endif /* inmemory_cache_hpp */
