//
//  custom_exception.hpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#ifndef custom_exception_hpp
#define custom_exception_hpp

#include <iostream>
using namespace std;

class StorageFullException : public exception {
    public:
    string what ();
};

class NotFoundException : public exception {
    public:
    string what ();
};

#endif /* custom_exception_hpp */
