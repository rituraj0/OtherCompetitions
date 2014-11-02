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


int maxi[1<<20];
int mx=0;

int mini[1<<20];
int mn=0;


int in[1<<20];
int n,x,y;

void max_cal(int k)
{

    mx=0;

    deque<int>  Q;

    int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!Q.empty()) && (in[i] >= in[Q.back()]) )
            Q.pop_back();

        Q.push_back(i);
    }

    for ( ; i < n; ++i)
    {

         int tp= in[Q.front()];
            maxi[mx++]=tp;

        while ( (!Q.empty()) && (Q.front() <= i - k) )
            Q.pop_front();

        while ( (!Q.empty()) && (in[i] >= in[Q.back()]) )
            Q.pop_back();

         Q.push_back(i);
    }

     int tp= in[Q.front()] ;
      maxi[mx++]=tp;
}

void min_cal(int k)
{

    mn=0;

    deque<int>  Q;

    int i;
    for (i = 0; i < k; ++i)
    {
        while ( (!Q.empty()) && (in[i] <= in[Q.back()]) )
            Q.pop_back();

        Q.push_back(i);
    }

    for ( ; i < n; ++i)
    {

         int tp= in[Q.front()];
            mini[mn++]=tp;

        while ( (!Q.empty()) && (Q.front() <= i - k) )
            Q.pop_front();

        while ( (!Q.empty()) && (in[i] <= in[Q.back()])  )
            Q.pop_back();

         Q.push_back(i);
    }

     int tp= in[Q.front()] ;
      mini[mn++]=tp;
}


int maxn=(1<<20);

long long bit[1<<20];

void add( int pos, int val)
{
     while( pos < maxn )
      { bit[pos]+=val;
       pos+=(pos & (-pos) );
      }
}

long long read( int pos)
{
     long long ans=0;

     while( pos > 0 )
       { ans+=bit[pos];
        pos-=( pos & (-pos) );
        }

   return ans;
}



bool solve(int len)
{
    max_cal(len);
    min_cal(len);

    fill(bit,0);

    for(int i=0;i<len-1;i++)
         add(in[i],1);

     int curr=len-1;
     int del=0;

    for(int i=0;i<mx;i++)
    {
         add(in[curr],1);

        int a1=mini[i]+x;
        int b1=maxi[i]-y;

         int a=read(a1+1);//a1 se chhota
         int b=read(b1);//b1 se bada inclu

         int cn=a-b;

          add( in[del] ,-1);
          del++;
          curr++;

         if(cn>0)
             return true;
    }



    return false;
}



int main()
{
  scanf("%d%d%d",&n,&x,&y);

  for(int i=0;i<n;i++)
     scanf("%d",&in[i]);


    int lo=1,hi=n;

    int ans=0;

    while(lo<=hi)
    {
        int mid=(lo+hi)/2;

        if( solve(mid) )
        {
            ans=mid;
            lo=mid+1;
        }
        else
        {
            hi=mid-1;
        }
    }

     printf("%d\n",ans);



 return 0;

}
