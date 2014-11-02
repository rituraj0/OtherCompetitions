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


int main()
{
 ios_base::sync_with_stdio(0);

 ll n,a,b;

 ll x;

 cin>>n>>a>>b;

 for(int i=0;i<n;i++)
 {
     cin>>x;

      ll mn=(x*a)/b;

      ll lo=0,hi=x;
      ll ans=x;

      while(lo<=hi)
      {
          ll mid=(lo+hi)/2;

          ll tp=(mid*a)/b;

          if(tp==mn)
          {
              ans=mid;
              hi=mid-1;
          }
          else if( tp < mn)
          {
              lo=mid+1;
          }
          else
          {
              hi=mid-1;
          }
      }

      cout<<x-ans<<" ";
 }



 return 0;

}
