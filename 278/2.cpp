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

int dp[1<<20];
multiset<int>  ele;// to store all elemnets  in monitinic order
multiset<int> temp;//to store maxi and mini dp[[] in this in this region
vector<int> in;

int main()
{
 ios_base::sync_with_stdio(0);

int n,max_diff,min_len;

 cin>>n>>max_diff>>min_len;

 in.resize(n);

 for(ll i=0;i<n;i++)
    cin>>in[i];

 fill(dp,63);

  for(int i=0,j=0;i<n;i++)
  {
      ele.insert( in[i] );

      while( (*ele.rbegin()) - (*ele.begin()) > max_diff )
      {
          ele.erase( ele.find( in[j] ));

          if( i - j  >= min_len)
           temp.erase( temp.find(dp[j-1] ) );

           j++;
      }

      if( i - j +1 >=min_len )
         temp.insert( dp[i-min_len]);

      if( sz(temp) == 0 )
        dp[i]=(1<<20);
      else
        dp[i]=(*temp.begin())+1;
  }

  if( dp[n-1] >= (1<<20))
    cout<<"-1\n";
  else
    cout<<dp[n-1]<<endl;


  return 0;

}
