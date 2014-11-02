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

#define fill(a,val) memset(a ,val, sizeof(a) );
/*Solution code starts here */

char sub='-',add='+',mul='*';

void print( int a, char op , int b , int c)
{
  cout<<a<<" "<<op<<" "<<b<<" "<<"="<<" "<<c<<endl;
}

void solve( int n)
{
    if(n==4)
    {
        print(1,mul,2,2);
        print(2,mul,3,6);
        print(6,mul,4,24);
        return;
    }

    if(n==5)
    {
        print(5,mul,4,20);
        print(3,sub,1,2);
        print(2,add,2,4);
        print(20,add,4,24);
        return;
    }

    if(n==6)
    {
     print(5,sub,6,-1);
     print(1,add,-1,0);
     print(2,add,0,2);
     print(2,mul,3,6);
     print(6,mul,4,24);
     return;
    }

    if(n==7)
    {
        print(7,mul,6,42);
        print(5,mul,4,20);
        print(42,sub,20,22);
        print(2,sub,1,1);
        print(3,sub,1,2);
        print(22,add,2,24);
        return;
    }
}

int main()
{
 ios_base::sync_with_stdio(0);


 int n;

 while(1)
 {

    cin>>n;

     if(n<=3)
     {
         cout<<"NO"<<endl;
         return 0;
     }

     cout<<"YES"<<endl;

     while(n>7)
     {
            print(n,sub,n-1,1);
            print(n-3,sub,n-2,-1);
            print(-1,add,1,0);
            print(0,add,n-4,n-4);
            n-=4;
     }

     solve(n);

 }

 return 0;

}
