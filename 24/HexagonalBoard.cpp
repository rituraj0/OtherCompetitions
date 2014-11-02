#include<algorithm>
#include<iomanip> 
#include<iostream>
#include<sstream>
#include<cstring>
#include<cstdlib>
#include<climits>
#include<fstream>
#include<cctype>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<map>
#include<set>
using namespace std;

#define pb push_back


int dx[]={0,1,1};
int dy[]={1,0,-1};

class HexagonalBoard 
{
public:

set<int> graf[2600];

bool two;

bool visit[2600];
int color[2600];

void  dfs( int u , int c )
{
  if( visit[u] )
   {
      if( color[u] !=c )
        two=false;       
        return ;
   }
   
        visit[u]=true;
        color[u]=c;
        
       for(     set<int>::iterator it=graf[u].begin() ; it!=graf[u].end() ; it++ )
         {
           int tp=*it;           
           dfs(tp,1-c);
          }
          
}            


int row,col;

int  minColors(vector <string> bord) 
{
  row=bord.size() ;
  col=bord[0].size();
  
      bool zero=true;
  
  for(int i=0;i<row;i++)
    for(int j=0;j<col;j++)
     {
         if( bord[i][j]!='X' )
          continue;
          
          zero=false;
          
          int curr=i*row+j;
          
          for(int k=0;k<3;k++)
           {
             int tx=i+dx[k];
             int ty=j+dy[k];
             
             if(tx< 0 || tx >=row || ty <0 || ty >=col )
              continue;
              
               if( bord[tx][ty]!='X' )
         	 continue;
         	 
         	 int tp=tx*row+ty;
         	 
         	 graf[tp].insert(curr);
         	 graf[curr].insert(tp);
          }
    }
          
      if( zero)
        return 0;
    
    
    
   bool lone=true;
   
   for(int i=0;i<2600;i++)
     if( graf[i].size()>0)
         lone=false;
      
        if( lone )
          return 1;      
          
           two=true;
           
           memset( visit, 0, sizeof(visit) );
           
            for(int i=0;i<2600;i++)
              if( !visit[i] )
                  dfs(i,0);
                
                 if( two )
                  return 2; 
          
                       	        	            	        	               	        	            	        	 
           return 3;                       	        	            	        	               	        	            	        	              	        	            	        	               	        	            	        	              	        	            	        	               	        	            	        	 
             
           




	
}

};



double test0() {
	string t0[] = {"---",
 "---",
 "---"}
 ;
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 0;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	string t0[] = {"-X--",
 "---X",
 "----",
 "-X--"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 1;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	string t0[] = {"XXXX",
 "---X",
 "---X",
 "---X"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	string t0[] = {"XX-XX--"
,"-XX-XXX"
,"X-XX--X"
,"X--X-X-"
,"XX-X-XX"
,"-X-XX-X"
,"-XX-XX-"};
	vector <string> p0(t0, t0+sizeof(t0)/sizeof(string));
	HexagonalBoard * obj = new HexagonalBoard();
	clock_t start = clock();
	int my_answer = obj->minColors(p0);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p1 = 3;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p1 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p1 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}

int main() {
	int time;
	bool errors = false;
	
	time = test0();
	if (time < 0)
		errors = true;
	
	time = test1();
	if (time < 0)
		errors = true;
	
	time = test2();
	if (time < 0)
		errors = true;
	
	time = test3();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}
