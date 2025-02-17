//  PROBLEMA 5 - oferta
#include <fstream>
#include <vector>
#include <iomanip>

using namespace std;

const int NMAX = 1e4 + 5;

double dp[NMAX][3];
// dp[i][0] pretul minim pana in punctul i
// daca produsul i il iau individual
// dp[i][1] pretul minim pana in punctul i
// daca produsul i il combin cu i - 1
// dp[i][2] pretul minim pana in punctul i
// daca produsul i il combin si cu i - 1 si cu i - 2
// pretul minim pana in punctul i este
// min(dp[i][0], dp[i][1], dp[i][2])


int main() {
    ifstream fin("oferta.in");
    ofstream fout("oferta.out");

    int n, k;  //  k = 1
    fin >> n;
    fin >> k;
    vector<int> preturi(n + 1);
    for (int i = 1; i <= n; i++) {
        fin >> preturi[i];
    }
    dp[1][0] = preturi[1];
    dp[1][1] = 1e9;  // nu pot sa iau pe 1 combinat cu 0 sau -1
    dp[1][2] = 1e9;
    dp[2][2] = 1e9;  // nu pot sa combin pe 2 cu 0
    for (int i = 2; i <= n; i++) {
        //  daca iau produsul i individual
        dp[i][0] = min(dp[i - 1][0],
         min(dp[i - 1][1], dp[i - 1][2])) + preturi[i];
        if (i >= 2) {  // daca pot grupa cate 2 produse
        //  unde cel mai ieftin va fi ieftinit cu 50%
            dp[i][1] = min(dp[i - 2][0],
            min(dp[i - 2][1], dp[i - 2][2])) +
             max(preturi[i], preturi[i - 1]) +
              min(preturi[i], preturi[i - 1]) / 2.0;
        }
        if (i >= 3) {  //  daca pot grupa cate 3 produse
        //  unde cel mai ieftin va fi ieftinit cu 100%
            dp[i][2] = min(dp[i - 3][0], min(dp[i - 3][1], dp[i - 3][2]))
             + preturi[i] + preturi[i - 1] + preturi[i - 2];
            dp[i][2] -= min(preturi[i], min(preturi[i - 1], preturi[i - 2]));
        }
    }

    double rez = min(dp[n][0], min(dp[n][1], dp[n][2]));
    fout << fixed << setprecision(1) << rez << endl;
    fin.close();
    fout.close();

    return 0;
}
