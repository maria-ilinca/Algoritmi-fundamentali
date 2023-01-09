class Solution {
public:
    int shortestPathLength(vector<vector<int> >& graph) {
        queue<vector<int> > q;
        map<int, set<int> > visited;
        int n = graph.size();
        int bit = (1 << n) - 1;

        for(int i = 0; i < n; i++){
            q.push({ 0 | (1 << i), i });
        }
        if (n == 1)
            return 0;
        //folosim un bfs pentru a parcurge graful
        for (int lev = 1; !q.empty(); lev++) {
            int size=q.size();
            while(size--){
                vector<int> curr = q.front();
                q.pop();
                // La fiecare pas, eliminam un element din coada si vedem daca am acoperit toate nodurile din bitMask-ul nostru. In caz ca da, returnam imediat costul caii. Din moment ce folosim BFS, acest lucru este considerat a fi calea cu cel mai mic cost.

                // In caz contrar, parcurgem toti vecinii nodului curent, il setam pe fiecare ca vizitat si il adaugam inapoi in coada
                for (int i = 0; i < graph[curr[1]].size(); i++) {
                    int v = graph[curr[1]][i];
                    int bitMask = curr[0] | (1 << v);

                    if (bitMask == bit)
                        return lev;
                    if(visited[v].count(bitMask))
                        continue;
                    visited[v].insert(bitMask);
                    q.push({bitMask, v });
                }
            }
        }
        return -1;
    }
};
