//
//  inmemory_cache.cpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#include "inmemory_cache.hpp"
#include "custom_exception.hpp"


Cache::Cache(Storage storage, EvictionPolicy *evictionPolicy){
    this->storage = storage;
    this->evictionPolicy = evictionPolicy;
}

void Cache::put(int key, int value){
    try {
        storage.putKey(key, value);
        evictionPolicy->keyAccessed(key);
        
    } catch (StorageFullException &error) {
        cout<<error.what()<<endl;
        
        int keyToEvict = evictionPolicy->evictKey();
        storage.removeKey(keyToEvict);
        
        storage.putKey(key, value);
        evictionPolicy->keyAccessed(key);
    }
    
}

int  Cache::get(int key){
    return storage.getValue(key);
}

