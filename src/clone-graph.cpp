/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // solve this problem by two steps:
        // 1. copy nodes
        // 2. copy edges
        if (node == NULL) return NULL;
        
        map<UndirectedGraphNode*, UndirectedGraphNode*> node2clone;
        map<UndirectedGraphNode*, bool> visited;
        
        
        queue<UndirectedGraphNode*> Q;
        Q.push(node);
        visited[node] = true;
        
        while (!Q.empty())
        {
            UndirectedGraphNode* cur = Q.front(); Q.pop();
            
            UndirectedGraphNode* copy = new UndirectedGraphNode(cur->label);
            
            node2clone[cur] = copy;
            
            for (auto i: cur->neighbors)
            {
                if (!visited[i])
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
        }
        visited.clear();
        Q.push(node);
        visited[node] = true;
        
        while (!Q.empty())
        {
            UndirectedGraphNode* cur = Q.front(); Q.pop();
            
            UndirectedGraphNode* copy = node2clone[cur];
            
            for (auto i: cur->neighbors)
            {
                copy->neighbors.push_back(node2clone[i]);
                
                if (!visited[i])
                {
                    Q.push(i);
                    visited[i] = true;
                }
            }
        }
        return node2clone[node];
    }
};
