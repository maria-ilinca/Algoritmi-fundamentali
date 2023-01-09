class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int size1 = text1.size(), size2= text2.size();
        int matr[size1+1][size2+1];

        for(int i = 0; i <= size1; i++) {
            for(int j = 0; j <= size2; j++) {
                if(i == 0 || j == 0) matr[i][j] = 0; // daca una/ambele lungimi sunt 0
                else if(text1[i-1] == text2[j-1]) matr[i][j] = 1 + matr[i-1][j-1]; // daca am gasit un caracter comun
                else matr[i][j] = max(matr[i-1][j], matr[i][j-1]);
            }
        }
        return matr[size1][size2];
    }
};