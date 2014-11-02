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

#define pii pair<int,int>

vector< pii > all[100009];

string in[1001][10];
int row,col,k,w;




int boss[1010];

int part[1010];
vector<int> edge[1010];

int root(int x)
{
     if( boss[x]==x) return x;
     return   boss[x]=root( boss[x] );
}


int join( int a, int b)
{
     int ar=root(a) , br=root(b);

     if(ar==br) return 0;

    if( rand() &1 )
        boss[ar]=br;
    else
        boss[br] =ar;

    return 1;

}




int main()
{
 ios_base::sync_with_stdio(0);

 cin>>row>>col>>k>>w;

 for(int i=1;i<=k;i++)
     for(int j=0;j<row;j++)
       cin>>in[i][j];

//   if(k==1)
//   {
//       cout<<row*col*w<<endl;
//       cout<<"1 0\n";
//       return 0;
//   }

  for(int i=1;i<=k;i++)
     for(int j=i+1;j<=k;j++)
     {
             int d=0;
              for(int a=0;a<row;a++)
                 for(int b=0;b<col;b++)
                   if( in[i][a][b]!=in[j][a][b])
                     d++;

              all[d*w].pb( mp(i,j));
     }

   for(int i=1;i<=k;i++)
     all[row*col].pb( mp(0,i));


  for(int i=0;i<1010;i++)
     boss[i]=i;

 int sm=0;

 for(int i=0;i<=100000;i++)
 {
       for(int j=0;j<all[i].sz;j++)
       {
            pii curr=all[i][j];

            int a=curr.X,b=curr.Y;

            int x=join(a,b);
            if(x==0) continue;
            sm+=i;

//            cout<<a<<"  "<<b<<endl;

           edge[a].pb(b);
           edge[b].pb(a);
       }
 }

  vector<pii> ans;

   queue<int> Q;

   fill(part,-1);
   Q.push(0);
   part[0]=0;

   while( Q.sz>0)
   {
       int curr=Q.front() ; Q.pop();

       for(int i=0;i<edge[curr].sz;i++)
       {
           int nw=edge[curr][i];

           if( part[nw]==-1)
           {
               part[nw]=curr;
               ans.pb( mp(nw,curr) );
               Q.push(nw);
           }
       }
   }


   cout<<sm<<endl;

   for(int i=0;i<ans.sz;i++)
    cout<<ans[i].X<<" "<<ans[i].Y<<endl;

 return 0;

}
