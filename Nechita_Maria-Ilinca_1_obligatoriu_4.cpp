#include <bits/stdc++.h>
#define maxi 200001

using namespace std;

ifstream fin("ctc.in");
ofstream fout("ctc.out");

list<int>G[maxi],Gt[maxi],sol[maxi];
stack <int> S;
int n,m,nrctc;
bool viz[maxi];

//facem o parcurgere dfs pe graf
//vizitam toate nodurile copilului unui vf si marcam nodurile vizitate
// Daca un varf duce la unul deja vizitat, atunci il adaugam in stiva.
void dfs(int i)
{
    list<int>::iterator it;
    viz[i]=true;
    for(it=G[i].begin();it!=G[i].end();++it)
        if(!viz[*it])
            dfs(*it);
    S.push(i);
}


void dfs_transpus(int i)
{
    list<int>::iterator it;
    viz[i]=false;
    sol[nrctc].push_back(i);
    for(it=Gt[i].begin();it!=Gt[i].end();++it)
        if(viz[*it])
            dfs_transpus(*it);
}

int main()
{	int i,x,y;
    fin>>n>>m;

    for(i=1;i<=m;i++)
    {
        fin>>x>>y;
        G[x].push_back(y);
        // construim graful transpus lui G
        Gt[y].push_back(x);
    }
    for(i=1;i<=n;i++)
        if(!viz[i])
            dfs(i);

//incepem de la vf de sus al stivei. Traversam prin toate nodurile copil ale sale.
//Odată ce varful deja vizitat este atins, se formează o componenta tare conexa.
    while(!S.empty()) {
        int nod = S.top();
        if (viz[nod] == 1) {
            nrctc++;
            dfs_transpus(nod);
        }
        S.pop();
    }
    fout<<nrctc<<'\n';
    list<int>::iterator it;
    for(i=1;i<=nrctc;i++)
    {
        for(it=sol[i].begin();it!=sol[i].end();it++)
            fout<<*it<<' ';
        fout<<'\n';
    }
    return 0;
}