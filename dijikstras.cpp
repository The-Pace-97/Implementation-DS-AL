#include<bits/stdc++.h>
using namespace std;
#define ll long long int
priority_queue < pair<int,int> , vector < pair < int,int > >, greater<pair<int,int>> >  pq;
vector < pair<int,int> > v[1001] ;
ll dist[1001];
bool vis[1001];
void init(int src)
{
    for(int i=0;i<=100;i++)
    {
        dist[i]=INT_MAX;
        vis[i]=false;
    }
    dist[src]=0;
}
void dijkstras(int src)
{
    pq.push({0,src});
    dist[src]=0;
    while(!pq.empty())
    {
        int u=pq.top().second;
        pq.pop();
        if(vis[u]) continue;
        vis[u]=true;
        for(int i=0;i<v[u].size();i++)
        {
            if(dist[u]+v[u][i].first<=dist[v[u][i].second]){
            dist[v[u][i].second]=dist[u]+v[u][i].first;
            pq.push({dist[v[u][i].second],v[u][i].second});
            }
        }
    }
}
int main()
{
    int i,j,k,l,n,m,t,q,a,b,c,src;
    cin>>n>>m;

    for(i=1;i<=m;i++)
    {
        cin>>a>>b>>c;
        v[a].push_back({c,b});
        v[b].push_back({c,a});
    }
    cin>>src;
    init(src);
    dijkstras(src);
    for(i=1;i<=n;i++)
    cout<<dist[i]<<" ";

}


/*

8
9
1 2 1
1 3 6
2 6 4
2 5 1
2 4 2
5 8 9
6 4 8
4 8 3
4 7 3
1


*/
