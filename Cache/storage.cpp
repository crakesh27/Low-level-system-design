//
//  storage.cpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#include "storage.hpp"
#include "custom_exception.hpp"

Storage::Storage(int capacity){
    this->capacity = capacity;
}

void Storage::putKey(int key, int value){
    if(store.size()==capacity && store.find(key)==store.end())
        throw StorageFullException();
    store[key] = value;
}

void Storage::removeKey(int key){
    if(store.find(key) == store.end())
        throw NotFoundException();
    store.erase(key);
}

int Storage::getValue(int key){
    if(store.find(key) == store.end())
        throw NotFoundException();
    return store.at(key);
}
