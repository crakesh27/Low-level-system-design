//
//  eviction_policy.hpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#ifndef eviction_policy_hpp
#define eviction_policy_hpp


class EvictionPolicy{

    public:

    virtual int evictKey() = 0;
    virtual void keyAccessed(int key) = 0;

};

#endif /* eviction_policy_hpp */
