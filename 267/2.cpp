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

 int n,m,k;

 int in[1005];

int cont( int a, int b)
{
  int t=(a^b);

  return __builtin_popcount(t);
}

int main()
{
 ios_base::sync_with_stdio(0);

  cin>>n>>m>>k;

  for(int i=1;i<=m+1;i++)
     cin>>in[i];

  int ans=0;

  for(int i=1;i<=m;i++)
      if( cont(in[i],in[m+1]) <=k )
        ans++;

  cout<<ans<<endl;

 return 0;

}
