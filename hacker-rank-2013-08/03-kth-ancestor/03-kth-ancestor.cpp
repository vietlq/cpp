#include <iostream>
#include <fstream>
#include <map>
#include <list>
#include <string.h>

struct Node
{
    Node * parent;
    int degree;
};

typedef std::map<int, Node *> map_nodes_t;
typedef std::list<Node *> node_container_t;

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
    NodeProcessor();
    
    //
    ~NodeProcessor();
    
    //
    void addLeaf(int parentValue, int nodeValue);
    
    //
    void deleteLeaf(int nodeValue);
    
    //
    int queryAncestor(int nodeValue, int k);
private:
    map_nodes_t mapOfNodes;
    node_container_t nodes;
};

void process_input(std::istream & istr, std::ostream & ostr)
{
    NodeProcessor nodeProcessor;
}

int main()
{
    process_input(std::cin, std::cout);
    //std::ifstream istr("/Users/vietlq/projects/viet-github-cpp/hacker-rank-2013-08/02-a-journey-to-the-moon/test01.txt");
    //process_input(istr, std::cout);
    
    return 0;
}
