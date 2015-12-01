#include <vector>
#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    vector<int> visited;
    vector<int> pre;
    vector<vector<int> > ans;
    int farest_node;
    int dfs(const vector<vector<int> >& graph, int root, vector<int>& visited)
    {
        queue<int> Q;
        visited[root] = 1;
        queue<int> Deep;
        Deep.push(1);
        Q.push(root);
        pre[root] = -1;

        int max_deep = 0;

        while (!Q.empty())
        {
            int node = Q.front(); Q.pop();
            int deep = Deep.front(); Deep.pop();
            max_deep = max(deep, max_deep);
            visited[node] = 1;
            farest_node = node;
            ans[deep].push_back(node);

            for (int i:graph[node])
            {
                if (visited[i] == 0)
                {
                    pre[i] = node;
                    Q.push(i);
                    Deep.push(deep+1);
                }
            }
        }
        return max_deep;
    }
    vector<int> findMinHeightTrees(int n, vector<pair<int, int> >& edges) {
        vector<vector<int> > graph(n); 
        for (auto i:edges)
        {
            graph[i.first].push_back(i.second);
            graph[i.second].push_back(i.first);
        }
        ans.resize(n+1);
        pre.resize(n+1);
        visited.resize(n);

        fill(visited.begin(), visited.end(), 0);
        dfs(graph, 0, visited);

        ans.clear();
        ans.resize(n+1);
        
        fill(visited.begin(), visited.end(), 0);
        pre.resize(n+1);
        fill(pre.begin(), pre.end(), -1);
        int len = dfs(graph, farest_node, visited);

        vector<int> path;
        int p = farest_node;
        
        while (p != -1)
        {
            path.push_back(p);
            p = pre[p];
        }
        //path.push_back(p);

       vector<int> anss; 
        if (len % 2)
        {
            anss.push_back(path[len/2]);
            return anss;
        }
        else
        {
            anss.push_back(path[len/2-1]);
            anss.push_back(path[len/2]);
            return anss;
        }
        return vector<int>();
    }
};


int main()
{
    int n = 4;
    vector<pair<int, int> > edges;
    edges.push_back(make_pair(1, 0));
    edges.push_back(make_pair(1, 2));
    edges.push_back(make_pair(1, 3));
    Solution().findMinHeightTrees(n, edges);
 return 0;
}

