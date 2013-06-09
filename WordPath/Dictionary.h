//
//  Dictionary.h
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#ifndef __WordPath__Dictionary__
#define __WordPath__Dictionary__

#include <iostream>
#include <string>
#include <set>

class Dictionary
{
public:
    Dictionary();
    
    ~Dictionary();
    
    bool empty() const;
    
    void add(const std::string & word);
    
    size_t size() const;
    
private:
    bool _empty;
    size_t _size;
    std::set<std::string> _words;
};

#endif /* defined(__WordPath__Dictionary__) */
