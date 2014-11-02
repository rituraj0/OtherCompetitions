#include<algorithm>
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back
#define mp make_pair
#define Y second
#define X first

#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)

const double pi     =   acos(-1.0);
const double eps    =   1e-8;



vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}

/*Solution code starts here */

typedef long long ll;


ll in[3005],dp[3005][3005];

int main()
{
 ios_base::sync_with_stdio(0);

 int n,k;

 cin>>n>>k;

 for(int i=1;i<=n;i++)
     cin>>in[i];

    memset( dp[0] , -63 , sizeof(dp[0]) );

  dp[0][0]=0;

  for(int i=1;i<=n;i++)
     for(int j=1;j<=k*2;j++)
        dp[i][j]=max(dp[i-1][j] , dp[i-1][j-1] + ( 1 + (-2)*(j%2) )*in[i] );

    ll ans=0;

    for(int i=1;i<=k;i++)
         ans=max( ans , dp[n][2*i] );

    cout<<ans<<endl;


 return 0;

}
