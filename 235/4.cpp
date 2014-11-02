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

string in;
int n;
int mod;

ll memo[1<<18][100];
int nm[100][100];

ll solve(int mask , int m)
{
     ll &ans=memo[mask][m];

     if(ans!=-1)
         return ans;

      if( mask==0)
     {
         ans=(m==0);
         return ans;
     }

     ans=0;

     for(int i=0;i<n;i++)
       if( mask&(1<<i) )
        {
                if( (in[i]=='0') && (mask==(1<<n)-1) )
                     continue;

                 ans+=solve( mask^(1<<i) , nm[m][ in[i]-'0'] );
      }

     return ans;
}

/*OPtimization Needed in

 1)                ans+=solve( mask^(1<<i) , (10*m+in[i]-'0')%mod );


2)
       for(int i=0;i<10;i++)
  ``      for(int j=1;j<=cont[i];j++)
            ans=ans/j;


 */




int main()
{
 ios_base::sync_with_stdio(0);

 cin>>in>>mod;
 n=in.size();

 //precalc

   for(int i=0;i<mod;i++)
      for(int j=0;j<10;j++)
        nm[i][j]=(10*i+j)%mod;

   ll fact[20];
      fact[0]=1;

      for(int i=1;i<20;i++)
         fact[i]=fact[i-1]*i;

 //done precalc



 fill(memo,-1);

 ll ans=solve( (1<<n)-1 , 0);

 int cont[12] ; fill(cont,0);

 for(int i=0;i<n;i++)
     cont[ in[i]-'0' ]++;

 for(int i=0;i<10;i++)
      ans=ans/fact[ cont[i] ];

 cout<<ans<<endl;

 return 0;

}
