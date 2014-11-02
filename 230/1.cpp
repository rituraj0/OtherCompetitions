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

string  xx="nineteen";

int main()
{
 ios_base::sync_with_stdio(0);

 string in;

 cin>>in;

 int aval[30]; fill(aval,0);

 for(int i=0;i<in.size();i++)
      aval[ in[i] - 'a']++;

  int req[30]    ; fill(req,0);

  for(int i=0;i<xx.sz;i++)
      req[ xx[i]-'a']++;


  int ans=0;


   while(1)
   {
        bool mila=true;

        for(int i=0;i<30;i++)
              if( req[i] )
              {
                 if( req[i] > aval[i] )
                    mila=false;

                    aval[i]-=req[i];
              }


         if(!mila)
              break;

         ans++;

         aval[ 'n'-'a']++;
   }


 cout<<ans<<endl;



 return 0;

}
