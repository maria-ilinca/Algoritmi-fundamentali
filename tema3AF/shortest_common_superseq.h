class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2){
        string str3 = LCS(str1, str2);
        string ret = "";
        int i = 0, j = 0, k = 0;

        while (k < str3.size()) {
            if (i < str1.size() && str1[i] != str3[k]) {
                ret += str1[i];
                i++;
                continue;
            }
            if (j < str2.size() && str2[j] != str3[k]) {
                ret += str2[j];
                j++;
                continue;
            }
            ret += str3[k];
            k++;
            i++;
            j++;
        }
        while (i < str1.size()) {
            ret += str1[i];
            i++;
        }
        while (j < str2.size()) {
            ret += str2[j];
            j++;
        }
        return ret;
    }
    string LCS(string str1, string str2){
        string ret = "";
        int n = str1.size();
        int m = str2.size();
        vector<vector<int> > matr(n + 1, vector<int>(m + 1));
        int i = n;
        int j = m;
        str1 = " " + str1;
        str2 = " " + str2;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(i == 0 || j == 0) matr[i][j] = 0; // daca una/ambele lungimi sunt 0
                else if(str1[i] == str2[j]) matr[i][j] = 1 + matr[i-1][j-1]; // daca am gasit un caracter comun
                else matr[i][j] = max(matr[i-1][j], matr[i][j-1]);
            }
        }
        while (i && j) {
            if (matr[i][j] == matr[i - 1][j]) {
                i--;
                continue;
            }
            if (matr[i][j] == matr[i][j - 1]) {
                j--;
                continue;
            }
            ret += str1[i];
            i--;
            j--;
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};
