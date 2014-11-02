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


vector<int> id[1<<17];

vector< pair<int,int> > ans;

int main()
{
 ios_base::sync_with_stdio(0);

  ll mx=0;

  ll n,k;

  cin>>n>>k;

   ll x;

  for(int i=0;i<n;i++)
  {
      cin>>x;

      mx=max(mx,x);

      id[x].pb(i+1);
  }

//  -1 if
//1) 0 != 1
//2) any form o to mx is absent
//2) if prev*k < prev+1

  if( id[0].sz!=1)
  {
      cout<<"-1\n";
      return 0;
  }

  for(int i=0;i<=mx;i++)
      if( id[i].sz==0)
    {
      cout<<"-1\n";
      return 0;
    }

   for(int i=1;i<=mx;i++)
      if( id[i].sz>id[i-1].sz*k)
   {
      cout<<"-1\n";
      return 0;
   }

   if( k==1 && mx >= 2)
   {
        cout<<"-1\n";
        return 0;
   }



   for(int i=1;i<=mx;i++)
   {
          for(int j=0;j<id[i].sz;j++)
          {
                 int prev;

                   if(i>1)
                    prev=id[i-1][j/(k-1)];
                    else
                     prev=id[i-1][j/(k)];

                 ans.pb( mp(prev,id[i][j]) );
          }
   }

   cout<<ans.sz<<endl;

   for(int i=0;i<ans.sz;i++)
     cout<<ans[i].X<<" "<<ans[i].Y<<endl;


   return 0;

}
