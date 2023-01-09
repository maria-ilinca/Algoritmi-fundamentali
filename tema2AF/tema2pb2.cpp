#include <fstream>

using namespace std;

const int MAXI = 100001;

ifstream fin("disjoint.in");
ofstream fout("disjoint.out");

int tata[MAXI], rang[MAXI];

// pentru a afla radacina merg in sus pe arbore pana gasesc un nod care pointeaza catre el insusi
int find(int x) {
    int root = x;
    while (tata[root] != root)
        root = tata[root];
    tata[x] = root;
    return root;
}

void unite(int x, int y) {
    // unim cele doua grafuri dupa radacina

    int root_x = find(x);
    int root_y = find(y);
    if (root_x == root_y)
        return;

    // radacina grafului cu rangul mai mic va deveni root celui cu rang mai mare
    if (rang[root_x] > rang[root_y]) {
        tata[root_y] = root_x;
        rang[root_x] += rang[root_y];
    }
    else {
        tata[root_x] = root_y;
        rang[root_y] += rang[root_x];
    }
}

int main() {
    int n, m, op, x, y;

    fin >> n >> m;
    // initial fiecare nod pointeaza catre el insusi iar rangul fiecarui arbore este 1
    for (int i = 1; i <= n; ++i) {
        tata[i] = i;
        rang[i] = 1;
    }

    for (int i = 1; i <= m; i++) {
        fin >> op >> x >> y;
        if (op == 1)
            unite(x, y);
        else {
            // verific daca radacina arborilor in care se afla x respectiv y este egala
            if (find(x) == find(y))
                fout << "DA" << '\n';
            else
                fout << "NU" << '\n';
        }
    }
    return 0;
}

