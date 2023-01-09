#include <bits/stdc++.h>

using namespace std;
ifstream fin("catun.in");
ofstream fout("catun.out");

vector<vector<pair<int, int>>> lista; //vector de vectori de tipul pereche unde perechea e <nod, dist>
vector<int> distanta;
vector<int> fortareata,radacina;
priority_queue<pair<int, int>> pq;

int main()
{
    int n,m,k,x,y,z;
    fin>>n>>m>>k;
    lista.resize(n+1);
    distanta.assign(n+1, 100000);
    fortareata.resize(k);
    radacina.resize(n+1);

    for(int i=0;i<k;i++)
    {
        fin>>x;
        fortareata[i]=x;
        radacina[x]=x;
        distanta[x]=0;
        pq.push(make_pair(0,x));
    }

    for(int i = 0; i < m; i++)
    {
        fin>>x>>y>>z;
        //pt fiecare nod am o lista de vecini, in pereche cu distanta lor
        lista[x].push_back(make_pair(y, z));
        lista[y].push_back(make_pair(x, z));
    }
    //aplicam alg lui djikstra
    int nod,vecin;
    //parcurgem coada si extargem la fiecare pas elementul cu costul cel mai mic, ii vizitam vecinii
    //si daca e cazul modificam dist
    while(pq.empty()==0)
    {
        //iau nodul cu prioritatea cea mai mare
        nod = pq.top().second;
        pq.pop();
        for(int i=0;i<lista[nod].size();i++)
        {
            vecin= lista[nod][i].first;
            if(distanta[vecin] > (distanta[nod] + lista[nod][i].second) )
            {
                //vedem daca distanta pana la nodul vecin e mai mica decat cea
                //anterioara si o actualizam, adaugand elementul gasit in coada
                // pentru a-i verifica vecinii ulterior
                distanta[vecin] = distanta[nod] +lista[nod][i].second ;
                radacina[vecin]=radacina[nod];
                pq.push(make_pair(-distanta[vecin],vecin));
            }
            if(distanta[vecin] == (distanta[nod] + lista[nod][i].second))
            {
                if( radacina[nod] < radacina[vecin])
                {
                    radacina[vecin]=radacina[nod];
                    pq.push(make_pair(-distanta[vecin],vecin));
                }
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(radacina[i]==i) fout<<0<<' ';
        else fout<<radacina[i]<<' ';
    }
    return 0;
}
