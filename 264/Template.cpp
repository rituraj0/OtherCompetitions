#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define sz size()
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

int  tobinary( int in)
{
    string ans="";

    while( (in>0) || (( (int)ans.size())<60) )
    {
        if(in&1)
            ans="1"+ans;
        else
            ans="0"+ans;
        in=in/2;
    }

    int cn=0;
    int i=ans.sz;
    i--;

    while(i>0)
    {
        if( ans[i]=='0')
             cn++;
        else
            break;

            i--;
    }
    return cn;
}

int main()
{
//    for(int i=0;i<100;i++)
//         cout<<i<<"  "<<tobinary(i)<<endl;


 int mx=(1<<20);

 for(int i=mx-20;i<mx;i++)
     cout<<i<<"  "<<tobinary(i)<<endl;

 cout<<" ** ** "<<mx<<"  "<<tobinary(mx)<<endl;


 for(int i=mx+1;i<mx+20;i++)
       cout<<i<<"  "<<tobinary(i)<<endl;



 return 0;

}
