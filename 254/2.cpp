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


vector<int> in[55];

bool done[55];

int cont;

void dfs( int x)
{
    if( done[x]) return ;

    done[x]=true;
     cont++;
    for(int i=0;i<in[x].sz;i++)
         dfs( in[x][i] );
}

int main()
{
 ios_base::sync_with_stdio(0);

 fill(done,0);


 int n,m,x,y;

 cin>>n>>m;

 for(int i=0;i<m;i++)
 {
     cin>>x>>y;
     in[x].pb(y);
     in[y].pb(x);
 }

int mx=0;

int sm=0;

 for(int i=1;i<=n;i++)
     if( !done[i])
       {
         cont=0;
         dfs(i);
         sm+=(cont-1);
       }

 cout<<(1LL<<sm)<<endl;

 return 0;

}
