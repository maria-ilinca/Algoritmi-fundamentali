class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> G(numCourses);
        vector<int> ans, nrpre(numCourses);
        for(auto& pre : prerequisites)
            G[pre[1]].push_back(pre[0]),     //creare lista de adiacenta
                    nrpre[pre[0]]++;  //nr de cursuri prerequisites pt al i-lea curs

        queue<int> q;
        for(int i = 0; i < numCourses; i++)
            if(nrpre[i] == 0) q.push(i);   // incepem cu cele care nu au prequisites


        while(size(q)) {
            auto cur = q.front(); q.pop();
            ans.push_back(cur);   // daca un curs nu are prereq incepem cu el
            for(auto nextCourse : G[cur])
                if(--nrpre[nextCourse] == 0)
                    q.push(nextCourse);
        }
        if (size(ans) == numCourses) { return ans; }    // sol exista cand s-au facut toate cursurile

        return {};
    }
};

