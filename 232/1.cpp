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

map<int,int> mapa;
set<int> st;

ll dp[15005][550];

void  cont(int in)
{
     int ans=0;
      int tp=in;

     for(int i=2;i*i<=in;i++)
     {
          while(tp%i==0)
          {
                mapa[i]++;
                st.insert(i);
                tp=tp/i;
          }
     }

     if( tp > 1)
     {
         mapa[tp]++;
         st.insert(tp);
     }

}


int main()
{
 ios_base::sync_with_stdio(0);

 int x,n;
 int cn=0;

 cin>>n;

 for(int i=0;i<n;i++)
 {
      cin>>x;
       cont(x);
 }



    fill(dp,0);
    dp[0][0]=1;

    for(int i=1;i<15005;i++)
         for(int j=0;j<=n;j++)
    {
            if(j==0)
            {
                dp[i][j]=1;
            }
           else
           {
               dp[i][j]=(dp[i-1][j-1]+dp[i-1][j])%1000000007;
           }
    }

 ll ans=1;

 for( set<int>::iterator it=st.begin();it!=st.end();it++)
 {

      int m=mapa[*it];
      ans=(ans*dp[n+m-1][n-1])%1000000007;
 }

cout<<ans<<endl;

 return 0;

}
