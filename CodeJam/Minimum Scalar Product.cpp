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

#define fi freopen("A-large-practice.in","r",stdin)
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

ll a[900],b[900];

void solve( int t)
{
     int n;

     cin>>n;

     for(int i=0;i<n;i++)
         cin>>a[i];

     for(int i=0;i<n;i++)
         cin>>b[i];

     sort(a,a+n);

     sort(b,b+n,greater<int>() );

     ll ans=0;

     for(int i=0;i<n;i++)
         ans+=a[i]*b[i];

     cout<<"Case #"<<t<<":"<<" "<<ans<<endl;
}

int main()
{
 ios_base::sync_with_stdio(0);

 fi;fo;

 int test;

 cin>>test;

  for(int i=1;i<=test;i++)
     solve(i);

 return 0;

}
