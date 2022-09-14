//
//  lru_eviction_policy.hpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#ifndef lru_eviction_policy_hpp
#define lru_eviction_policy_hpp

#include "eviction_policy.hpp"
#include <deque>
#include <unordered_map>

using namespace std;

class LRUEvictionPolicy: public EvictionPolicy{

    private:
    deque<int> dq;
    unordered_map<int, deque<int>::iterator> ma;

    public:
    LRUEvictionPolicy(){};

    int evictKey();
    void keyAccessed(int key);

};

#endif /* lru_eviction_policy_hpp */
