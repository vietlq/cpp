#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string.h>

struct Node
{
    int value;
    int degree;
    Node * parent;
    Node * farAncestor;
    Node * veryFarAncestor;
};

typedef std::map<int, Node *> map_nodes_t;
typedef map_nodes_t::iterator map_nodes_it;
typedef std::map<int, std::list<int> > map_paths_t;
typedef map_paths_t::iterator map_paths_it;
typedef std::list<int> list_values_t;
typedef list_values_t::iterator list_values_it;

enum Actions
{
    ACT_NONE = -1,
    ACT_ADD_LEAF = 0,
    ACT_DEL_LEAF = 1,
    ACT_QUERY_ANCESTOR = 2,
    ACT_MAX
};

class NodeProcessor
{
public:
    //
    static const int MIN_LOOKUP_BASE_1 = 32;
    //
    static const int MIN_LOOKUP_BASE_2 = 512;
    
    //
    NodeProcessor(int fastLookUpBase_ = 100, int veryFastLookUpBase_ = 1000);
    
    //
    ~NodeProcessor();
    
    //
    void reset();
    
    //
    void setInitCount(int nodeCount);
    
    //
    void setRoot(int nodeValue);
    
    //
    void addPair(int value1, int value2);
    
    //
    void addLeaf(int parentValue, int nodeValue);
    
    //
    void deleteLeaf(int nodeValue);
    
    //
    int queryAncestor(int nodeValue, int k);
private:
    map_paths_t mapUndecidedNodes;
    map_nodes_t mapOfNodes;
    Node * pRoot;
    int initCount;
    int fastLookUpBase;
    int veryFastLookUpBase;
};

void process_input(std::istream & istr, std::ostream & ostr)
{
    NodeProcessor nodeProcessor;
    int T;
    
    istr >> T;
    
    for(int treeIdx = 0; treeIdx < T; ++treeIdx)
    {
        int P, Q, value1, value2, X, Y, K, C;
        
        istr >> P;
        
        for(int lineIdx = 0; lineIdx < P; ++lineIdx)
        {
            istr >> value1 >> value2;
            
            if(0 == value1)
            {
                nodeProcessor.setRoot(value2);
            }
            else if(0 == value2)
            {
                nodeProcessor.setRoot(value1);
            }
            else
            {
                nodeProcessor.addPair(value1, value2);
            }
        }
        
        istr >> Q;
        
        for(int queryIdx = 0; queryIdx < Q; ++queryIdx)
        {
            istr >> C;
            switch (C) {
                case ACT_ADD_LEAF:
                    istr >> X >> Y;
                    nodeProcessor.addLeaf(X, Y);
                    break;
                case ACT_DEL_LEAF:
                    istr >> X;
                    nodeProcessor.deleteLeaf(X);
                    break;
                case ACT_QUERY_ANCESTOR:
                    istr >> X >> K;
                    ostr << nodeProcessor.queryAncestor(X, K) << std::endl;
                    break;
                default:
                    break;
            }
        }
        
        nodeProcessor.reset();
    }
}

int main()
{
    process_input(std::cin, std::cout);
    //std::ifstream istr("/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/test01.txt");
    //process_input(istr, std::cout);
    
    return 0;
}

NodeProcessor::NodeProcessor(int fastLookUpBase_, int veryFastLookUpBase_):
pRoot(NULL), initCount(0),
fastLookUpBase(fastLookUpBase_), veryFastLookUpBase(veryFastLookUpBase_)
{
    if(fastLookUpBase < MIN_LOOKUP_BASE_1)
    {
        fastLookUpBase = MIN_LOOKUP_BASE_1;
    }
    
    if(veryFastLookUpBase < MIN_LOOKUP_BASE_2)
    {
        veryFastLookUpBase = MIN_LOOKUP_BASE_2;
    }
}

NodeProcessor::~NodeProcessor()
{
    reset();
}

void NodeProcessor::reset()
{
    Node * pNode = NULL;
    
    if(mapOfNodes.size())
    {
        for(map_nodes_it it = mapOfNodes.begin(); mapOfNodes.end() != it; ++it)
        {
            pNode = it->second;
            if(NULL == pNode) continue;
            delete pNode;
            pNode = NULL;
        }
        
        mapOfNodes.clear();
    }
    
    pRoot = NULL;
    
    if(mapUndecidedNodes.size())
    {
        mapUndecidedNodes.clear();
        
        initCount = 0;
    }
}

void NodeProcessor::setInitCount(int nodeCount)
{
    if(nodeCount > 0) initCount = nodeCount;
    
    initCount = nodeCount;
}

