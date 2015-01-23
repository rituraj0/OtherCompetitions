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

vector<ll> save_head,head;

queue<ll> save_track,track;

bool cool( ll  time )
{
     head= save_head;
     track = save_track;

    for(int i=0;i<sz(head);i++)
    {

        if( track.empty() )
             return true;

        if( track.front()  <= head[i] )
        {
              if( track.front() < head[i] - time )
              {
                return false; //no possible to erase left most
              }

              ll left = track.front();

              ll op1 = time - 2LL*( head[i] - left );//lo left first

              ll op2 = (time - ( head[i]-left) )/2LL + head[i];//go to right first

              ll ri8 = max(op1,op2);

              while( (!track.empty() ) && ( track.front() <= max(ri8,head[i] ) ) )
              {
                  track.pop();
              }

        }
       else
       {
              ll dy  = time;
              ll ri8 = head[i] + dy ;

              while( (!track.empty())&& ( track.front() <= ri8) )
              {
                  track.pop();
              }
       }

    }

    return  track.empty();

}
int main()
{
 ios_base::sync_with_stdio(0);

 int hc,tc;

 cin>>hc>>tc;

 ll x;

 save_head.resize(hc);

 for(int i=0;i<hc;i++)
 {
     cin>>save_head[i];
 }


 for(int i=0;i<tc;i++)
 {
     cin>>x;

     save_track.push(x);
 }

 ll ans = -1;

 ll lo=0, hi=(1LL<<50);

 while( lo <= hi )
 {
     ll mid=(lo+hi)/2LL;

     if( cool(mid) )
     {
        ans = mid;
         hi = mid-1;
     }
     else
     {
        lo = mid+1;
     }
 }


 cout<<ans<<endl;



 return 0;

}
