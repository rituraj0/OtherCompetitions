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

void solve()
{

    ll n;


 ll ans=0;


 cin>>n;


 if(n==1)
 {
     cout<<"4\n";
     return;
 }

 if(n==0)
 {
     cout<<"1\n";
     return;
 }

 ll last=floor( sqrt( n*n-(n-1)*(n-1) ) );

  if(last-1>=0)
      ans+=max( (ll)0,last);

 for(ll i=n-2;i>=1;i--)
 {
     ll curr=last;

     for(ll j=last; ; j++)
         if( i*i + j*j <=n*n)
        {
         curr=j;
        }
       else
       {
           break;
       }

       ans++;//for curr upar se

       ans+=max( (ll)0 , curr-last-2);


       last=curr;
 }

 ans*=4LL;

 ans+=4;

 cout<<ans<<endl;


}


int main()
{
 ios_base::sync_with_stdio(0);



   ll n;

   cin>>n;

   if(n==0)
     cout<<"1\n";
   else
   {
        ll tp=n*sqrt(2);
        cout<<4LL*tp<<endl;
   }


 return 0;

}
