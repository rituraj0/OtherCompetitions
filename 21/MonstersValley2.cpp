#include<algorithm>
#include<iostream>
#include <sstream>
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

long long mini=-1*(long long )100000*100000*100000L;

class MonstersValley2 {
public:


long long  cache[55][110];
bool done[55][110];

vector<int> price;
vector<int > dread;

int n;


long long solve( int id  , int p)
{

     if(id==0)
      {
            if( p >= price[0] )
              return dread[0];
              
              return mini;
      }   
      
      if( done[id][p] )
        return cache[id][p];          
      
      long long op1=mini;
      
      if( p-price[id] >=0 )
       op1=solve(id-1,p-price[id]) + dread[id];
      
      long long  op2=solve( id-1 , p );
                 
       long long ret=mini;
       
       if( op2 > dread[id]  )
          ret=op2;
          
       if( op1 > ret )
          ret=op1;
          
       done[id][p]=true;
       
      return   cache[id][p]=ret;

}       
          
int minimumPrice( vector<int > _dread, vector <int> _price)
 {
    memset(done, false , sizeof(false) );
     
     price=_price;
     dread=_dread;
     n=price.size();
     
     
     for(int p=0;p<=2*n;p++)
        solve(n-1,p);
         
     
     for(int p=1;p<=2*n;p++)
       if( cache[n-1][p] > dread[n-1] )
          return p;  
                       
}

};

#include<ctime>

double test0() {
	int t0[] = {8, 5, 10};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MonstersValley2 * obj = new MonstersValley2();
	clock_t start = clock();
	int my_answer = obj->minimumPrice(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int t0[] = {1, 2, 4, 1000000000};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 1, 1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MonstersValley2 * obj = new MonstersValley2();
	clock_t start = clock();
	int my_answer = obj->minimumPrice(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int t0[] = {200, 107, 105, 206, 307, 400};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {1, 2, 1, 1, 1, 2};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MonstersValley2 * obj = new MonstersValley2();
	clock_t start = clock();
	int my_answer = obj->minimumPrice(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 2;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int t0[] = {5216, 12512, 613, 1256, 66, 17202, 30000, 23512, 2125, 33333};
	vector <int> p0(t0, t0+sizeof(t0)/sizeof(int));
	int t1[] = {2, 2, 1, 1, 1, 1, 2, 1, 2, 1};
	vector <int> p1(t1, t1+sizeof(t1)/sizeof(int));
	MonstersValley2 * obj = new MonstersValley2();
	clock_t start = clock();
	int my_answer = obj->minimumPrice(p0, p1);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	int p2 = 5;
	cout <<"Desired answer: " <<endl;
	cout <<"\t" << p2 <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t" << my_answer <<endl;
	if (p2 != my_answer) {
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
		
		
		cin>>time;
}

//Powered by [KawigiEdit] 2.0!
