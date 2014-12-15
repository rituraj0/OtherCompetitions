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




pair<ll,ll> get_cont( ll a)
{
    pair<ll,ll> ans=mp(0,0);

    while( (a>1) && (a%2==0 ))
    {
        ans.X++;
        a=a/2LL;
    }

    while( (a>1) && (a%3 == 0))
    {
        ans.Y++;
        a=a/2LL;
    }

    return ans;
}

int main()
{
 ios_base::sync_with_stdio(0);

 ll div3[55],mul3[55],div2[55];

 div3[0]=mul3[0]=div2[0]=1;

 for(int i=1;i<55;i++)
 {
     div3[i]=div3[i-1]*3LL;

     mul3[i]=div2[i]=div2[i-1]*2LL;
 }

 ll a,b,c,d;

 cin>>a>>b>>c>>d;

 pair<ll,ll> A = get_cont(a*b) , B = get_cont(c*d);

 int cont=(1<<20);

 for(int i=0;i<=A.Y;i++)//3 cont in
    for(int j=0;j<=A.X + i; j++)//2 cont
      for(int k=0;k <= B.Y; k++)// 3 cont in other number
        for(int l=0;l <=B.Y+k; l++) //2 count in other
        {

        }


   if( cont == (1<<20))
    cout<<"-1"<<endl;
   else
    {
        cout<<cont<<endl;
        cout<<a<<" "<<b<<endl;
        cout<<c<<" "<<d<<endl;
    }

   return 0;

}
