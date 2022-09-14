//
//  main.cpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#include <iostream>
#include <gtest/gtest.h>
#include "cache_factory.hpp"
#include "storage.hpp"
#include "inmemory_cache.hpp"
#include "lru_eviction_policy.hpp"
#include "custom_exception.hpp"

using namespace std;


int main(int argc, char **argv) {
    // insert code here...

    testing::InitGoogleTest(&argc, argv);
    
    Cache *cache = CacheFactory::getLRUCache();
    
    cache->put(2,2);
    cache->put(1,1);
    cache->put(2,2);
    cache->put(3,3);
    cache->put(3,3);
    cache->put(3,3);
    
    assert (cache->get(3)==3);
    assert (cache->get(2)==2);
    
    cout<<cache->get(3)<<endl;
    cout<<cache->get(2)<<endl;
   
    return RUN_ALL_TESTS();
}
