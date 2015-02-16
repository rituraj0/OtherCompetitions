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

#define maxn 200009

vector<int>  graf[maxn];

vector<char> ans;

string decode( int val)
{
    string ans = "";

    ans+=(char)(val/255);
    ans+=(char)(val%255);

    return ans;
}

int  incode( string in)
{
    return int( in[0] )*255 + int( in[1] );
}

void dfs( int u)
{
    while( sz(graf[u]) > 0 )
    {
        int v = graf[u].back();
        graf[u].pop_back();

         dfs(v);
    }

    ans.pb( (char)(u%255) );
}

int in[maxn],out[maxn];

int main()
{
 ios_base::sync_with_stdio(0);

 fill(in,0);
 fill(out,0);

 int n;

 string tp;

 cin>>n;

 int start = 0 ;

 for( int i=0;i<n;i++)
 {
     cin>>tp;

     int u = incode( tp.substr(0,2) );
     int v = incode( tp.substr(1,2) );

     start = u;

     graf[u].pb(v);

     out[u]++;
     in[v]++;
 }

 int ingt=0,outgt=0;

 for(int i=0;i<maxn;i++)
    if( out[i] - in[i] == 1)
    {
           ingt++;
           start=i;
    }
    else if( out[i] - in[i] == -1)
    {
        outgt++;
    }
    else if( out[i] - in[i] != 0 )
    {
        cout<<"NO"<<endl;
        return 0;
    }

  if( (ingt>1)   || ( outgt > 1) )
  {
       cout<<"NO"<<endl;
       return 0;
  }

  //cout<<start/255<<"  "<<start%255<<endl;

  dfs(start);

  ans.pb( start/255 );

  if( sz(ans)!= n+2 )
  {
     cout<<"NO"<<endl;
     return 0;
  }

  cout<<"YES\n";

  for(int i=n+1;i>=0;i--)
    cout<<ans[i];

  cout<<endl;

  return 0;

}
