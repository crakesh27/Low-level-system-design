//
//  cache_factory.hpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 06/08/22.
//

#ifndef cache_factory_hpp
#define cache_factory_hpp

#include "storage.hpp"
#include "inmemory_cache.hpp"
#include "lru_eviction_policy.hpp"

class CacheFactory{
public:
    static Cache* getLRUCache();
};

#endif /* cache_factory_hpp */
