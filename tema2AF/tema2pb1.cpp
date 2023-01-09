#include <bits/stdc++.h>

using namespace std;

ifstream fin("retea2.in");
ofstream fout("retea2.out");

int n, m;

vector<pair<int, int>> blocuri, centrale;
vector<double> distCentrala; // distanta fiecarui nod pana la cea mai apropiata centrala
double distantaTotala; // distanta totala la final
vector<bool> finalizat; // daca am ales pentru un nod o distanta
vector<double> distFinala; // distantele finale => APCM

//functie care calculeaza distanta euclidiana
double dist(pair<int, int> p1, pair<int, int> p2) {
    return sqrt((pow(p1.first - p2.first, 2)) + pow((p1.second - p2.second), 2));
}

int main() {

    fin >> n >> m;
    distCentrala.resize(m + 1, INT_MAX);
    finalizat.resize(m + 1, false);
    distFinala.resize(m + 1, INT_MAX);

    int x, y;
    for (int i = 0; i < n; i++) {
        fin >> x >> y;
        centrale.push_back( make_pair(x,y) );
    }
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        blocuri.push_back( make_pair(x,y) );
    }

    // calculam distanta de la fiecare bloc la cea mai apropiata centrala
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            distCentrala[i] = min(distCentrala[i], dist(blocuri[i], centrale[j]));
        distFinala[i] = distCentrala[i];
    }


    for ( int i = 0; i < m; i++) {
        double d = INT_MAX;
        int ultim = -1;
        // pentru fiecare nod care nu a fost finalizat il legam de cel mai apropiat nod deja finalizat
        // am calculat deja distantele bloc-centrala, calculam distantele bloc-bloc
        for ( int j = 0; j < m; j++) {
            if (!finalizat[j]) {
                if (distFinala[j] < d) {  // distFinala minima
                    d = distFinala[j];
                    ultim = j;
                }
            }
        }
        // crestem distanta totala cu valoarea determinata anterior
        distantaTotala += d;

        // Modificam distFinala cu minimul dintre valorile existente si cele noi calculate
        for ( int j = 0; j < m; j++)
            distFinala[j] = min(distFinala[j], dist(blocuri[j], blocuri[ultim]));
        finalizat[ultim] = true;
    }
    fout << fixed << setprecision(6) << distantaTotala;
    return 0;
}

