// PROBLEMA 1 - NUMARARE
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;  // 10^9 + 7

int main() {
    ifstream fin("numarare.in");
    ofstream fout("numarare.out");

    int n, m;  // dimensiunile celor 2 arbori
    fin >> n >> m;

    // construiesc arborele g1 ca matrice de adiacenta alocata dinamic
    int** matr_G1 = new int* [n];
    for (int i = 0; i < n; i++) {
        matr_G1[i] = new int[m];
    }
    vector<int> G[100002];
    // initializare matrice de adiacenta
    int x, y;
    for (int i = 0; i < m; i++) {
        fin >> x >> y;
        matr_G1[x][y] = 1;
    }
    // construiesc arborele G de muchii comune
	for (int i = 0; i < m; i++) {
        fin >> x >> y;
        if (matr_G1[x][y] == 1) {
			G[x].push_back(y);
		}
    }

    // vectorul dp[i] = numarul de drumuri de la nodul 1 la nodul i
    vector<int> dp(n + 1, 0);
    dp[1] = 1;  // Start de la nodul 1

    // calculul numarului de drumuri folosind doar muchiile comune
    for (int i = 1; i <= n; i++) {
		int len = G[i].size();
        // pentru fiecare nod i, adaug numarul de drumuri
        // de la nodul i la nodul G[i][j]
        for (int j = 0; j < len; j++) {
            dp[G[i][j]] = (dp[G[i][j]] + dp[i]) % MOD;
		}
	}

    // afisez rezultatul
    fout << dp[n] << endl;

    fin.close();
    fout.close();
    return 0;
}
