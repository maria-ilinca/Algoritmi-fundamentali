class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    // putem reduce problema la o verificare daca graful e bipartit sau nu
    vector<vector<int>> ls_ad(n+1);
    vector<int> cul(n + 1, 0);
    vector<bool> viz(n + 1, false);

    // creem lista de adiacenta
     for (auto &dislike: dislikes)
    {
        ls_ad[dislike[0]].push_back(dislike[1]);
        ls_ad[dislike[1]].push_back(dislike[0]);
    }
// efectuam BFS peste fiecare componentă conectata din grafic
// in acest timp verificam daca intalnim probleme la colorarea nodurilor din graf, acestea indica faptul ca bi-partitia nu este posibila
    queue<int> q;
    for(int i = 1; i <= n; ++i){
        if(!viz[i])
    {
        cul[i] = 1;
        q.push(i);
    while(!q.empty())
    {
        int fr=q.front();
        q.pop();
        if(viz[fr])
        {
            continue;
        }
        viz[fr]=true;
        for(auto v: ls_ad[fr]){

                if(cul[v]==cul[fr])
                {
                    return false;
                }

                if (cul[fr] == 1)
                        {
                            cul[v] = 2;
                        }
                 else
                        {
                            cul[v] = 1;
                        }
                 q.push(v);
        }
    }
    }
    }
    // pentru a determina cele 2 parti ale grafului bipartit
    // for(int i=0; i<n; i++){
    //     if(viz[i]==1)m1.push_back(i);
    //     else m2.push_back(i);
    // }


    return true;
    }
};

