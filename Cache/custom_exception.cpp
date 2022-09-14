//
//  custom_exception.cpp
//  Cache
//
//  Created by Rakesh Chinthakrindi on 05/08/22.
//

#include "custom_exception.hpp"

string StorageFullException::what (){
    return "Storage is full";
}

string NotFoundException::what (){
    return "key not found";
}
