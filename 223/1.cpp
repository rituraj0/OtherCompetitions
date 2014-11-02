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


struct node
{
    ll st,ed;
    bool add;
    int val;
    ll pref,cont;

    node( ll a , ll b,  bool d, ll e , ll p , ll c)
    {
        st=a; ed=b; add=d; val=e ; pref=p ; cont=c;
    }
    node()
    {

    }
};

node all[100009];
int n;
vector<int> elem;


ll solve( ll in)
{
      int lo=1,hi=n;
      int ans;

      while(lo<=hi)
      {
          int mid=(lo+hi)/2;

          if( (all[mid].st <= in) && (in<=all[mid].ed) )
          {
               ans=mid;
               break;
          }
         else if( all[mid].ed < in)
         {
             lo=mid+1;
         }
         else
         {
             hi=mid-1;
         }
      }

      if( all[ans].add)
         return all[ans].val;

      ll off=( in - all[ans-1].ed)%all[ans].pref;

      if(off==0)
         off=all[ans].pref;

      return elem[off];
}

int main()
{
 ios_base::sync_with_stdio(0);

 all[0]=node(0,0,0,0,0,0);
 elem.pb(-1);

 cin>>n;

 ll t,x,y;

 for(int i=1;i<=n;i++)
 {
      cin>>t;

      if(t==1)
      {
          cin>>x;

          all[i]=node( all[i-1].ed+1 , all[i-1].ed+1 , true,x, 0,0);
      }
     else
     {
         cin>>x>>y;

         all[i]=node( all[i-1].ed+1 , all[i-1].ed+x*y , false,-1, x, y);

     }
 }

 for(int i=1;i<=n;i++)
 {
       if( elem.sz > 100000)
         break;

       if( all[i].add)
         elem.pb( all[i].val);
       else
       {
            for(int c=1;c<=all[i].cont;c++)
            {
                        if( elem.sz > 100000)
                            break;

                    for(int j=1;j<=all[i].pref;j++)
                         elem.pb( elem[j] );
            }
       }
 }


// for(int i=1;i<elem.sz;i++)
//     cout<<elem[i]<<" ";
//
//
//     cout<<"Now query section\n";

     int Q;

     cin>>Q;

     for(int i=1;i<=Q;i++)
     {
         cin>>x;

         cout<<solve(x)<<" ";
     }

 return 0;

}
