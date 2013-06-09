//
//  PathFinder.cpp
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#include "PathFinder.h"

bool are_adjacent(const std::string & s1, const std::string & s2)
{
    if(s1.size() != s2.size())
    {
        return false;
    }
    
    if(s1.empty())
    {
        return false;
    }
    
    size_t diff = 0;
    
    for(size_t idx = 0; idx < s1.size(); ++idx)
    {
        diff += ((s1[idx] == s2[idx]) ? 0 : 1);
    }
    
    return (1 == diff);
}

PathFinder::PathFinder(): _pRoot(0)
{
}

PathFinder::~PathFinder()
{
    while(_bstNodes.size() > 0)
    {
        bst_iterator_t firstEle = _bstNodes.begin();
        delete *firstEle;
        _bstNodes.erase(firstEle);
    }
}

bool PathFinder::empty() const
{
    return _bstNodes.empty();
}

size_t PathFinder::size() const
{
    return _bstNodes.size();
}

void PathFinder::add(const std::string & word)
{
    std::string newWord(word);
    
    std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);
    
    if(contains(newWord))
    {
        return;
    }
    
    NodePtr pNode = new Node;
    pNode->_value = newWord;
    
    if(_bstNodes.empty())
    {
        _pRoot = pNode;
        _bstNodes.insert(pNode);
        return;
    }
    
    for(bst_iterator_t it = _bstNodes.begin(); it != _bstNodes.end(); ++it)
    {
        are_adjacent((*it)->_value, newWord);
        pNode->_adjacent.push_back(*it);
        (*it)->_adjacent.push_back(pNode);
    }
    
    _bstNodes.insert(pNode);
}

void PathFinder::remove(const std::string & word)
{
    std::string newWord(word);
    
    std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);
    
    Node node;
    node._value = newWord;
    _bstNodes.erase(&node);
}

bool PathFinder::contains(const std::string & word) const
{
    std::string newWord(word);
    
    std::transform(newWord.begin(), newWord.end(), newWord.begin(), ::tolower);
    
    Node node;
    node._value = newWord;
    return (_bstNodes.end() != _bstNodes.find(&node));
}
