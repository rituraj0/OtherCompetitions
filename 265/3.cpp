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


int main()
{
 ios_base::sync_with_stdio(0);

 int n,x;

 string in;

 cin>>n>>x;

 cin>>in;


char p='a'+x-1;

 int i=n-1;

  in[n-1]++;

 while( (i>=0) && (i<n) )
 {
        if( in[i]==p+1)
        {
            in[i]='a';
            i--;
            in[i]++;
        }
        else if( (i>0)&& (in[i-1]==in[i]))
        {
            in[i]++;
        }
        else if ( (i>1) && ( in[i-2]==in[i]) )
        {
            in[i]++;
        }
        else
        {
            i++;
        }
 }

 if( i < 0 )
 {
     cout<<"NO"<<endl;
 }
 else
 {
     cout<<in<<endl;
 }



 return 0;

}
