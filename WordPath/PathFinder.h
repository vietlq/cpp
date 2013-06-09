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
    bool operator()(const Iterator & it1, const Iterator & it2)
    {
        return (*it1 < *it2);
    }
};

class PathFinder
{
public:
    PathFinder();
    
    ~PathFinder();
    
private:
    // Node
    struct Node
    {
        Node(): _adjacent(0)
        {
            
        }
        
        ~Node()
        {
            
        }
        
        std::string _value;
        std::list<Node *> _adjacent;
    };
    typedef Node * NodePtr;
    // Node Container
    typedef std::list<NodePtr> word_container_t;
    typedef word_container_t::iterator word_iterator_t;
    typedef word_container_t::const_iterator word_const_iterator_t;
    // Container of Iterators to the Nodes
    typedef std::set<NodePtr, proxy_iterator_comp<NodePtr> > bst_t;
    typedef bst_t::iterator bst_iterator_t;
    typedef bst_t::const_iterator bst_const_iterator_t;
};

#endif /* defined(__WordPath__PathFinder__) */
