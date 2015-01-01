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

 vector<int> rem;

 int as=0,bs=0,x;

 int N,m;

 cin>>N;

 for(int k=1;k<=N;k++)
 {
   cin>>m;

   int cn=m/2;

   for(int i=1;i<=cn;i++)
   {
       cin>>x;
       as+=x;
   }

   if( m%2)
   {
       cin>>x;
       rem.pb(x);
   }

    for(int i=1;i<=cn;i++)
   {
       cin>>x;
       bs+=x;
   }

 }


 sort( rem.begin() , rem.end() );
  x=rem.size();
 for(int i=x-1;i>=0;i-=2)
    as+=rem[i];

 for(int i=x-2;i >=0;i-=2)
    bs+=rem[i];

 cout<<as<<" "<<bs<<endl;

 return 0;

}
