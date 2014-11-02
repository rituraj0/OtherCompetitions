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

int dx[]={-1,-1,-1,0,0,1,1,1};
int dy[]={-1,0,1,-1,1,-1,0,1};

int val[55][55];
int in[55][55];//0 if empty ,1 if mines

bool done[55][55];

int row,col,mines;


void dfs( int x, int y)
{
     if( done[x][y])
         return ;

     done[x][y]=true;

     for(int i=0;i<8;i++)
     {
          int nx=x+dx[i];
          int ny=y+dy[i];

          if( nx < 0 || nx >=row || ny <0 || ny >=col)
           continue;

          if( val[nx][ny]==0)
             dfs(nx,ny);
     }

}

bool  process()
{
     fill(val,0);

     for(int i=0;i<row;i++)
         for(int j=0;j<col;j++)
           if( in[i][j]==1)
        {
             val[i][j]=20;

             for(int k=0;k<8;k++)
             {
                  int tx=i+dx[k];
                  int ty=j+dy[k];

                  if( tx <0 || tx>=row || ty<0 || ty >=col)
                    continue;

                  val[tx][ty]++;
             }
     }

     cout<<"\n\n\nin\n";
     for(int i=0;i<row;i++,cout<<endl)
         for(int j=0;j<col;j++)
            cout<<in[i][j]<<" ";

     cout<<"\nVal is\n";

          for(int i=0;i<row;i++,cout<<endl)
         for(int j=0;j<col;j++)
          cout<<val[i][j]<<" ";


     //start dfs , all '0' must be in compnent



     int x=-1,y=-1;

    //find a zero
       for(int i=0;i<row;i++)
          for(int j=0;j<col;j++)
            if( val[i][j]==0)
       {
           x=i;
           y=j;
           break;
       }

       cout<<"zeroth pos is "<<x<<"  "<<y<<endl;

       if(x==-1)//kow zero wala nahi mila
       {
            return  false;
       }

       cout<<"Here  afer finding Zertoth Start\n";

       fill(done,0);

       dfs(x,y);

       //all zero must be connexted
       for(int i=0;i<row;i++)
         for(int j=0;j<col;j++)
           if( val[i][j]==0)
              if( done[i][j]==false)
           {
             return false;
           }

       //checking for all non-mines coverd by ZEROs

       for(int i=0;i<row;i++)
         for(int j=0;j<col;j++)
           if( val[i][j]==0)
           {

              for(int k=0;k<8;k++)
               {
                  int tx=i+dx[k];
                  int ty=j+dy[k];

                  if( tx <0 || tx>=row || ty<0 || ty >=col)
                    continue;

                   if( val[tx][ty] <=8)
                     done[tx][ty]=true;
              }
        }


        //checking if all non-mones are coverd

        for(int i=0;i<row;i++)
             for(int j=0;j<col;j++)
               if( val[i][j]<=8)
                  if( !done[i][j])
           			{
            			return false;
        			}
        			
        			
        			return true;

}

void solve( int t)
{


        cin>>row>>col>>mines;


          fill(in,0);

           int cont=0;

           for(int i=0;i<row;i++)
             for(int j=0;j<col;j++)
                  if( cont<mines)
                 {
                  cont++;
                  in[i][j]=1;
                 }

           bool ans= process();

    if( ans==false)
    {
       printf("Case #%d:\n",t);
       printf("Impossible\n");
       return;
    }
    else
    {
    	         printf("Case #%d:\n",t);
    

   				 bool zd=0;

	    for(int i=0;i<row;i++,cout<<endl)
	         for(int j=0;j<col;j++)
	            if( val[i][j]<=8)
	              {
	                    if( val[i][j]==0)
	                    {
	                        if(zd==true)
	                         cout<<".";
	                        else
	                        {
	                            cout<<"c";
	                            zd=true;
	                        }
	                    }
	                   else
	                      cout<<".";
	              }
	              else
	              {
	                  cout<<"*";
	              }
    }
}


int main()
{
 ios_base::sync_with_stdio(0);

  int test;

  cin>>test;

    for(int i=1;i<=test;i++)
    {
	  solve(i);
    }

 return 0;

}
