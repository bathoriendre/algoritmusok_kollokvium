#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, LL> LLLL;
typedef vector<LLLL> vLLLL;

vector<vector<int>> edges;    // GRÁF ábrázolja a szomszédsági listát a fa ábrázolásához
vLLLL m1, m2;                  // Az m1 minden városban a max profitot, az m2 a második legjobb profitot tárolja
bool seen[100010];             // Tömb a meglátogatott városok nyomon követéséhez a DFS során
int A[100010];                 // A városok árai

// A setPath függvény frissíti egy adott város u maximális profitútját

void setPath(const int u, const int v) {
    LL w = max(0, A[v] - A[u]);  // Kiszámítjuk a lehetséges profitot u várostól v-ig
    LL p = (m1[v].second != u) ? m1[v].first : m2[v].first; // Nézzük meg profitot a legjobb vagy a második legjobb útból
    if (w + p > m1[u].first) {  // Ha az új út jobb hasznot kínál
        m2[u] = m1[u];          
        m1[u].first = w + p;    
        m1[u].second = v;       
    }
    else if (w + p > m2[u].first) {  // Ha az új út jobb második legjobb profitot kínál
        m2[u].first = w + p;
        m2[u].second = v;
    }
}

// A DFS0 az első mélységi keresés, amely a maximális nyereséget számítja ki
// minden város számára u a szomszédok rekurzív feltárásával
void DFS0(const int u) {
    seen[u] = 1;  // A város megjelölése látogatottként
    for (auto& e : edges[u]) {  // Fedezzük fel az összes szomszédos várost
        if (!seen[e]) {          
            DFS0(e);             
            setPath(u, e);       
        }
    }
}

// A DFS1 a második mélységi keresés, amely a számított maximális nyereséget továbbítja
// és újraellenőrzi az u várostól a szomszédokhoz vezető maximális utat
void DFS1(const int u, const int prv) {
    seen[u] = 1;  // A város megjelölése látogatottként
    setPath(u, prv);  // Frissítse a legjobb útvonalat az előző városból (prv) a jelenlegi városba u
    for (auto& e : edges[u])  
        if (!seen[e])         
            DFS1(e, u);       
}

int main() {
    int N, Q, n1, n2;
    scanf("%d %d", &N, &Q);  
    
    edges.assign(N + 10, vector<int>());  
    m1.assign(N + 10, LLLL(0, 0));        
    m2.assign(N + 10, LLLL(0, 0));       
    
    for (int i = 0; i < N; i++)          
        scanf("%d", &A[i]);
    
    for (int i = 0; i < N - 1; i++) {    
        scanf("%d %d", &n1, &n2);
        edges[n1].push_back(n2);          
        edges[n2].push_back(n1);          
    }

    DFS0(0);  
    
    memset(seen, 0, sizeof(seen));  
    DFS1(0, N);  
    
    while (Q--) {  
        scanf("%d", &n1);  
        printf("%lld\n", m1[n1].first); 
    }
    
    return 0;
}