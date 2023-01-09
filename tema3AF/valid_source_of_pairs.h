class Solution {
public:

    unordered_map<int,vector<int>> adj;
    unordered_map<int, int> in;
    unordered_map<int, int> out;

    void find(int node,vector<vector<int>>&ans)
    {
        while(adj[node].size()!=0)
        {
            auto &nod=adj[node];
            int next_node=adj[node].back();
            adj[node].pop_back();
            find(next_node,ans);
            ans.push_back({node,next_node});
        }
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {


        for (int i = 0; i < pairs.size(); i++) {
            int u = pairs[i][0], v = pairs[i][1];
            in[v]++;
            out[u]++;
            adj[u].push_back(v);
        }

        // gasim nodul de start
        int start = -1;
        for (auto& p : adj) {
            int i = p.first;
            if (out[i] - in[i] == 1) start = i;
        }

        if (start == -1) {
            // daca graful este un circuit eulerian => putem porni din orice nod
            start=pairs[0][0];
        }

        vector<vector<int>>ans;
        find(start,ans);
        reverse(ans.begin(),ans.end());

        return ans;
    }
};