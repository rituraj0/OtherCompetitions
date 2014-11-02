#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdlib>
#include <climits>
#include <fstream>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <map>
#include <set>
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

#define print(a) cout<<(#a)<<" = "<<a<<"  ";
#define println(a) cout<<(#a)<<" = "<<a<<"\n";
#define fill(a,val) memset(a ,val, sizeof(a) );

vector <string> parse(string s, string c)
{
  int len = c.length(), p = -len, np;
  vector <string> ans;

  do
    {
      np = s.find(c, p+len);
      ans.push_back(s.substr(p+len, np - p - len));
      p = np;
    }
  while (p != string::npos);

  return ans;
}


/*Solution code starts here */

#define maxn (20000000)

int ulta( int in)
{
    int ans=0;

     while(in>0)
     {
        ans=ans*10;
        ans+=in%10;
        in=in/10;
     }

     return ans;
}

bool prime[maxn];//i th ith odd number

bool inline cool( int in)
{

      for(int i=3;i*i<=in;i+=2)
         if( in%i==0)
          return false;


     return true;
}


int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}


bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}


int main()
{

 ll start=clock(),here;

  fill(prime,true);

  int maxreal=2*maxn;


 for(int i=1;i<maxn;i++)
     if( prime[i] )
        {
             int curr=2*i+1;
             int add=2*curr;

             for(int j=3*curr;j<maxreal;j+=add)
                 prime[j/2]=false;
        }

    int ex=0,cont=0;

    for(int i=1;i<maxn;i++)
             if( prime[i] )
               {
                    int curr=2*i+1;

                     //contion for stop
                    here=clock();

                    if( (here-start)/double(CLOCKS_PER_SEC)*1000 > 1970 )
                    {
                         break;
                    }

                     //contion for stop


                    int tp=ulta(curr);

                    if(curr==tp)
                        continue;

                      if(tp&1)
                        {

                                   if(tp<maxreal)
                                    {
                                        int x=tp/2;

                                       if( prime[x])
                                       {
                                          printf("%d\n",curr);

                                          prime[i]=prime[x]=false;
                                       }
                                   }
                                   else if( Miller(tp,1) )
                                   {
                                          printf("%d\n",curr);
                                   }
                        }

               }


 return 0;

}
