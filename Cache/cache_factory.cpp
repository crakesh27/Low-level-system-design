//
//  cache_factory.cpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 06/08/22.
//

#include "cache_factory.hpp"

Cache* CacheFactory::getLRUCache(){
    Storage storage(2);
    EvictionPolicy *evictionPolicy = new LRUEvictionPolicy();
    return new Cache(storage, evictionPolicy);
}
