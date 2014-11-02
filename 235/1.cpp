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

 bool in[5000]; fill(in,0);

 int n,k;

 cin>>n>>k;

 for(int i=0;i<k;i++)
 {
     int x,y,z;

     cin>>x;

     if(x==1)
     {
         cin>>y>>z;
         in[z]=in[y]=true;
     }
     else
     {
         cin>>y;
         in[y]=true;
     }
 }



  int dp[5000]; fill(dp,0);

  for(int i=1;i<n;i++)
      if( in[i]==false)
    {
          dp[i]=1+dp[i-1];
          dp[i-1]=0;
    }

     int mx=0,mn=0;

     for(int i=1;i<n;i++)
          if( dp[i] )
     {
         mx+=dp[i];

         mn+=(dp[i]/2)+ (dp[i]%2);
     }

     cout<<mn<<" "<<mx<<endl;




 return 0;

}
