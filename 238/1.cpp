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

   int x,n;

   scanf("%d",&n);
   
   int ans=0;

    for(int i=1;i<=n;i++)
         for(int j=1;j<=n;j++)
       {
            scanf("%d",&x);
            if(i==j)
                 ans+=x;
       }

       ans=ans%2;

      int Q,op;

      scanf("%d",&Q);

        for( int i=0;i<Q;i++)
        {
            scanf("%d",&op);


             if(op==3)
             {
                printf("%d",ans);
             }
            else
            {
                ans=1-ans;
            }
        }



 return 0;

}