void NodeProcessor::setRoot(int nodeValue)
{
    pRoot = new Node;
    pRoot->parent = NULL;
    pRoot->farAncestor = NULL;
    pRoot->veryFarAncestor = NULL;
    pRoot->degree = 0;
    pRoot->value = nodeValue;
    
    mapOfNodes[nodeValue] = pRoot;
}

void NodeProcessor::addPair(int value1, int value2)
{
    map_nodes_it it1, it2, it;
    const map_nodes_it end = mapOfNodes.end();
    
    it1 = mapOfNodes.find(value1);
    it2 = mapOfNodes.find(value2);
    
    if((end == it1) && (end == it2))
    {
        mapUndecidedNodes[value1].push_back(value2);
        mapUndecidedNodes[value2].push_back(value1);
        return;
    }
    
    // Either value1 or value2 is found and the remaining is not
    int nodeValue;
    if(end == it1)
    {
        // If value1 is not found
        addLeaf(value2, value1);
        it = mapOfNodes.find(value1);
        nodeValue = value1;
    }
    else
    {
        // If value2 is not found
        addLeaf(value1, value2);
        it = mapOfNodes.find(value2);
        nodeValue = value2;
    }
    
    std::list<int> listOfValues;
    std::map<int, char> visited;
    listOfValues.push_back(nodeValue);
    
    while(listOfValues.size())
    {
        int currNodeValue = listOfValues.front();
        listOfValues.pop_front();
        
        if(visited.end() != visited.find(currNodeValue)) return;
        visited[currNodeValue] = 1;
        
        const list_values_t & unMappedNodes = mapUndecidedNodes[nodeValue];
        list_values_t::const_iterator tempIt = unMappedNodes.begin();
        const list_values_t::const_iterator tempEnd = unMappedNodes.end();
        
        for(; tempIt != tempEnd; ++tempIt)
        {
            listOfValues.push_back(*tempIt);
            addLeaf(currNodeValue, *tempIt);
        }
        
        mapUndecidedNodes.erase(currNodeValue);
    }
}

void NodeProcessor::addLeaf(int parentValue, int nodeValue)
{
    map_nodes_it it = mapOfNodes.find(parentValue);
    if(mapOfNodes.end() == it) return;
    
    Node * pNode = new Node;
    pNode->value = nodeValue;
    pNode->parent = it->second;
    pNode->degree = pNode->parent->degree + 1;
    
    //
    if(pNode->degree <= veryFastLookUpBase)
    {
        pNode->veryFarAncestor = pRoot;
    }
    else if(1 == (pNode->degree % veryFastLookUpBase))
    {
        pNode->veryFarAncestor = pNode->parent;
    }
    else
    {
        pNode->veryFarAncestor = pNode->parent->veryFarAncestor;
    }
    
    //
    if(pNode->degree <= fastLookUpBase)
    {
        pNode->farAncestor = pRoot;
    }
    else if(1 == (pNode->degree % fastLookUpBase))
    {
        pNode->farAncestor = pNode->parent;
    }
    else
    {
        pNode->farAncestor = pNode->parent->farAncestor;
    }
    
    mapOfNodes[nodeValue] = pNode;
}

void NodeProcessor::deleteLeaf(int nodeValue)
{
    map_nodes_it it = mapOfNodes.find(nodeValue);
    if(mapOfNodes.end() == it) return;
    
    Node * pNode = it->second;
    mapOfNodes.erase(it);
    delete pNode;
    pNode = NULL;
}

int NodeProcessor::queryAncestor(int nodeValue, int k)
{
    map_nodes_it it = mapOfNodes.find(nodeValue);
    // If the node does not exist, return 0
    if(mapOfNodes.end() == it) return 0;
    
    Node * pNode = it->second;
    
    // If the degree of the node is < k, return 0
    if(pNode->degree < k)return 0;
    
    if(pNode->degree == k)
    {
        if(NULL == pRoot) return 0;
        return pRoot->value;
    }
    
    Node * pAncestorNode = pNode->parent;
    --k;
    int temp;
    while(k > 0)
    {
        if(k >= veryFastLookUpBase)
        {
            temp = pAncestorNode->degree % veryFastLookUpBase;
            if(0 != temp)
            {
                k -= temp;
            }
            else
            {
                k -= veryFastLookUpBase;
            }
            pAncestorNode = pAncestorNode->veryFarAncestor;
        }
        else if(k >= fastLookUpBase)
        {
            temp = pAncestorNode->degree % fastLookUpBase;
            if(0 != temp)
            {
                k -= temp;
            }
            else
            {
                k -= fastLookUpBase;
            }
            pAncestorNode = pAncestorNode->farAncestor;
        }
        else
        {
            pAncestorNode = pAncestorNode->parent;
            --k;
        }
    }
    
    return pAncestorNode->value;
}
