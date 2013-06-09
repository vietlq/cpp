//
//  PathFinder.h
//  WordPath
//
//  Created by Le Quoc Viet on 9/6/13.
//
//

#ifndef __WordPath__PathFinder__
#define __WordPath__PathFinder__

#include <iostream>
#include <set>
#include <list>
#include <string>
#include <queue>

bool are_adjacent(const std::string & s1, const std::string & s2);

template<typename Iterator>
struct proxy_iterator_comp
{
    bool operator()(const Iterator & it1, const Iterator & it2) const
    {
        return (*it1 < *it2);
    }
};

class PathFinder
{
public:
    PathFinder();
    
    ~PathFinder();
    
    bool empty() const;
    
    size_t size() const;
    
    void add(const std::string & word);
    
    void remove(const std::string & word);
    
    bool contains(const std::string & word) const;
    
private:
    // Node & pointer forward declaration
    struct Node;
    typedef Node * NodePtr;
    // Node Container
    typedef std::list<NodePtr> word_container_t;
    typedef word_container_t::iterator word_iterator_t;
    typedef word_container_t::const_iterator word_const_iterator_t;
    // Container of Iterators to the Nodes
    typedef std::set<NodePtr, proxy_iterator_comp<NodePtr> > bst_t;
    typedef bst_t::iterator bst_iterator_t;
    typedef bst_t::const_iterator bst_const_iterator_t;
    // The Node class
    struct Node
    {
        Node(): _adjacent(0)
        {
            
        }
        
        ~Node()
        {
            
        }
        
        bool operator<(const Node & rhs)
        {
            return (_value < rhs._value);
        }
        
        std::string _value;
        word_container_t _adjacent;
    };
    //
    NodePtr _pRoot;
    bst_t _bstNodes;
    std::queue<NodePtr> _queueRefWords;
};

#endif /* defined(__WordPath__PathFinder__) */
