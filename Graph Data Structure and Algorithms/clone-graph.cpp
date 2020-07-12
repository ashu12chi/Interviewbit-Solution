/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
UndirectedGraphNode *Solution::cloneGraph(UndirectedGraphNode *node) {
    if(node == NULL)
        return node;
    UndirectedGraphNode* temp = new UndirectedGraphNode(node->label);
    for(int i=0;i<node->neighbors.size();i++)
    {
        temp->neighbors.push_back(cloneGraph(node->neighbors[i]));
    }
    return temp;
}
