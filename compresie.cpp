// PROBLEMA 3 - compresie
#include <bits/stdc++.h>
using namespace std;


int main() {
    // deschiderea fisierelor "compresie.in" si "compresie.out"
    ifstream fin("compresie.in");
    ofstream fout("compresie.out");

    int n, m;
    // n - nr de elemente din vectorul A
    // m - nr de elemente din vectorul B

    fin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++)
        fin>>A[i];
    fin >> m;
    vector<int> B(m);
    for (int j = 0; j < m; j++)
        fin >> B[j];

    // compar in paralel vectorii A si B
    // si aplic compresia acolo unde este nevoie
    int i = 0, j = 0, compressionsA = 0;
    while (i < n && j < m) {
        if (A[i] != B[j]) {
            if (A[i] > B[j]) {
                // compresie pe elementul j si j+1 din B,
                // daca nu ne aflam la final
                if (j + 1 < m) {
                    B[j + 1] = B[j+1] + B[j];
                    j++;  // sarim peste elementul care tocmai a fost comprimat
                }
            } else {
                // compresie pe elementul i si i+1 din A,
                // daca nu ne aflam la final
                if (i + 1 < n) {
                    compressionsA++;
                    A[i+1] = A[i+1] + A[i];
                    i++;  // sarim peste elementul care
                    // tocmai a fost comprimat
                }
            }
        } else {
            // elementele sunt egale => avansam în ambii vectori
            i++;
            j++;
        }
    }

    if (i != n  || j != m) {
        fout << -1 << "\n";
    }
    fout << A.size() - compressionsA << "\n";

    fin.close();
    fout.close();

    return 0;
}
