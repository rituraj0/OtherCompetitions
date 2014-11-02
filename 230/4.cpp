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

ll cost[3][3];
ll memo[55][3][3];

ll solve( int n, int s, int t)
{
    if(n==0)
        return 0;

    if( memo[n][s][t]!=-1)
         return memo[n][s][t];

    int aux=3-s-t;

    ll ans=LONG_LONG_MAX;

    ans=min( ans , solve(n-1,s,aux) + cost[s][t] + solve(n-1,aux,t) );

    ans=min( ans , solve(n-1,s,t) + cost[s][aux] + solve(n-1,t,s) + cost[aux][t] + solve(n-1,s,t) );

    return memo[n][s][t]=ans;

}


int main()
{
 ios_base::sync_with_stdio(0);

 for(int i=0;i<3;i++)
     for(int j=0;j<3;j++)
       cin>>cost[i][j];

 int n;

 cin>>n;

 fill(memo,-1);

 cout<<solve(n,0,2)<<endl;



 return 0;

}
