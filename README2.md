PROBLEMA 1 - servere
Problema se bazeaza pe metoda analizarii graficelor ecuatiilor primite ca input pe site-ul "desmos", unde am luat perechile de intersectie ale dreptelor graficelor si am sticat punctele de suma minima de (putere,prag) si diferenta minima de (putere,prag). Am egalat ecuatiile corespunzatoare acestora in vederea determinarii cantitatii de curent prin serverele cerintei si am luat in considerare doar cazul prag_mic (din perechile luate) <= x (curentul ce trebuie aflat) <= prag_mare (din perechile luate), pentru ca x-ul sa nu se reduca la explicitarea matematica a modulului.
Ulterior, inlocuiesc acest x in ecuatiile celelalte pentru a afla puterile individuale pentru fiecare dintre acestea si mai departe de a stoca minimul dintre ele drept raspuns final.

PROBLEMA 2 - colorare
Problema se foloseste de functia "fast_pow" pentru ridicarea eficienta la putere in functie de o baza si un exponent. Ulterior, se trece la verificarea unuia dintre cele 3 cazuri posibile, pe baza carora am stabilit formula de numar de tablouri ce pot fi colorate in mod distinct din cele 3 culori: roz, mov, galben. Acestea sunt:
- ultimul dreptunghi este orizontal si vreau sa introduc minim unul vertical
- ultimul dreptunghi este orizontal si vreau sa introduc minim unul orizontal
- ultimul dreptunghi este vertical si vreau sa introduc minim unul vertical
- ultimul dreptunghi este vertical si vreau sa introduc minim unul orizontal
Dupa stabilirea formulelor, pentru primul set de dreptunghiuri, am scazut cu 1 numarul celor ce trebuie adaugate in formula si am verificat separat cate tablouri distincte se pot realiza dintr-o singura verticala, respectiv o orizontala.

PROBLEMA 3 - compresie
Implementarea vizeaza un algoritm ce itereaza prin ambele siruri A si B in paralel si aplica operatia de compresie acolo unde este nevoie (suma a doua elemente adiacente sirului ce le va inlocui pe acestea). Se compara elementele corespunzatoare din A si B. Daca un element din A este mai mic decat corespondentul sau din B, se aplica compresia pe sirul A. Daca este mai mare, se aplica pe sirul B, iar daca elementele sunt egale (ceea ce se si urmareste in final, ajungerea la 2 siruri egale), avansam indecsii ambilor vectori. Algoritmul se incheie cand cel putin unul dintre siruri a fost parcurs complet, intrucat acestea nu au neaparat lungimi egale. In cazul in care in final cei doi vectori sunt egali, se returneaza lungimea maxima posibila. In caz contrar, -1.

PROBLEMA 4 - criptat
Programul se bazeaza in special pe tehnica de programare dinamica pentru a determina maximul lungimiin unei parole care poate fi formata sub conditiile cerintei. Din scopul de a forma cea mai lunga parola ce respecta regula literei dominante, verificam fiecare cuvant pentru a determina daca poate contribui la formarea unei parole valide (prezenta literei dominante in acest cuvant). Am utilizat o structura de date de tip "set", pentru a stoca cu usurinta caracterele unice pentru un "alfabet". Prin iteratia setului, verific crearea parolei cu fiecare caracter dominant extras din alfabet (fiecare litera considerata ch dominant). Stocarea rezultatelor intermediare se face prin "dp". Valorilor initiale le-au fost atribuite valorile -10^9 si 0, pentru cazul de baza.  Complexitatea este: O(N * L)

PROBLEMA 5 - oferta
Programul se foloseste de tehnica programarii dinamice pentru a determina costul minim posibil de pe banda de cumparaturi, putand grupa in 3 moduri diferite produsele de pe aceasta. ALgoritmul foloseste o matrice dp[NMAX][3], pentru urmatoarele cazuri: dp[i][0]- costul minim pt produsele pana la i ce pot fi luate individual, 
						dp[i][1]- costul minim dacă produsul i este grupat cu produsul i-1, aplicând o reducere de 50% la produsul mai ieftin din aceste doua 
						dp[i][2]- Costul minim dacă produsele i, i-1 și i-2 sunt grupate împreună, oferind produsul cel mai ieftin dintre cele trei gratuit
După iterarea prin toate produsele, rezultatul final este minimul dintre cele trei costuri calculate pentru ultimul produs n. Aceasta reprezintă soluția optimă - cel mai mic preț posibil pentru achiziția tuturor produselor.
