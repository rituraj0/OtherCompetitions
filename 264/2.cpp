#include <bits/stdc++.h>
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
#define print(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

string rem;

int solve( string in)//
{

   // cout<<in<<"   ";

  if( in.find('1')==string::npos)
 {
    rem="";
    return 0;
 }

    int x=0;

    while(in[x]=='0')
    {
        x++;
    }

    //now +1,-1

    int n=in.sz;
    int ans=2;//seek here & open xthe leter

    while(x<n)
    {

         if((x+1)<n)
              if( in[x+1]=='1')
              {
                  x++;
                  ans++;
                  continue;
              }

           if((x+2)<n)
              if( in[x+2]=='1')
              {
                  x+=2;
                  ans+=2;
                  continue;
              }

              break;
    }

   // cout<<ans<<endl;


    rem=in.substr(x+1);

    return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 int n;

 string in="";


 cin>>n;

 for(int i=1;i<=n;i++)
 {
     char  x;
     cin>>x;
     in+=x;
 }

if( in.find('1')==string::npos)
{
    cout<<"0\n";
    return 0;
}

 int ans=0;

 rem=in;

 while(rem!="")
 {
        ans+=solve(rem);
 }

//we ssumed every seek
 cout<<(ans-1)<<endl;

 return 0;

}
