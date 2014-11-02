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


vector<ll> ev,od;
vector<ll> ans[1<<20];

int main()
{
 ios_base::sync_with_stdio(0);

 ll n,k,p,x;

 cin>>n>>k>>p;

 for(int i=0;i<n;i++)
 {
     cin>>x;

     if(x&1)
         od.pb( x );
     else
         ev.pb( x);
 }

  ll odreq=k-p;
  ll odaval=od.sz;

  if( (odreq%2)!=( odaval%2 ) )
  {
      cout<<"NO\n";
      return 0;
  }

  if( odreq > odaval )
  {
      cout<<"NO\n";
      return 0;
  }

   int used=0;

  for(int i=0;i<odreq;i++)
     { ans[i].pb( od[i] );
        used++;
     }

   int j=odreq;

   int done=odreq,odused=odreq;

   int evendone=0;

   for(int i=odreq;i<k;i++)//bas even bcacha hoga
   {
          if( j  >= odaval-1 )
             break;

          ans[i].pb( od[j] );
          ans[i].pb( od[j+1] );
          used+=2;

          odused+=2;

          done++;
          j+=2;

          evendone++;
   }

 //now even wala push kar rahe hai
   j=0;
  for(int i=done;i<k;i++)
  {
        if( j >= ev.sz)
             break;

         ans[i].pb( ev[j]);
         j++;

         evendone++;

         used++;
  }

  if( p > 0)
  {
       for(int i=j;j<ev.sz;i++)
       {
          if( ans[k-1].sz==0)
             evendone++;

           used++;
           ans[k-1].pb( ev[i] );


       }

       for(int i=odused;i<od.sz;i++)
       {
          if( ans[k-1].sz==0)
            evendone++;

           used++;
           ans[k-1].pb( od[i]);
       }
  }
  else
  {
       for(int i=odused;i<od.sz;i++)
       {
           used++;
           ans[k-1].pb( od[i]);
       }
  }

  if( used!=n)
  {
      cout<<"NO\n";
      return 0;
  }

   if( evendone != p)
    {
      cout<<"NO\n";
      return 0;
    }

  cout<<"YES\n";

  for(int i=0;i<k;i++)
  {
       cout<<ans[i].sz<<" ";
        for(int j=0;j<ans[i].sz;j++)
             cout<<ans[i][j]<<" ";

        cout<<endl;
  }


 return 0;

}
