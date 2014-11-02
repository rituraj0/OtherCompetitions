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

int X[1<<20];
bool aval[1<<20];
bool done[1<<20];

int s=1000*1000;


int main()
{
 ios_base::sync_with_stdio(0);

  fill(aval,1);

 int n;

 scanf("%d",&n);

 for(int i=1;i<=n;i++)
     {
         scanf("%d",&X[i]);

         aval[ X[i] ]=false;
     }


 vector<int> ans;

 fill(done,0);

 int cont=0;

 for(int i=1;i<=n;i++)
      if( !done[ X[i] ] )
      {
            if( aval[ s + 1 - X[i] ] )
            {
                ans.pb(   s + 1 - X[i] );
                aval[ s + 1 - X[i] ]=false;
                continue;
            }
           else
           {
                cont++;

                done[ X[i] ]=done[  s + 1 - X[i] ]=true;
                aval[ X[i] ]=aval[  s + 1 - X[i] ]=false;
           }
      }

//        cout<<cont<<endl;

      vector<int> add;

      for(int i=1;i<=s;i++)
          if( aval[i] && aval[ s -i + 1 ] )
           {

                if(add.sz==cont*2)
                     break;

                add.pb(i); add.pb( s-i+1);

                aval[i]=aval[s-i+1]=false;

            }


      for( int i=0;i<add.sz;i++)
         ans.pb( add[i]);


     printf("%d\n",ans.sz);
     for(int i=0;i<ans.sz;i++)
          printf("%d ",ans[i]);

 return 0;

}
