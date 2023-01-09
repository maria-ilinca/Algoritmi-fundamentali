typedef pair<int,double> pi;
typedef pair<double,int> pi1;
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end)
    {
        vector<vector<pi>> adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pi1,vector<pi1>> pq;
        pq.push({1.00,start}); //initial setam probabilitatea la 1
        vector<double> dist(n,0.00); //pastreaza distanta maxima
        dist[start]=1.00;
        while(!pq.empty())
        {
            double wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]) //pentru vecinii unui nod determinam muchia pentru care probabilitatea este maxima
            {
                if(dist[it.first]<dist[node]*it.second) //daca gasim o probabilitate mai mare, ii dam push in coada de prioritati
                {
                    dist[it.first]=dist[node]*it.second;
                    pq.push({dist[it.first],it.first});
                }
            }
        }
        return dist[end];
    }
};