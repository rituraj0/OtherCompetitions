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

bool in[20009][12];
ll sent[20009];
ll cont[12];
ll ans[20009];


int main()
{
 ios_base::sync_with_stdio(0);

 int n,m,k;

  cin>>n>>m>>k;

  fill(cont,0); fill(in,0); fill(sent,0);


  for(int i=1;i<=n;i++)
     for(int j=1;j<=m;j++)
        cin>>in[i][j];

int x,y;

  for(int i=0;i<k;i++)
  {

      cin>>x>>y;

      sent[x]++;
      cont[y]++;
  }

  fill(ans,0);

  for(int i=1;i<=m;i++)
  {
     for(int j=1;j<=n;j++)
        if( in[j][i]==1)
         ans[j]+=cont[i];
  }


  for(int i=1;i<=n;i++)
     cout<<ans[i]-sent[i]<<" ";




 return 0;

}
