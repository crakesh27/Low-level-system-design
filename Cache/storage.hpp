//
//  storage.hpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#ifndef storage_hpp
#define storage_hpp

#include <iostream>
#include <unordered_map>
using namespace std;

class Storage{

    private:
    unordered_map<int, int> store;
    int capacity;

    public:

    Storage(){};

    Storage(int capacity);

    void putKey(int key, int value);

    void removeKey(int key);

    int getValue(int key);

};

#endif /* storage_hpp */
