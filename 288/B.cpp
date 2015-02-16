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

int n,k;
int in[105];

vector<int> ans[105];

int main()
{

 ios_base::sync_with_stdio(0);

 cin>>n>>k;

 int mx = 0, mn = 1000;

 for(int i=1;i<=n;i++)
    {
        cin>>in[i];

        mx=max(mx,in[i]);
        mn=min(mn,in[i]);
    }

  if( mn + k < mx)
  {
      cout<<"NO\n";
      return 0;
  }

  //first with

  for(int i=1;i<=n;i++)
  {
      for(int j=0;j<mn;j++)
        ans[i].pb(1);

      in[i]-=mn;
  }

  int cid=1;

  for(int cid=1;cid<=k;cid++)
  {
       for(int j=1;j<=n;j++)
         if( in[j] >= 1)
         {
              in[j]--;
              ans[j].pb(cid);
         }
  }

  cout<<"YES\n";

  for(int i=1;i<=n;i++,cout<<endl)
    for(int j=0;j<sz(ans[i]);j++)
      cout<<ans[i][j]<<" ";



 return 0;

}
