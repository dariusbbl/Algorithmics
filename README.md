1. numarare.cpp: -> Pentru problema data am calculat numarul de drumuri de la nodul 1 la nodul n intr-un graf orientat cu muchii comune dintre 2 arbori. 
M-am folosit de o matrice de adiacenta pentru reprezentarea grafurilor si a programarii dinamice pentru calculul drumurilor. 
Astfel, matricea de adiacenta matr_G1 alocata dinamic pentru primul arbore, iar lista de adiacenta G este folosita pentru stocarea muchiilor comune celor 2 arbori 
( daca muchia apartine amandurora, este adaugata in aceasta lista). Vectorul dp este folosit pentru a stoca numarul de drumuri de la nodul de start la 
fiecare nod i (am initializat dp[1] = 1 intrucat exista un singur drum de la nodul 1 la el insusi). Pentru fiecare nod i programul itereaza prin lista de adiacenta si 
actualizeaza dp[j] pentru fiecare vecin j al lui i, adaugand la dp numarul de drumuri pana la i aplicand MOD. -> Complexitate temporala: O(n + m)

2. drumuri.cpp: -> Problema data determina costul minim pentru a ajunge la un nod dat din 3 puncte diferite intr-un graf orientat. Pentru aceasta este utilizat algoritmul lui Djikstra 
pentru a gasi cel mai scurt drum de la fiecare dintre cele 3 puncte la toate celelalte noduri. Graful este reprezentat prin: lista de adiacenta "edges" ce contine perechi (nod,cost) 
pentru a reprezenta muchiile si "costurile" asociate fiecarei muchii si lista de adiacenta inversa "reversed" utilizata pentru a reprezenta graful transpus, muchiile fiind adaugate invers 
pentru a permite calculul costului de la nodul z la celelalte. Pentru Dijkstra se foloseste o coada de prioritati pentru a selecta nodul cu cel mai mic cost de la fiecare pas. 
Costurile sunt stocate intr-o materice "cost" unde fiecare coloana este atribuita costurilor nodului sursa. -> Codul parcurge toate nodurile pentru a determina nodul pentru care suma costurilor 
de la x,y si z este minima. Se verifica si daca nodul este accesibil la toate cele 3 surse. -> Complexitate temporala: O((n + m) log n)

