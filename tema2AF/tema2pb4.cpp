#include <bits/stdc++.h>

#define MIN -1000000001

using namespace std;

ifstream in("easygraph.in");
ofstream out("easygraph.out");

vector<vector <long long>> l;
vector<long long> cost, ok; //ok marcheaza daca in nodul curent pot ajunge cu o muchie
vector<bool> viz;

long long n, m, t, x, y;
long long rez; //in rez calculez costul maxim

void dfs(long long nod)
{
    viz[nod] = 1;
    long long r = 0;
    for(long long i=0; i<l[nod].size(); i++)
    {
        long long nodNou = l[nod][i];
        if(viz[nodNou] == 0)
            dfs(l[nod][i]);
        if(r < cost[nodNou])
            r = cost[nodNou];
        //dupa calcularea distantei pana la vecinul curent
        // verficam daca a fost obtinut un cost minim pentru un vecin
        //daca da, actualizez cu costul calculat pt vecin la care adaug
        //costul nodului
    }
    cost[nod] += r;
    if(rez < cost[nod])
        rez = cost[nod];
}

int main()
{
    in>>t;

    for(long long test=1; test<=t; test++)
    {
        l.clear();
        viz.clear();
        cost.clear();
        ok.clear();
        in>>n>>m;

        rez = MIN;
        viz.resize(n+1);
        cost.resize(n+1);
        l.resize(n+1);
        ok.resize(n+1, 0); //initial, facem parcurgeri din toate nodurile

        for(long long i=1; i<=n; i++)
            in>>cost[i];

        for(long long i=1; i<=m; i++)
        {
            in>>x>>y;
            l[x].push_back(y);
            ok[y] = 1; //nodul y e nod de sosire, deci nu e nevoie sa pornim parcurgere din el
        }

        for(long long i=1; i<=n; i++)
            if(ok[i] == 0) //daca i e nod de plecare, fac parcurgerea din el
                dfs(i);

        out<<rez<<"\n";
    }

    return 0;
}
