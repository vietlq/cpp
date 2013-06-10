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
    
    bool contains(const std::string & word) const;
    
    void remove(const std::string & word);
    
private:
    typedef std::set<std::string> word_container_t;
    typedef word_container_t::iterator word_iterator_t;
    typedef word_container_t::const_iterator word_const_iterator_t;
    
    std::set<std::string> _words;
};

#endif /* defined(__WordPath__Dictionary__) */
