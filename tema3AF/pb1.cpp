// folosim alg Edmonds-Karp
// se face bfs pt a se gasi de fiecare data s-t lantul din graf cu lungime minima
// se actualizeaza capacitatile si se revizuieste fluxul lanturilor

#include <bits/stdc++.h>

using namespace std;

ifstream fin("maxflow.in");
ofstream fout("maxflow.out");

int n, m, res_graph[1001][1001], graph[1001][1001], F;

bool vizitat[1001];
int tata[1001];

int bfs()
{
    // Reinitializez coada, multimea nodurilor vizitate si vectorul de tati

    queue <int> q;

    for (int i=0; i<=n; i++)
    {
        tata[i] = 0;
        vizitat[i] = false;
    }


    q.push(1);
    vizitat[1] = 1;

    // Fac BFS pentru a gasi drum de la sursa la destinatie:
    // -- ma uit la vecinii care nu sunt vizitati si au valoarea pozitiva (pot trimite flux)
    // -- salvez la fiecare pas parintele fiecarui nod pentru a reconstrui drumul

    while (q.empty() == false)
    {
        int node = q.front();
        q.pop();

        // Daca am ajuns la destinatie, am gasit drum

        if (node == n) return true;

        for (int i=1; i<=n; i++)
            if (vizitat[i] == false && res_graph[node][i] > 0)
            {
                q.push(i);
                tata[i] = node;
                vizitat[i] = true;
            }
    }

    // Daca nu am ajuns la destinatie, nu am putut gasi drum.

    return false;
}

// Pentru 100 de puncte trebuie facuta o optimizare.
// Astfel, la fiecare pas construim arborele BFS (excluzand destinatia),
// si acum un drum de la sursa la destinatie e reprezentat de un drum de la sursa
// (care este radacina arborelui) la o frunza legata de destinatie printr-o muchie nesaturata.

int flux()
{
    // Cat timp mai putem construi drumuri:

    while (bfs())
    {
        for (int i=1; i<n; i++)
        {
            if (res_graph[i][n] > 0 && vizitat[i] == true)
            {
                int frunza = i;

                // Reconstitui drumul dupa vectorul de tati:

                vector <int> drum;
                drum.push_back(n);
                drum.push_back(frunza);

                int nod = tata[frunza];

                if (nod == 1)
                    drum.push_back(nod);
                else
                {
                    while (nod != 1)
                    {
                        drum.push_back(nod);
                        nod = tata[nod];
                    }
                    drum.push_back(1);
                }

                reverse(drum.begin(), drum.end());

                // Gasesc capacitatea minima si o adaug la flux.

                int capacitate_minima = 110001;

                for(long unsigned int i=0; i<drum.size()-1; i++)
                    capacitate_minima = min(capacitate_minima, res_graph[drum[i]][drum[i+1]]);

                F += capacitate_minima;

                //scad apacitatea minima din muchiile drumului
                //si o adaug la muchiile cu directie opusa

                for(long unsigned int i=0; i<drum.size()-1; i++)
                {
                    res_graph[drum[i]][drum[i+1]] -= capacitate_minima;
                    res_graph[drum[i+1]][drum[i]] += capacitate_minima;
                }
            }
        }
    }

    return F;
}

//pentru min cut

/*bool visited[1001];
memset(visited, false, sizeof(visited));
dfs(res_graph, s, visited);
void dfs(int res_graph[V][V], int s, bool visited[])
{
    visited[s] = true;
    for (int i = 0; i < V; i++)
       if (res_graph[s][i] && !visited[i])
           dfs(res_graph, i, visited);
}
 visited[s] = true;
    for (int i = 0; i < V; i++)
       if (rGraph[s][i] && !visited[i])
           dfs(rGraph, i, visited);

// afisam toate muchiile care duc de la un varf accesibil
// la unul neacceptat in graful initial

for (int i = 0; i < V; i++)
   for (int j = 0; j < V; j++)
     if (visited[i] && !visited[j] && graph[i][j])
         cout << i << " - " << j << endl;*/

int main()
{
    fin>>n>>m;
    int x, y, capacitate;
    for(int i=1; i<=m; i++)
    {
        fin>>x>>y>>capacitate;
        res_graph[x][y]=capacitate;
        graph[x][y]=capacitate;
    }
    fout << flux();
    return 0;
}