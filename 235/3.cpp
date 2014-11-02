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

 int on, z;

 cin>>z>>on;



 if( on >= z )
 {

         if( on > 2*z+2)
         {
             cout<<"-1\n";
              return 0;
         }

         vector<int> oc(z+1,on/(z+1) ) ;

         for(int i=0;i<on%(z+1);i++)
             oc[i]++;

         for(int i=0;i<z;i++)
         {
              string tp( oc[i],'1');

              cout<<tp<<"0";
         }

         string tp(oc[z],'1');

          cout<<tp<<endl;

          return 0;
 }

  if( on < z-1 )
  {
      cout<<"-1\n";
      return 0;
  }

  for(int i=0;i<z+on;i++)
      if(i&1)
       cout<<"1";
      else
         cout<<"0";

     cout<<"\n";
      return 0;

 return 0;

}
