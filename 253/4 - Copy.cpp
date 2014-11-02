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

int n;
double in[200];

double memo[200];
bool done[200];

double memo2[200];
bool done2[200];

double mini(int);
double maxi(int);

double maxi( int id)
{
     if(id==0) return 0.0;

     if( done[id]) return memo[id];

     done[id]=true;

     double ans=0;

     double curr=in[id];

     double prev=maxi(id-1);
     double op1=prev*(1-curr) + (1-prev)*curr;
     double op2=prev;

     ans=max( ans , max(op1,op2) );

      prev=mini(id-1);
      op1=prev*(1-curr) + (1-prev)*curr;
      op2=prev;

      ans=max( ans , max(op1,op2) );

      prev= ( mini(id-1) + maxi(id-1) )/2.0;
      op1=prev*(1-curr) + (1-prev)*curr;
      op2=prev;

      ans=max( ans , max(op1,op2) );

     return memo[id]=ans;
}


double mini( int id)
{
     if(id==0) return 0.0;

     if( done2[id]) return memo2[id];

     done2[id]=true;

     double ans=10000.000;

     double curr=in[id];

     double prev=maxi(id-1);
     double op1=prev*(1-curr) + (1-prev)*curr;
     double op2=prev;

     ans=min( ans , min(op1,op2) );

      prev=mini(id-1);
      op1=prev*(1-curr) + (1-prev)*curr;
      op2=prev;

      ans=min( ans , min(op1,op2) );

     return memo2[id]=ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 cin>>n;

 for(int i=1;i<=n;i++)
     cin>>in[i];

     fill( done , 0);
     fill(done2,0);

     printf("%0.10lf",maxi(n));

 return 0;

}
