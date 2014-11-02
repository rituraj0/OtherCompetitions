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

#define mod 1000000007

int dp[26];
int id[100009];

int ans[100009][26][26];

int main()
{

 fill(id,0);

 dp[0]=1;
 dp[1]=2;

 id[1]=0;id[2]=1;

 for(int i=2;i<=24;i++)
      { dp[i]=dp[i-1]+dp[i-2];
         id[ dp[i] ]=i;
      }

  fill(ans,0);

  for(int i=0;i<=24;i++)//i th coind
     for(int j=0;j<=24;j++)//forbidden
       ans[0][i][j]=1;

       int x,y;

  for(int i=1;i<=100000;i++)//value
     for(int j=0;j<=24;j++)//using this coin
         for(int k=0;k<=24;k++) // forbid
        {
            x=0;

           if(j!=k)
            x=(i-dp[j]>=0)?ans[i-dp[j] ][j][k]:0;

           y=(j>=1)?ans[i][j-1][k]:0;

           ans[i][j][k]=(x+y)%mod;
        }


        int q;


        scanf("%d",&q);

        int n,k;

        for(int i=1;i<=q;i++)
        {
            scanf("%d%d",&n,&k);
             k=id[k];
            printf("%d\n",ans[n][24][k]);

        }






 return 0;

}
