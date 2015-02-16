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

ll n,mod,k;

ll memo[1005][105][2][2];

ll rem[1010];//10^P % K


ll solve( int pos , int md , int mila , int non)//non for non_zero used
{
    if( pos == 0 )
    {
        return  ( (mila==1));
    }

    if( memo[pos][md][mila] [non]!= -1)
        return memo[pos][md][mila][non];

    memo[pos][md][mila][non] = 0;
    ll ans=0;

    for(int i=0;i<10;i++)
    {
        if(i==0 && pos == 1 )//x cant start with 0
            continue;

        ll new_md = (i*rem[n-pos] + md)%k;

        int new_non = non;
        if( i > 0)
            new_non = 1;

        int new_mila = 0;
        if(  mila == 1)
             new_mila =1;
        else if( (new_non == 1 ) &&(new_md==0) )
              new_mila = 1;

        ans = ( ans + solve(pos-1, new_md , new_mila , new_non) )%mod;

        //cout<<i<<"  "<<new_md<<" "<<new_mila<<"  "<<new_non<<endl;
    }

    return memo[pos][md][mila][non] = ans;
}




int main()
{
 ios_base::sync_with_stdio(0);

 fill(memo,-1);

 cin>>n>>k>>mod;

  rem[0]=1;

  for(int i=1;i<1005;i++)
    rem[i]=(rem[i-1]*10)%k;

 cout<<solve(n,0,0,0)<<endl;

 return 0;

}
