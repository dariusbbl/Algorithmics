//  PROBLEMA 4 - criptat
#include <bits/stdc++.h>
using namespace std;


int dp[10005];

void init(int n) {
    for (int i = 1; i <= n; i++) {
        // initializam cu o valoare foarte mica
        dp[i] = -1e9;
    }
    dp[0] = 0;
}

int main() {
    ifstream fin("criptat.in");
    ofstream fout("criptat.out");

    int n;
    string s[1005];
    set<char>myset;  // set pentru carcatere unice
    fin >> n;
    for (int i = 0; i < n; i++) {
        fin >> s[i];
        for (int j = 0; j < (int)s[i].size(); j++) {
            myset.insert(s[i][j]);  // adaugam caracterele in set
        }
    }
    set<char>::iterator it = myset.begin();  // iterator pentru set
    int maxx = 0;  // lungimea maxima a parolei
    for (it; it != myset.end(); it++) {
        char ch = *it;  //  caracterul curent din set
        int ans = 0;
        int total = 0;
        vector<pair<int, int> > values;  // vector de perechi
        // (contor aparitii caracter, lungime)
        for (int i = 0; i < n; i++) {
            int cnt = 0;
            for (int j = 0; j < (int)s[i].size(); j++) {
                if (ch == s[i][j])
                    cnt++;  // numaram aparitiile caracterului
            }
            // adaugam perechea in vector
            values.push_back(make_pair(cnt, s[i].size()));
            // adaugam la lungimea totala
            total += s[i].size();
        }
        init(total);
        for (int i = 0; i < n; i++) {
            for (int j = total; j >= 0; j--) {
                if (j >= values[i].second) {
                    dp[j] = max(dp[j], dp[j - values[i].second]
                    + values[i].first);
                }
            }
        }
        // verificarea cond literei dominante
        for (int i = total; i >= 0; i--) {
            if (dp[i] * 2 > i) {
                ans = i;
                break;
            }
        }
        // actualizarea lungimii maxime
        maxx = max(maxx, ans);
    }
    fout << maxx;
    fin.close();
    fout.close();
    return 0;
}
