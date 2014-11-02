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

#define maxn  1300000

bool prime[maxn];


int main()
{
 ios_base::sync_with_stdio(0);

 int n,k;

 cin>>n>>k;

 if( n==1)
 {
     if(k==0)
         cout<<"1\n";
     else
         cout<<"-1\n";
     return 0;
 }


 int mn=n/2;

 if(mn > k)
    {
         cout<<"-1\n";
         return 0;
    }

    fill(prime,true);

    prime[0]=prime[1]=0;

    for(int i=2;i<maxn;i++)
         if( prime[i])
    {
            for(int j=2*i;j<maxn;j+=i)
                 prime[j]=false;
    }

    int fs=k-(mn-1);

    map<int,bool> done;

   vector<int> ans;

   ans.pb(fs); done[fs]=true;
   ans.pb(fs*2); done[fs*2]=true;

   for(int i=2;i<maxn;i++)
   {
         if( ans.size()==n)
             break;

       if( prime[i])
          if( done.count(i)==0)
          {
              ans.pb(i);
              done[i]=true;
          }
   }


   for(int i=0;i<ans.sz;i++)
     cout<<ans[i]<<" ";

//   //cout cheking
//   int sum=0;
//
//   for(int i=0;i<ans.sz-1;i+=2)
//      sum+=__gcd(ans[i],ans[i+1]);
//
//   cout<<" sun is "<<sum<<endl;






 return 0;

}
