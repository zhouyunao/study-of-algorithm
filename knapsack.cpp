#include <stdio.h>
#include <iostream>
#include <string>
#define flag0 0;
#define flag1 1;
using namespace std;
struct I
{
	int v;
	int w;
};
 
int C[1001][5001];
//int G[1001][1001];
I item[100];


int ks(int n, int w){
	for(int i = 1; i <= n; i++) C[i][0] = 0;
	for(int j = 0; j <= w; j++) C[0][j] = 0;

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= w; j++){
			int t = item[i].w;
			
			//weight is smaller than j
			if(t <= j){
				if(item[i].v + C[i - 1][j - t] > C[i - 1][j]){
					C[i][j] = item[i].v + C[i - 1][j - t];
					//G[i][w] = flag1;
				}
				else C[i][j] = C[i - 1][j];
			}

			//weight is bigger than j
			else {
				C[i][j] = C[i - 1][j];
				//G[i][j] = flag0;
			}
		}
	}
	return C[n][w];
}


int main(){
	int n, w;
	cin >> n >> w;

	for(int t = 1; t <= n; t++){
		cin >> item[t].v;
		cin >> item[t].w;
	}
	cout << ks(n, w) << endl;

}


