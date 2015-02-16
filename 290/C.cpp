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

vector<int> graf[30];

vector<int> ans;

bool done[30];

bool instack[30];
bool cycle = false;

void dfs( int u )
{
    if( done[u])
        return;

     instack[u]=true;

    done[u]=true;
    ans.pb(u);

    for(int i=0;i<sz(graf[u]);i++)
    {
        if( incycle[ graf[u][i] )
        { cycle=true;
           return;
        }
    }
        dfs( graf[u][i] );
}

int inc[30];

void build( string A, string B )//given A < B
{
     int n = min( sz(A) , sz(B) );

     for(int i=0;i<n;i++)
         if( A[i] != B[i] )
         {
                graf[ A[i]-'a' ].pb( B[i]-'a' );
                inc[ B[i]-'a' ]++;
                return;
         }
}


string in[105];

int main()
{
 ios_base::sync_with_stdio(0);

 fill(done,0);
 fill(inc,0);

 int n;

 cin>>n;

 for(int i=1;i<=n;i++)
    cin>>in[i];

 for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
       build( in[i] , in[j] );

 bool dp[30][30]; fill(dp,0);

 for(int i=0;i<26;i++)
    for(int )

 for(int i=0;i<26;i++)
     if( !done[i])
       if( inc[i] == 0)
            dfs(i);


  for(int i=0;i<sz(ans);i++)
    cout<<(char)('a'+ans[i]);

  cout<<endl;

 return 0;

}
