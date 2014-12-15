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


vector<ll> A,B,C;

int main()
{
 ios_base::sync_with_stdio(0);

 int n,m;

 ll  mx=0,x;

 cin>>n;

 A.pb(0); B.pb(0);

 for(int i=0;i<n;i++)
 {
     cin>>x;
     mx=max(mx , x);

     A.pb(x);
 }

 cin>>m;

 for(int i=0;i<m;i++)
 {
     cin>>x;

     mx=max( mx , x);

     B.pb(x);
 }

 mx++;

 A.pb(mx*2LL); B.pb(mx*2LL);

 for(int i=0;i<A.size();i++)
    C.pb( A[i]);

 for(int i=0;i<B.size();i++)
     C.pb( B[i]);

 sort( A.begin() , A.end() );
 sort( B.begin() , B.end() );
 sort( C.begin() , C.end() );

 ll a=0,b=0;
 ll ans=-(1LL<<60);

 for(int i=0;i<sz(C);i++)
 {
     ll low = C[i]; // <=low le aaya to d points

     //find pos  in A
      int posA=-1;
      int lo=0,hi=sz(A)-1;

      while(lo<=hi)
      {
          int mid= (lo+hi)/2;

          if(  A[mid] <= low)
          {
              posA=mid;
              lo=mid+1;
          }
          else
          {
              hi=mid-1;
          }
      }

      //find pos on B

      int posB=-1;

      lo = 0 ; hi =sz(B) - 1 ;

      while(lo<=hi)
      {
          int mid= (lo+hi)/2;

          if(  B[mid] <= low)
          {
              posB=mid;
              lo=mid+1;
          }
          else
          {
              hi=mid-1;
          }
      }

      //decide

      ll ap=posA*2LL + (n-posA)*3LL;
      ll bp=posB*2LL + (m - posB)*3LL;

      if( ap - bp > ans )
      {
          ans=ap-bp;
          a=ap;
          b=bp;
      }
     else
     {
         if( ap-bp == ans )
             if( ap > a)
             {
                 a=ap;
                 b=bp;
             }
     }
 }

 cout<<a<<":"<<b<<endl;





 return 0;

}
