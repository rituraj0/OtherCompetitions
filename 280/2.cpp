#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz(s) ((int)(s.size()))
#define bg begin()
#define en end()
#define Y second
#define X first
typedef long long ll;
#define fi freopen("input.txt","r",stdin)
#define fo freopen("output.txt","w",stdout)
const double pi     =   acos(-1.0);
const double eps    =   1e-8;
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */


vector<string> ans;//simulate 1 sec. movement (x+y) steps

int main()
{
 ios_base::sync_with_stdio(0);

 ll n,x,y;

 cin>>n>>x>>y;

 //simualte one sec. moveent , after 1 sec , it is guranted that they would attak simultaneously

 ll cx=0,cy=0;

  int i=0;

  while(sz(ans) < x+y )
  {
    if( (cx+1)*y < (cy+1)*x )
    {
        cx++;
        ans.pb("Vanya");
    }
    else if( (cx+1)*y > (cy+1)*x)
    {
        cy++;
        ans.pb("Vova");
    }
    else
    {
        cx++; cy++;
        ans.pb("Both");
        ans.pb("Both");
    }
  }


 ll id=-1;

 for(int i=0;i<n;i++)
 {
     cin>>id;
     id--;
     id=id%(x+y);

     cout<<ans[id]<<endl;
 }

 return 0;

}
