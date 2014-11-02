#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

#define MAX_V 100005
#define mod 1000000007

vector<int> L[MAX_V],C[MAX_V];

int V,dfsPos,dfsNum[MAX_V],lowlink[MAX_V],num_scc;

bool in_stack[MAX_V];

stack<int> S;

ll cost[MAX_V];

void tarjan(int v){
    dfsNum[v] = lowlink[v] = dfsPos++;
    S.push(v); in_stack[v] = true;

    for(int i = L[v].size()-1;i>=0;--i){
        int w = L[v][i];
        if(dfsNum[w]==-1){
            tarjan(w);
            lowlink[v] = min(lowlink[v],lowlink[w]);
        }else if(in_stack[w]) lowlink[v] = min(lowlink[v], lowlink[w]);
    }

    if(dfsNum[v]==lowlink[v]){
        vector<int> com;
        int aux;

        do{
            aux = S.top(); S.pop();
            com.push_back( cost[aux] );
            in_stack[aux] = false;
        }while(aux!=v);

        C[num_scc] = com;
        ++num_scc;
    }
}

void build_scc(){
    memset(dfsNum,-1,sizeof(dfsNum));
    memset(in_stack,false,sizeof(in_stack));
    dfsPos = num_scc = 0;

    for(int i = 1;i<=V;++i)
        if(dfsNum[i]==-1)
            tarjan(i);
}



int main()
{
 ios_base::sync_with_stdio(0);

 cin>>V;

 for(int i=1;i<=V;i++)
     cin>>cost[i];

 int m,a,b;
 cin>>m;

 for(int i=1;i<=m;i++)
 {
     cin>>a>>b;
     L[a].pb(b);
 }

 build_scc();

 ll ans=0;
 ll cont=1;

 for(int i=0;i<num_scc;i++)
 {
     ll mn=*min_element(C[i].bg,C[i].en);
     ll all=0;

     for(int j=0;j<C[i].sz;j++)
          if( mn==C[i][j])
           {
                all++;
           }

      ans+=mn;
      cont=(cont*all)%mod;
 }

 cout<<ans<<" "<<cont<<endl;

 return 0;

}
