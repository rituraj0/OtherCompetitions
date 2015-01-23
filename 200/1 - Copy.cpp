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

map<int,bool> done;

bool cool( ll  time )
{
     head= save_head;
     track = save_track;

     cout<<"Here in "<<time<<endl;

     print( head.size() );
     print( track.size());

    for(int i=0;i<sz(head);i++)
    {

        ll rem = time;

        ll curr_pos = head[i];

        ll used=0;

        if( track.front()  <= head[i] )
        {
              if( track.front() < head[i] - rem )
              {

                cout<<" returning at "<<i<<"  "<<track.front()<<"  "<<head[i]<<endl;
                 return false; //no possible to erase left most
              }

              curr_pos = track.front();

              while( (!track.empty() ) && ( track.front() <= head[i] ) )
              {
                  cout<<" left  popped is "<< track.front()<<endl;
                  track.pop();

              }

               used = llabs(  curr_pos - head[i] );

              rem-=used;
        }

        ll ri8 = curr_pos + rem ;

        while( (!track.empty())&& ( track.front() <= ri8) )
        {
             cout<<" right popped is "<< track.front()<<endl;
             track.pop();
        }

        cout<<" i is "<<i<<"  "<<head[i]<<endl;
        print(rem);
        print(curr_pos);
        print(used);
        print(ri8);
    }

    return  track.empty();

}
int main()
{
 ios_base::sync_with_stdio(0);

 int hc,tc;

 cin>>hc>>tc;

 int x;

 save_head.resize(hc);

 for(int i=0;i<hc;i++)
 {
     cin>>save_head[i];
    // done[x]=true; //ramoved alreadt covered
 }


 for(int i=0;i<tc;i++)
 {
     cin>>x;

     save_track.push(x);
 }

 bool ans = -1;

 ll lo=0, hi=(1LL<<50);

 print(lo);
 print(hi);

 cout<<cool(1)<<"   ** * ** "<<endl;
  cout<<cool(2)<<"   ** * ** "<<endl;
   cout<<cool(3)<<"   ** * ** "<<endl;

 while( lo <= hi )
 {
     ll mid=(lo+hi)/2LL;

     if( 1)//cool(mid) )
     {
         //print(mid);

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
