//
//  PathFinder.cpp
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#include "PathFinder.h"

PathFinder::PathFinder(): _pNode(0)
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
    _bstNodes.insert(pNode);
    
    _pNode = (NULL == _pNode) ? pNode : _pNode;
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
