#include <bits/stdc++.h>
using namespace std;

ifstream fin("graf.in");
vector<vector<int>> graph;
int n,m,s;
vector<int> viz, dist;
vector<int> componenta;
vector<vector<int>> componente;
queue<int> q;
int max_distance;

// facem o parcurgere bfs din nodul s pentru a determina ecc (s)
void bfs(int node){
    q.push(node);
    viz[node]=1;
    dist[node]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(int i=0;i<graph[x].size();i++){
            if(viz[graph[x][i]]==0){
                viz[graph[x][i]]=1;
                dist[graph[x][i]]=dist[x]+1;
                max_distance=max(max_distance, dist[graph[x][i]]);
                q.push(graph[x][i]);
            }
        }
    }

}


void dfs(int x){
    viz[x]=1;
    componenta.push_back(x);
    // nodurile accesibile dintr-un nod x fac parte din cc al lui x
    for(int i=0;i<graph[x].size();i++){
        if(viz[graph[x][i]]==0){
            dfs(graph[x][i]);
        }

    }
}

int main() {

    fin>>n>>m;
    graph.resize(n+1);
    viz.resize(n+1);
    dist.resize(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        f>>x>>y;
        // constructie lista de adiacenta 
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    fin>>s;
    for(int i=1;i<=n;i++){
        if(viz[i]==0){
            dfs(i);
            // dupa ce am vizitat un nod, adaugam componenta acestuia la lista cu toate componentele
            componente.push_back(componenta);
            componenta.clear();

        }
    }
    
    for(int i=0;i<componente.size()-1;i++){
        cout<<componente[i][0]<<" - "<<componente[i+1][0]<<"\n";
        // adaug o muchie intre fiecare 2 comp conexe
        graph[componente[i][0]].push_back(componente[i+1][0]);
        graph[componente[i+1][0]].push_back(componente[i][0]);
    }

    for(int i=1;i<=n;i++){
        viz[i]=0;
    }
    bfs(s);
    cout<<"\n"<<max_distance;



    return 0;
}
