//  PROBLEMA 2 - colorare
#include <bits/stdc++.h>

using namespace std;

const long long MOD = 1000000007;  // 10^9 + 7

long long fast_pow(long long base, long long exponent, const long long mod) {
    //  Calculati (base ^ exponent) % mod in O(log exponent)
    //  base ^ 0 = 1
    if (!exponent) {
        return 1;
    }
    int aux = 1;
    while (exponent != 1) {
        if (exponent % 2 == 0) {  //  par
            base = (1LL * base * base) % mod;
            exponent /= 2;
        } else {  //  impar
            aux = (1LL * aux * base) % mod;
            exponent--;
        }
    }
    return (1LL * aux * base) % mod;
}


int main() {
    ifstream fin("colorare.in");
    ofstream fout("colorare.out");

    int k;
    fin >> k;

    long long tablouri = 0;
    for (int i = 0; i < k; i++) {
        int numar;
        char type, old_type;
        fin >> numar >> type;
        if (i == 0) {
            numar = numar - 1;
            if (type == 'H') {
                tablouri = (6 * fast_pow(3, numar, MOD))%MOD;
            } else {
                tablouri = (3 * fast_pow(2, numar, MOD))%MOD;
            }
        } else {
            if (type == 'H' && old_type == 'H') {
                tablouri = (tablouri * fast_pow(3, numar, MOD))%MOD;
            }
            if (type == 'V' && old_type == 'V') {
                tablouri = (tablouri * fast_pow(2, numar, MOD))%MOD;
            }
            if (type == 'H' && old_type == 'V') {
                tablouri = (2 * tablouri * fast_pow(3, numar - 1, MOD))%MOD;
            }
            if (type == 'V' && old_type == 'H') {
                tablouri = (tablouri * fast_pow(2, numar - 1, MOD))%MOD;
            }
        }
        old_type = type;
    }
    fout << tablouri;
    fin.close();
    fout.close();

    return 0;
}
