//
//  Dictionary.cpp
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#include "Dictionary.h"

Dictionary::Dictionary()
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

bool Dictionary::contains(const std::string & word) const
{
    return (_words.end() != _words.find(word));
}

void Dictionary::remove(const std::string & word)
{
    word_iterator_t it = _words.find(word);
    
    if(_words.end() != it)
    {
        _words.erase(word);
    }
}
