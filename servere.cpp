//  PROBLEMA 1 - servere
#include <bits/stdc++.h>
using namespace std;


int main() {
    ifstream fin("servere.in");
    ofstream fout("servere.out");

    int nr_servere;
    fin >> nr_servere;

    vector<int> puteri(nr_servere);
    vector<int> praguri(nr_servere);

    for (int i = 0; i < nr_servere; i++) {
        fin >> puteri[i];
    }
    for (int i = 0; i < nr_servere; i++) {
        fin >> praguri[i];
    }

    //  Verific perechea de suma minima de (Putere,Prag)
    int suma_minima = INT_MAX;
    int putere_suma_minima = 0;
    int prag_suma_minima = 0;
    for (int i = 0; i < nr_servere; i++) {
        int suma = puteri[i] + praguri[i];
        if (suma < suma_minima) {
            suma_minima = suma;
            putere_suma_minima = puteri[i];
            prag_suma_minima = praguri[i];
        }
    }

    //  Verific perechea de diferenta minima de (Putere,Prag)
    int diferenta_minima = INT_MAX;
    int putere_diferenta_minima = 0;
    int prag_diferenta_minima = 0;
    for (int i = 0; i < nr_servere; i++) {
        int diferenta = puteri[i] - praguri[i];
        if (diferenta < diferenta_minima) {
            diferenta_minima = diferenta;
            putere_diferenta_minima = puteri[i];
            prag_diferenta_minima = praguri[i];
        }
    }

    //  Egalez ecuatiile :
    //  putere_suma_minima - |x - prag_suma_minima| =
    //  putere_diferenta_minima - |x - prag_diferenta_minima|
    //  Rezolv ecuatia si obtin x
    //  Iau doar cazul in care prag_mic <= x <= prag_mare ,
    //  ca altfel ni se anuleaza x
    double x;
    x = (putere_suma_minima + prag_suma_minima - putere_diferenta_minima
    + prag_diferenta_minima) / 2.0;

    //  Inlocuiesc pe x pentru toate ecuatiile de forma:
    //  putere[i] - |x - prag[i]| = ?
    vector<double> rezultate(nr_servere);
    for (int i = 0; i < nr_servere; i++) {
        int putere = puteri[i];
        int prag = praguri[i];
        //  Calculez rezultate[i]
        rezultate[i] = putere - (double)abs(x - prag);
    }

    //  Scot cel mai mic rezultat
    double rez = *min_element(rezultate.begin(), rezultate.end());

    fout << fixed << setprecision(1) << rez << endl;

    fin.close();
    fout.close();
    return 0;
}
