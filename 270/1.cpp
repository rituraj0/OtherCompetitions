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



const ll maxi = (1<<20);

bool prime[maxi];


bool cool( int n)
{
    for(int i=2;i*i<=n;i++)
         if( n%i==0)
           return true;
}

int main()
{
 ios_base::sync_with_stdio(0);

 fill(prime,true);


 for(ll i=2;i<maxi;i++)
     if( prime[i])
        {
            for(ll j=i+i;j<maxi;j=j+i)
                 prime[j]=false;
        }

//        int cn=0;
//
//        for(int i=1;i<=1000;i++)
//              if(prime[i])
//                 cn++;
//
//
//                 print(cn);


cout<<cool(2)<<endl;



 return 0;

}
