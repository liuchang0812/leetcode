class Solution {
public:
    int finished;
    vector<vector<int>> graph;
    map<int, bool> visited;
    int total;
    vector<string> answer;
    
    
    void init( vector<pair<string, string>> &tickets)
    {
        sort(tickets.begin(), tickets.end());
        finished = false;
        total = tickets.size();
        graph.resize(total);
        

        for (int i=0; i<total; ++i)
            for (int j=i+1; j<total; ++j)
            {
                pair<string, string> p1, p2;
                p1 = tickets[i];
                p2 = tickets[j];
                
                if (p1.second == p2.first)
                    (graph[i]).push_back(j);
                
                if (p2.second == p1.first)
                    (graph[j]).push_back(i);
            }
    }
    
    void contructAns(vector<int>& cur_ans, vector<string> &ans, vector<pair<string, string>> tickets)
    {
        ans.clear();
        
        for (int i=0; i<cur_ans.size(); ++i)
        {
            ans.push_back(tickets[cur_ans[i]].first);
        }
        
        ans.push_back(tickets[cur_ans.back()].second);
    }

    void dfs(int cur, int total, vector<int>& cur_ans, const vector<pair<string, string>> tickets)
    {
        if (cur == total)
        {
            finished = true;
            contructAns(cur_ans, answer, tickets);
            return;
        }
        //cout << "debug " << endl;
        if (!finished)
        {
            if (!cur_ans.empty())
            {
            int preNode = cur_ans.back();
        
            //cout << "preNode " << preNode << " cur " << cur << endl;
            for (auto nextNode:graph[preNode])
            {
                if (!visited[nextNode])
                {
                    visited[nextNode] = true;
                    cur_ans.push_back(nextNode);
                
                
                    dfs(cur+1, total, cur_ans, tickets);
                
                    visited[nextNode] = false;
                    cur_ans.pop_back();
                }
            }
            }
            else
            {
                for (int i=0; i<total; ++i)
                {
                    if (tickets[i].first == "JFK")
                    {
                    visited[i] = true;
                    cur_ans.push_back(i);
                    
                    dfs(cur+1, total, cur_ans, tickets);
                    
                    visited[i] = false;
                    cur_ans.pop_back();
                    }
                }
            }
        }
    }
    

    
    
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
        init(tickets);
        
        cout << "init ok" << endl;
        vector<int> cur_ans;
    
        dfs(0, total, cur_ans, tickets);
        return answer;
        
    }
};
