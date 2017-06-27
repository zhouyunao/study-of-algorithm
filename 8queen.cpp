#include <cstdio>
#include <math.h>
#include <iostream>
using namespace std;



/*N-8
 *ans摆放方法数
 *行标记
 *列标记
 *45度标记
 *135都标记
 *棋盘标记
*/
int N = 8;
int ans = 0;
int row[9];
int col[9];
int dpos[17];
int dneg[17];
int cb[8][8];

/*检查4个方向上是否有棋子占用*/
int check(int i, int j){
	if(row[i]==0&&col[j]==0&&dpos[i-j+N-1]==0&&dneg[i+j]==0)
		return 1;
	else
		return 0;
}


/*放置棋子标记4方向*/
void mark(int i, int j){
	row[i]=1;
	col[j]=1;
	dpos[i-j+N-1]=1;
	dneg[i+j]=1;
}


/*解除棋子4方向标记*/
void demark(int i, int j){
	row[i]=0;
	col[j]=0;
	dpos[i-j+N-1]=0;
	dneg[i+j]=0;
}

/*放置棋子的函数*/
void findchess(int x, int n){
	if(n > 8){ 
		ans++;
		return;
	}
 *一行向右循环
 *标记
 *对棋盘下一行进行再归---->停止条件 超过棋盘范围 8 返回上一行
 *解除标记
 *继续向右循环
 */
	for(int u = 0; u < N; u++){
		if(check(x,u) == 1){
			cb[x][u] = 1;
			mark(x,u);
			findchess(x+1, n+1);
			demark(x,u);
			cb[x][u] = 0;
		}
	}
}




int main(){
	for(int i=0;i<N;i++){
		for(int y=0;y<N;y++){
			cb[i][y] = 0;
		}
	}
	for(int i = 0; i < N; i++){
		row[i] = 0;
		col[i] = 0;
		
	}
	for(int i = 0; i < 2*N-1; i++){
		dpos[i] = 0;
		dneg[i] = 0;
	}
	
	
	findchess(0,1);
	
	

	cout << ans << endl;
}
