#include<iostream>
#include<unordered_map>
#include<list>
using namespace std;

class graph{
    public:
    unordered_map<int,list<int>>adj;

    void addedje(int u,int v,bool direction){
        //direction=0->undirected
        //directoon=1->directed

        //create an edge from u to v

        adj[u].push_back(v);
        if(direction ==0)
        {
            adj[v].push_back(u);
        }
        cout<<endl;
    }

    void printadjlist(){
        for(auto i:adj){
            cout<<i.first<<"->";
            for(auto j:i.second){
                cout<<j<<" ,";
            }
            cout<<endl;
        }
    }
};

int main(){
    int n;
    cout<<"enter the number of nodes"<<endl;
    cin>>n;

    int m;
    cout<<"enter the no. of edges "<<endl;
    cin>>m;

    graph g;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        //creating an undirected graph
        g.addedje(u,v,0);
    }

    //printing graph

    g.printadjlist();

    return 0;
}