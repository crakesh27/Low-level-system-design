//
//  lru_eviction_policy.cpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#include "lru_eviction_policy.hpp"

int LRUEvictionPolicy::evictKey(){
    
    int last = dq.back();
    dq.pop_back();
    ma.erase(last);
    
    return last;
}

void LRUEvictionPolicy::keyAccessed(int key){
    if(ma.find(key)!=ma.end()){
        dq.erase(ma[key]);
    }
    
    dq.push_front(key);
    ma[key] = dq.begin();
}


