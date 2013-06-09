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
    // Node
    struct Node;
    typedef Node * NodePtr;
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
        std::list<NodePtr> _adjacent;
    };
    // Node Container
    typedef std::list<NodePtr> word_container_t;
    typedef word_container_t::iterator word_iterator_t;
    typedef word_container_t::const_iterator word_const_iterator_t;
    // Container of Iterators to the Nodes
    typedef std::set<NodePtr, proxy_iterator_comp<NodePtr> > bst_t;
    typedef bst_t::iterator bst_iterator_t;
    typedef bst_t::const_iterator bst_const_iterator_t;
    //
    NodePtr _pNode;
    bst_t _bstNodes;
};

#endif /* defined(__WordPath__PathFinder__) */
