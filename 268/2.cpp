#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
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

#define MAX_V 200009

vector<int> L[MAX_V],C[MAX_V];
int V,dfsPos,dfsNum[MAX_V],lowlink[MAX_V],num_scc;
bool in_stack[MAX_V];
stack<int> S;

int comp[MAX_V];

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
            com.push_back(aux);
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

    for(int i = 0;i<V;++i)
        if(dfsNum[i]==-1)
            tarjan(i);
}

int in[MAX_V];

map<int,vector<int> > mapa;

int main()
{
 ios_base::sync_with_stdio(0);

 int n,a,b;

 cin>>n>>a>>b;

 for(int i=0;i<n;i++)
     {
      cin>>in[i];

      mapa[ in[i] ].pb(i);
     // mapa[ in[i] ].pb(n+i);
     }

  for(int i=0;i<2*n;i++)
  {
      int val=(i>=n)?in[i-n]:in[i];
      ///try on side A

        vector<int> curr=mapa[ a - val ];

           for(int j=0;j<sz(curr);j++)
           {
               if(i==curr[j] )
                  continue;

               int id=(curr[j]>=n)?(curr[j]-n):(curr[j]+n);

                 L[i].pb( id );
           }

       //try on side B

         curr=mapa[ b - val ];

           for(int j=0;j<sz(curr);j++)
           {
               if(i==curr[j] )
                  continue;

               int id=(curr[j]>=n)?(curr[j]-n):(curr[j]+n);

               L[i].pb( id );
           }
    }

    V=2*n;

    build_scc();

    for(int i=0;i<=num_scc;i++)
          for(int j=0;j<sz( C[i] );j++)
            comp[ C[i][j] ]=i;

    for(int i=0;i<n;i++)
    {
        //cout<<C[i]<<"  ";
        if( comp[i]==comp[i+n] )
            {

                cout<<"NO\n";
                return 0;
            }
    }

 return 0;

}
