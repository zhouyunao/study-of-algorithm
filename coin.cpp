#include <stdio.h>
#include <iostream>
#define INF 100000;
using namespace std;



int main(){
	//init the array for category of coins
	int C[21];

	//m for the value of target
	//n means that there are n kinds of coins
	int m, n;
	cin >> m >> n;

	//set the array C[]
	for(int t = 1; t <= n; t++){
		cin >> C[t];
	}

	//init value array T[]={0 INF INF INF....}
	int T[50001];
	for(int t = 0; t <= m; t++){
		T[t] = INF;
	}
	T[0] = 0;


	// select between T[j+C[i]]--the past way with T[j]+1--the much smarter way
	for(int i = 1; i <= n; i++){
		for(int j = 0; j + C[i] <= m; j++){
			T[j + C[i]] = min(T[j + C[i]], T[j] + 1);
		}
	}

	cout << T[m] << endl;

}