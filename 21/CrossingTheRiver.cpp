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
#include<ctime>
#include<map>
#include<set>
using namespace std;

class CrossingTheRiver {
public:

 bool cool(int ww, int lw, vector<int> rem, int dp,int wl, int wh, int ll, int lh)
    {
        for (int i=wl; i<=wh; i++) 
         {
         	  ww--;
         	  
         	  if(ww<0)
         	    return false;
         	  else
			    {
			    	 rem[i]--;
			    	 
			    	 if( rem[i] < 0 )
			    	  return false;
			    }   
         }

            
        for (int i=ll; i<=lh; i++) 
          {          	
               lw--;
               
              if(lw <0) 
               return false;
         	  else
			    {
			    	 rem[i]--;
			    	 
			    	 if( rem[i] < 0 )
			    	  return false;
			    } 
	      }
                    
        int dono = 0;
        int lo = 0;
        int wo = 0;
        
        for (int i=dp; i<=100; i++) 
		 {
            bool w = ( wl <= i && i <= wh);
            bool l = ( ll <= i && i <= lh);
            
            if ( w && l ) 
                dono += rem[i];
             else if (w) 
                wo += rem[i];
             else if (l) 
                lo += rem[i];
            
        }
      
        ww = max(0, ww - wo);
        lw = max(0, lw - lo);
        
        if ( lw + ww <= dono )
         return true;
         
         return false;
         
    
 }

    string isItEvenPossible( int ww, int lw,  vector <int> bh, int dp)
    {
        int n = bh.size();
        
        vector<int> cont(101, 0);
        
        for (int i=0; i<n; i++) 
            cont[ bh[i] ]++;
        
        if (cont[dp] >= ww) // after water , walk on surface
		         return "POSSIBLE";
        
        for (int wl=dp; wl<=dp+1; wl++) 
		     if (cont[wl]) 
			  {
                for (int wh=wl; wh<=100; wh++)
				     if (cont[wh]) 
					   {
                          for (int ll=wh-dp; ll<=wh-dp+1; ll++) 
						   {
                              if ( (ll < 0) || (cont[ll] == 0 )  )
                               continue;
                            
                               for (int lh=ll; lh<=100; lh++) 
							     if (cont[lh]) 
                                   if ( cool( ww, lw, cont , dp, wl,wh, ll,lh ) ) 
                                     {                                     
                                       return "POSSIBLE";
                                     }
                          }
                     }
              }
                    
        return "IMPOSSIBLE";
    }
    
};





#include<ctime>


double test0() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {3,4,4,5,5, 6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test1() {
	int p0 = 3;
	int p1 = 3;
	int t2[] = {3,4,4,5,6, 6};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test2() {
	int p0 = 5;
	int p1 = 2;
	int t2[] = {4,4,4,4,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 4;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test3() {
	int p0 = 5;
	int p1 = 5;
	int t2[] = {5,5,5,5,5,5, 2,3,4,4,6, 7, 3, 2};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test4() {
	int p0 = 5;
	int p1 = 7;
	int t2[] = {6,6,6,6,6,6,6, 6,6,6,6,6,7,8,9,10};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 5;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "POSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
		cout <<"DOESN'T MATCH!!!!" <<endl <<endl;
		return -1;
	}
	else {
		cout <<"Match :-)" <<endl <<endl;
		return (double)(end-start)/CLOCKS_PER_SEC;
	}
}
double test5() {
	int p0 = 1;
	int p1 = 1;
	int t2[] = {5,3,4};
	vector <int> p2(t2, t2+sizeof(t2)/sizeof(int));
	int p3 = 2;
	CrossingTheRiver * obj = new CrossingTheRiver();
	clock_t start = clock();
	string my_answer = obj->isItEvenPossible(p0, p1, p2, p3);
	clock_t end = clock();
	delete obj;
	cout <<"Time: " <<(double)(end-start)/CLOCKS_PER_SEC <<" seconds" <<endl;
	string p4 = "IMPOSSIBLE";
	cout <<"Desired answer: " <<endl;
	cout <<"\t\"" << p4 <<"\"" <<endl;
	cout <<"Your answer: " <<endl;
	cout <<"\t\"" << my_answer<<"\"" <<endl;
	if (p4 != my_answer) {
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
	
	time = test4();
	if (time < 0)
		errors = true;
	
	time = test5();
	if (time < 0)
		errors = true;
	
	if (!errors)
		cout <<"You're a stud (at least on the example cases)!" <<endl;
	else
		cout <<"Some of the test cases had errors." <<endl;
}

//Powered by [KawigiEdit] 2.0!
