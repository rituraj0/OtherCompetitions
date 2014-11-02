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

 int test,n;
 string in;

 cin>>test;

 while(test--)
 {
    cin>>n>>in;

    bool mila[3];fill(mila,0);

    for(int i=0;i<n;i++)
         if( in[i]=='Y')
            {
                mila[0]=true;
            }
           else if( in[i]=='I')
           {
               mila[1]=true;
           }
           else
           {
               mila[2]=true;
           }

     if( mila[0])
        cout<<"NOT INDIAN\n";
     else if( mila[1])
        cout<<"INDIAN\n";
     else
        cout<<"NOT SURE\n";
 }

 return 0;

}
