//
//  Dictionary.cpp
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#include "Dictionary.h"

Dictionary::Dictionary(): _empty(true), _size(0)
{
    
}

Dictionary::~Dictionary()
{
    
}

bool Dictionary::empty() const
{
    return _words.empty();
}

void Dictionary::add(const std::string & word)
{
    _words.insert(word);
}

size_t Dictionary::size() const
{
    return _words.size();
}
