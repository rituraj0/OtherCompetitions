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

map<string,string> mapa;


int main()
{
 ios_base::sync_with_stdio(0);

 ll x=-2*(1e9),y=2*(1e9);


 //convert to y

 mapa[">"]="<=";
 mapa["<="]=">";

 mapa["<"]=">=";
 mapa[">="]="<";

 int n;

 cin>>n;

 string ch,b;

 ll a;


 for(int i=0;i<n;i++)
 {
      cin>>ch>>a>>b;

         if(b=="N")
             ch=mapa[ch];

         if(ch=="<")
         {
            y=min(y,a-1);
         }
        else if( ch=="<=")
        {
            y=min(y,a);
        }
        else if( ch==">")
        {
            x=max(x,a+1);
        }
        else
        {
            x=max(x,a);
        }

 }

 if( y  < x)
 {
     cout<<"Impossible\n";
 }
 else
 {
     cout<<x<<endl;
 }

 return 0;

}
