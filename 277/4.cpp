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


ll sum , len;

int main()
{
 ios_base::sync_with_stdio(0);



 cin>>len>>sum;

 if( len ==1)
 {
     if( (0<=sum)&&(sum<=9))
     {
         cout<<sum<<" "<<sum<<endl;
         return 0;
     }

     cout<<"-1 -1"<<endl;
     return 0;
 }

 ll mins=1,maxs=len*9LL;

 if( (sum < mins) || (maxs < sum))
 {
     cout<<"-1 -1"<<endl;
     return 0;
 }

 string mini=string(len,'0');
 string maxi=mini;

 maxi[0]=mini[0]='1';

 //build mini
 int tp=sum-1;

 for(int i=len-1;i>=0;i--)
      {
         int add = min(9,tp);
         mini[i]=mini[i] + add;
         tp-=add;
      }

 //build maxi

 tp = sum -1;

 for(int i=0;i<len;i++)
 {
     int add= min( tp , 9-(maxi[i]-'0'));
     maxi[i]=maxi[i]+add;
     tp-=add;
 }

 cout<<mini<<" "<<maxi<<endl;


 return 0;

}
