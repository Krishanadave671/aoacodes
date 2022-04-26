#include <bits/stdc++.h>
using namespace std;
#define INF 999
// macros;
typedef vector<int> vi;
typedef vector<vi> vvi;

vvi edges;
vvi Graph;
vi d, p;
void readGraph(int V)
{
    cout << "Enter the graph in matrix form "<<endl; ;
    for (int i = 0; i < V; i++)
    {
        vi a;
        for (int j = 0; j < V; j++)
        {
            int x;
            cin >> x;
            a.push_back(x);
            
        }
        Graph.push_back(a);
    }
}

void createTable(int V , int E){
    for(int i = 0 ; i < V ; i++){
        for(int j = 0; j < V; j++){
            if(Graph[i][j] != 0) edges.push_back({i, j, Graph[i][j]});
        }
    }
    cout<<"/n Edge Table \n";
    for(int i = 0; i < E; i++){
        cout << edges[i][0] <<" --> " << edges[i][1] <<" : "<< edges[i][2] <<endl;
    }


}
void displayGraph(int V)
{
    cout << "\nThe graph in matrix form\n"<<endl;
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout << Graph[i][j] << " ";
        }
        cout << endl;
    }
}

void initialize(int V , int s){
    for(int i = 0 ; i < V; i++){
        auto  dbegin = d.begin();
        auto  pbegin = p.begin();
        if(i != s){
             d.insert(dbegin + i, INF);
             p.insert(pbegin + i , -1);
        }

        else{
             d.insert(dbegin + i, 0);
             p.insert(pbegin + i , -1);
        }
    }
}
int negcycle(int E)
{
  for(int i = 0;i<E;i++)
  {
    if(d[edges[i][1]]>d[edges[i][0]]+edges[i][2])
      return 0;
  }
  return 1;
}

void relax(int u,int v,int w)
{
  if(d[v]>d[u]+w)
  {
    d[v] = d[u] +w;
    p[v] = u;
  }
  
}

void printpath(int s,int v)
{
  if (v==s)
    printf(" %d ",s);
  else if(p[v] == -1)
    printf("No path exist");
  else
  {
    printpath(s,p[v]);
    printf("-->");
    printf(" %d ",v);
  }
  
}

int main()
{
    int V, E;
    int source;
    cout << "Enter the vertices of graph :  ";
    cin >> V;
    cout << "Enter the number of edges in graph : ";
    cin>> E;
    readGraph(V);
    displayGraph(V);
    createTable(V, E);
    cout << "Enter the source vertex "<<endl;
    cin >> source;
    initialize(V, source);
    printf("\n shortest path estimate after initialization \n");
    for(int i =0;i<V;i++)
    printf("%d \t",d[i]);
    printf("\n");
    printf("\n predecessor after initialization\n");  
    for(int i =0;i<V;i++)
    printf("%d \t",p[i]);
     for (int i = 0; i < V-1; i++)
    {
      for (int j = 0; j < E; j++)
      {
        relax(edges[j][0],edges[j][1],edges[j][2]);
      }
    }

    printf("\n shortest path estimate\n");
    for(int i =0;i<V;i++)
    printf("%d \t",d[i]);
    
    printf("\n");
    printf("\n predecessor\n");  
    for(int i =0;i<V;i++)
    printf("%d \t",p[i]);   
    bool flag = negcycle(E);
    if(flag)printf("\nSSSP Exist\n");
  else
    printf("Negative weight Cycle");

    for (int i = 0;i<=V-1;i++)
  {
    if (i ==source)
    continue;
    printf("path from %d to %d is ",source,i);  
    printpath(source,i);
    printf("\n");
  }


      



    return 0;
}
