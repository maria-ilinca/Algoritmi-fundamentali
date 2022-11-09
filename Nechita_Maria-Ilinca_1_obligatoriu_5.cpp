#include <bits/stdc++.h>
#define maxi 10001
using namespace std;

ifstream fin ("graf.in");
ofstream fout("graf.out");

int n,m,pct;

vector <int> G[maxi];
int pcte_control[maxi];
int viz[maxi], dist[maxi];

// folosim parcurgerea bfs, utila in calculul distantei de la un nod la altul
void bfs(int node) {
    queue<int> Q;
    Q.push(node);
    viz[node]=1;
    dist[node] = 0;
    while(!Q.empty()) {
        int node = Q.front();
        Q.pop();
        for(auto neigh :G[node]) {
            if(viz[neigh] == 0) {
                Q.push(neigh);
                viz[neigh]=1;
                dist[neigh] = 1 + dist[node];
            }
        }
    }
}

int main()
{
    int x,y;
    fin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        fin>>x>>y;
        G[x].push_back(y);
        G[y].push_back(x);
    }

int ind=0,cn=n,nod=0;
    while(fin >> pct)
       pcte_control[ind++]=pct;
    ind --;
    bfs(1);
//pentru fiecare nod calculam distanta pana la cel mai apropiat punct de control
    for(int j=0;j<n;j++)
    {
        for (int i=0;i<ind;i++)
            if (dist[i] < cn and dist[i] != 0)
              cn = dist[x];
        fout << cn << " ";
    }
    return 0;
}