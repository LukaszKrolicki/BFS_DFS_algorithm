#include <iostream>
#include <queue>
using namespace std;

struct edge{
    int s; //wierzcholek
    int t; //sasiad
};

class Graph{
private:
    int** adjMatrix; //macierz sasiedztwa;
    int n; //liczba wezlow
    bool directed; //true jezeli skierowany false jezeli nieskierowany
    void dfs(int s, int* visited); //wykonuje przeszukiwanie i wyœwietla wêz³y w przypadku odwiedzenia
public:
    Graph(int n, int m, edge edges[], bool directed); //tworzt graf w oparciu o podan¹ listê krawêdzi
    void bfs(int s);
    void dfs(int s);
    void wyswietl();

};

//konstruktor
Graph::Graph(int n, int m, edge edges[], bool directed){
    this->n=n;
    this->directed=directed;
    adjMatrix= new int*[n];
    for(int i=0; i<n; i++){
        adjMatrix[i]=new int[n]{};
    }

    for(int i=0;i<m;i++){
        adjMatrix[edges[i].s][edges[i].t] = 1;
        if(!directed){
            adjMatrix[edges[i].t][edges[i].s]=1;
        }
    }
}

void Graph::wyswietl(){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void Graph::bfs(int s){
    int visited[n]{};
    int parent[n]{};
    int u;
    queue<int> g; //#include <queue>
    visited[s]=1; //odwiedzony true

    g.push(s);
    while(!g.empty()){
        u=g.front();//zapisujemy szczyt
        cout<<u;
        g.pop();//usuwamy szczyt
        for(int i=0;i<n; i++){ //przechodzimy przez wszystkie wierzcho³ki
            if(adjMatrix[u][i]==1) //je¿eli napotakmy s¹siada
            {
                if(visited[i]==0)//jezeli nie by³ odwiedzony
                {
                    visited[i]=1; //zaznaczamy ze odwiedzony
                    parent[i]=u; //ustawiamy rodzica
                    g.push(i); //dodajemy do kolejki
                }
            }
        }
    }

}

void Graph::dfs(int s, int* visited){
    visited[s]=1;
    cout<<s<<" ";
    for(int i=0; i<n; i++){
        if(adjMatrix[s][i]==1)
        {
            if(visited[i]==0)
            {
                dfs(i, visited);
            }
        }
    }

}

void Graph::dfs(int s){
    int visited[n]{};
    dfs(s,visited);
}


int main(){
    int n=6; //liczba wierzcholkow
    int m=15; //liczba po³¹czen

    edge directedGraph[]={{0,4},{0,5},{1,0},{1,2},{1,4},{2,1},{2,3},{2,4},{3,2},{3,5},{4,0},{4,1},{4,3},{5,3},{5,4}};

    Graph g(n,m,directedGraph,true);
    g.dfs(0);

}
