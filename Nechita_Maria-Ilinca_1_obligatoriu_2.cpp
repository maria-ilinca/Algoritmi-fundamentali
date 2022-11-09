#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,n;
vector<int> permutare(100001), pozPermutare(100001), viz(100001), parcurgereDFS(100001);
vector<vector<int>> ls_ad(100001);

void dfs(int u){
    viz[u] = true;
    parcurgereDFS.push_back(u);
    for(int v: ls_ad[u]){
        if(!viz[v])
            dfs(v);
    }
}

//daca rezultatul dat de dfs este la fel cu permutarea atunci afisam 1

bool checkdfs(){
    for(int i = 1; i <= n; i++){
        if(parcurgereDFS[i] != permutare[i])
            return 0;
    }
    return 1;
}


bool compara(int nod1, int nod2)
{
    return pozPermutare[nod1] < pozPermutare[nod2];
}


int main()
{
    cin >> n >> m;

    //salvam permutarea si pozitiile nodurilor din permutare
    for (int i = 1; i <= n; i++)
    {
        int nod;
        cin >> nod;
        permutare.push_back(nod);
        pozPermutare[nod] = i;
    }

    //citim graful si cream lista de adiacenta
    for(int i = 1; i <= m; i++)
    {
        int x, y;
        cin >> x >> y;
        ls_ad[x].push_back(y);
        ls_ad[y].push_back(y);
    }

    //sortam nodurile din lista de adiacenta in functie de pozitiile lor din permutare
    for (int i = 1; i <= n; i++)
        sort(ls_ad[i].begin(), ls_ad[i].end(), compara);

    dfs(1);
    cout << checkdfs();
    return 0;

}

