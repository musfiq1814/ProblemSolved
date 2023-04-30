#include<iostream>
#include<queue>
#include<algorithm>
//#include<time.h>
using namespace std;
const long long int maxn=1e4 ;
long long int n , c , cnt = 1 ,best_x[maxn] , best_v = 0, w[maxn], v[maxn] , ww[maxn] , vv[maxn];
long long int total=1;
struct node       
{
    int no , i , w , v;
    int x[maxn]; 
    double ub; 
};

struct nn{
     long long a ;
	 long long b;
	 double c = (double)b/(double)a;
};
bool com(nn a, nn b){
	return a.c>b.c;
}
void bound(node &e){
	int i = e.i +1; 
	int sumw = e.w;
	double sumv = e.v;
	while((sumw + w[i] <= c ) and i <= n){
		sumw += w[i];
		sumv += v[i];
		i++;
	}
	if(i <= n ){
		e.ub = sumv + (c - sumw)*v[i]/ w[i];
	}
	else
	    e.ub = sumv;
}


void insert(node e , queue<node>&pq){
	if(e.i == n){
		if(e.v > best_v){
			best_v = e.v;
			for(int j = 1 ; j <= n; j++){
				best_x[j] = e.x[j];
			}
		}
	}
	else
	   pq.push(e);
}

void BB(){
	node curr , left , right;
	queue<node> pq;
	curr.i = 0;
	curr.v = 0;
	curr.w = 0;
	curr.no = cnt++;  
	for(int j = 1 ; j <= n ; j++){ 
		curr.x[j] = 0;
	}
	bound(curr);
	pq.push(curr);

	while(!pq.empty()){

		curr = pq.front(); 
		pq.pop();
		if(curr.w + w[curr.i+1] <= c){ 
			left.no = cnt; 
			left.i = curr.i+1;
			left.w = curr.w + w[left.i];
			left.v = curr.v + v[left.i];
			for(int j = 1;  j <= n ; j++){
				left.x[j] = curr.x[j]; 
			}
			left.x[left.i] = 1; 
			bound(left);
			insert(left , pq);
			cnt++;
		}

		right.no = cnt; 
		right.i = curr.i+1;
		right.w = curr.w; 
		right.v = curr.v;
		for(int j = 1;  j <= n ; j++){
			right.x[j] = curr.x[j]; 
		}
		right.x[right.i] = 0;
		bound(right);
		if(right.ub > best_v){ 
			insert(right , pq);
			cnt++;
		}
	}
}

int main(){


     n = 10;  
	 int ww[] = {12,15,7,19,1,12,18,11,20,25};  
     int pp[] = {33,39,24,47,10,34,45,31,49,60}; 
	 c  = 50; 
     for(int i = 1; i <= n; i++)
     {
         w[i] = ww[i-1];
	 	 v[i] = pp[i-1];
     }
    BB();

    cout<<"FIFO BB"<<endl;
    cout<<"\nThe optimal value is:"<<best_v<<endl;
    cout<<"(";
    for(int i=1;i<=n;i++)
        cout<<best_x[i]<<" ";
    cout<<")";
    cout<<endl;
      cout<<" Total  node created : "<<cnt - n <<endl;

	return 0;
}

