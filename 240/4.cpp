#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

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

int n,k;

#define mod 1000000007

ll memo[2005][2005];

ll solve( int len , int prev)
{
     if( len==k)
     {
         return 1;
     }

     ll &ans=memo[len][prev];

     if( ans !=-1)
         return ans;

         ans=0;

     for(int i=prev;i<=n;i+=prev)
          ans=(ans+solve(len+1,i) )%mod;

     return ans;

}

int main()
{
 ios_base::sync_with_stdio(0);

  cin>>n>>k;

  fill(memo,-1);

   ll ans=0;

  for(int i=1;i<=n;i++)
     ans=(ans+solve(1,i) )%mod;

   cout<<ans<<endl;

 return 0;

}
