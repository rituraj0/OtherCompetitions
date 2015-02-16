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
vector<ll>  arr[5];
vector<ll>  ans[5];
int n,m;
ll maxi;

deque<ll>  Q;


void printt( vector<ll> in)
{
    for(int i=0;i<sz(in);i++)
        cout<<in[i]<<" ";

    cout<<"    \n";
}

void slide( int id , int k)//n is size , k is len
{
   //clean it
    while(!Q.empty())
         Q.pop_back();

    ans[id].clear();

    int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!Q.empty()) && arr[id][i] >= arr[id][Q.back()])
            Q.pop_back();

        Q.push_back(i);
    }

    for ( ; i < n; ++i)
    {
        ans[id].pb( arr[id][Q.front()] );

        while ( (!Q.empty()) && Q.front() <= i - k)
            Q.pop_front();

        while ( (!Q.empty()) && arr[id][i] >= arr[id][Q.back()])
            Q.pop_back();

        Q.push_back(i);
    }

    ans[id].pb( arr[id][Q.front()] );
}

ll spent[5];

bool cool( int len )
{
    if( len == 0)
    {
        fill(spent,0);
        return true;
    }


  //  cout<<"lenght is  "<<len<<endl;

   for(int i=0;i<m;i++)
      {
          slide(i,len);

        //  printt( ans[i] );
      }

   bool  mila = false;

   for(int i=0;i< sz(ans[0]) ;i++)
   {
        ll req = 0;

        for(int j=0;j<m;j++)
          req+=ans[j][i];

        if( req <= maxi)
        {
            for(int j=0;j<m;j++)
                spent[j]=ans[j][i];

            return true;
        }

   }

   return false;
}

int main()
{
 ios_base::sync_with_stdio(0);

 ll a;

 cin>>n>>m>>maxi;

 for(int i=0;i<n;i++ )
 {
      for(int  j=0;j<m;j++)
      {
          cin>>a;
          //print(a);
          arr[j].pb(a);
      }
 }

//for(int i=0;i<m;i++)
//    printt( arr[i] );
//
//
//slide(0,2);
//slide(1,2);
// printt(ans[0]);
// printt(ans[1]);



 int lo = 0 , hi =n;

 while( lo < hi )
 {
     int mid =(lo+hi+1)/2;

     if( cool(mid) )
     {
         lo = mid;

        // print(mid);
     }
     else
     {
         hi = mid -1;
     }
 }

 for(int i=0;i<m;i++)
    cout<<spent[i]<<" ";

 return 0;

}
