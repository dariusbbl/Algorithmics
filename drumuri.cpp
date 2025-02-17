// PROBLEMA 3 - DRUMURI
#include <bits/stdc++.h>

using namespace std;

// declarare variabile globale
const int NMAX = 1e5 + 5;
const long long INF = 1e18;

vector<vector<pair<int, int>>> edges;
vector<vector<pair<int, int>>> reversed;
// cost[i][j] = costul minim de la nodul i la nodul j
long long cost[NMAX][3];
bool visited[NMAX][3];
// priority queue pentru Dijkstra
priority_queue<pair<long long, int>,
 vector<pair<long long, int>>, greater<pair<long long, int>>> pq;

// functie pentru algoritmul lui Dijkstra
void dijkstra(int src, vector<vector<pair<int, int>>>& graph, int index) {
    for (int i = 0; i < NMAX; i++) {
        cost[i][index] = INF;
        visited[i][index] = false;
    }
    cost[src][index] = 0;
    pq.push({0, src});

    while (!pq.empty()) {
        pair<long long, int> top = pq.top();
        pq.pop();
        int u = top.second;
        if (visited[u][index]) continue;
        visited[u][index] = true;

        int len = graph[u].size();
        for (int i = 0; i < len; i++) {
            int v = graph[u][i].first;
            int w = graph[u][i].second;
            if (cost[u][index] + w < cost[v][index]) {
                cost[v][index] = cost[u][index] + w;
                pq.push({cost[v][index], v});
            }
        }
    }
}

int main() {
    ifstream fin("drumuri.in");
    ofstream fout("drumuri.out");

    int n, m;
    fin >> n >> m;
    // initializare vectori de muchii
    edges.resize(n + 1);
    reversed.resize(n + 1);
    // citire muchii
    for (int i = 0, a, b, c; i < m; i++) {
        fin >> a >> b >> c;
        edges[a].push_back({b, c});
        reversed[b].push_back({a, c});
    }
    // citire noduri x, y, z
    int x, y, z;
    fin >> x >> y >> z;
    // apelare Dijkstra pentru fiecare nod
    dijkstra(x, edges, 0);
    dijkstra(y, edges, 1);
    dijkstra(z, reversed, 2);
    // calculare cost minim
    long long minSum = INF;
    for (int i = 1; i <= n; i++) {
        // daca am vizitat toate cele 3 noduri
        if (visited[i][0] && visited[i][1] && visited[i][2]) {
            // costul total de la nodul i la cele 3 noduri
            long long currSum = cost[i][0] + cost[i][1] + cost[i][2];
            minSum = min(minSum, currSum);
        }
    }
    // afisare rezultat
    fout << minSum << endl;

    fin.close();
    fout.close();
    return 0;
}
