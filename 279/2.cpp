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




pair<ll,ll> get_cont( ll a)//return number of  2's & 3's
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
        a=a/3LL;
    }

    return ans;
}


pair<ll,ll> solve2( ll a , ll b , ll cont)
{
    while( cont > 0)
    {
         if( a % 2LL ==0 )
         {
             a =a/2LL;
             cont--;
             continue;
         }

         if( b % 2LL ==0)
         {
             b = b/2LL;
             cont--;
             continue;
         }
    }

    return mp(a,b);
}


pair<ll,ll> solve3( ll a , ll b , ll cont)
{
    while( cont > 0)
    {
         if( a % 3LL ==0 )
         {
             a =a/3LL;
             a= a*2LL;
             cont--;
             continue;
         }

         if( b % 3LL ==0)
         {
             b = b/3LL;
             b=b*2LL;
             cont--;
             continue;
         }
    }

    return mp(a,b);
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

// cout<<A.X<<"  "<<A.Y<<"  "<<B.X<<"  "<<B.Y<<endl;


 ll p=(1e10),q=(1e10),r=(1e10),s=(1e10);

 for(int i=0;i<=A.Y;i++)//3 cont in
    for(int j=0;j<=A.X + i; j++)//2 cont
      for(int k=0;k <= B.Y; k++)// 3 cont in other number
        for(int l=0;l <=B.X+k; l++) //2 count in other
        {
            ll  x = (((a*b)/div3[i])*mul3[i])/div2[j];

            ll  y =  (((c*d)/div3[k])*mul3[k])/div2[l];

            if( x == y )
            {
                if( i + j + k + l < p + q + r +s )
                {
                    p = i; q = j ; r=k ; s= l;
                }
            }
        }


    if( p == (1e10))
    {
        cout<<"-1\n";
        return 0;
    }

    cout<<p+q+r+s<<endl;


   pair<ll,ll> ap=solve3(a,b,p);
               ap=solve2( ap.X , ap.Y ,q);


   pair<ll , ll > cp =solve3(c,d,r);
                  cp=solve2(cp.X , cp.Y ,s);


   cout<<ap.X<<" "<<ap.Y<<endl;
   cout<<cp.X<<" "<<cp.Y<<endl;
   return 0;

}
