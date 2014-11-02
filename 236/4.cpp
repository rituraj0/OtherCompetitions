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

map<int,bool> bad;
int gc[5005],in[5005];

map<int,int> memo;

int calc( int val)
{
      if( val==1) return 0;

      if( memo.count(val) ) memo[val];

      int pf=-1;

      for(int x=2;x*x<=val;x++)
           if(val%x==0)
         {
           pf=x;
           break;
          }

       if(pf==-1)
          pf=val;

       if( bad.count(pf) )
           return memo[val]=calc(val/pf)-1;

           return memo[val]=calc(val/pf)+1;
}

int main()
{
 ios_base::sync_with_stdio(0);

   int n,m;

 cin>>n>>m;

 for(int i=0;i<n;i++)
     { cin>>in[i];

       if(i==0)
          gc[i]=in[i];
        else
        gc[i]=__gcd( gc[i-1] , in[i]);
     }

       int x;

  for(int i=0;i<m;i++)
  {
      cin>>x;
      bad[x]=true;
  }

     int div=1,ans=0;

     for(int i=n-1;i>=0;i--)
     {
          gc[i]/=div;

          if( calc(gc[i]) < 0 )
          {
              div*=gc[i];
          }

          ans+=calc(in[i]/div);
     }

     cout<<ans<<endl;





 return 0;

}
