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

ll in[10009];
ll dp[10009];
ll mx[10009];

int n,k;

ll solve()
{
    scanf("%d%d",&n,&k);

    dp[0]=0;
    mx[0]=0;

    for(int i=1;i<=n;i++)
         scanf("%lld",&in[i]);

    for(int i=1;i<=n;i++)
    {
        dp[i]=in[i];//start here
        mx[i]=0;


        if(i-k-1>0)
            {
                 dp[i]=max( dp[i] , mx[i-k-1] + in[i] );
            }

         mx[i]=max( mx[i-1] , dp[i] );


    }

    return mx[n];

}


int main()
{

 int test;

 scanf("%d",&test);

 for(int i=0;i<test;i++)
    printf("%lld\n",solve() );

 return 0;

}
