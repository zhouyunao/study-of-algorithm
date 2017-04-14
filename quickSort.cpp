#include <stdio.h>
#include <iostream>
#define MAX 100000
#define INF 100000
using namespace std ;



struct Card
{
	char type;
	int number;
};

//init 2 Card arrays
Card L[MAX/2], R[MAX/2];


void merge(Card c[], int left, int mid, int right){
	//init the length we are going to use
	int n1 = mid - left;
	int n2 = right - mid;

	//set the numbers which are already seperated into the new temporary arrays
	for(int i = 0; i < n1; i++ ){
		L[i] = c[left + i];
	}
	for(int i = 0; i < n2; i++ ){
		R[i] = c[mid + i];
	}


	//set the last Card's number
	L[n1].number = INF;
	R[n2].number = INF;

	//reset mark i and j
	int i = 0;
	int j = 0;

	//comparing numbers in array L[]with the numbers R[], and push the
	//the smaller one into array c[]
	for(int k = left; k < right; k++){
		if(L[i].number <= R[j].number){
			c[k] = L[i];
			i++;
		}
		else{
			c[k] = R[j];
			j++;
		}
	}


}


//split C[] by using recursive func and marker left and right 
void mergeSort(Card c[], int left, int right){
	int mid;
	if(left + 1 < right){
		mid = (left + right) / 2;
		mergeSort(c, left, mid);
		mergeSort(c, mid, right);
		merge(c, left, mid, right);
	}
}


// make array c[] in a new way like{3425(6)987}  every number which is smaller than 6
// will be in front of 6, however, the biiger ones will be behind 6
int partition(Card c[], int left, int right){
	int x = c[right].number;
	int i = left - 1;    //<=x marker
	for( int j = left; j <= right-1; j++){
		if(c[j].number <= x){
			i++;
			//swap
			Card temp = c[j];
			c[j] = c[i];
			c[i] = temp;
		}
	}
	// swap with a number >x
	Card temp1 = c[right];
	c[right] = c[i + 1];
	c[i + 1] = temp1;

	return i+1;
}

//the recursive func using partition func
void quickSort(Card c[], int left, int right){
	if (left < right){
		int q = partition(c, left, right);
		quickSort(c, left, q-1);
		quickSort(c, q+1, right);
	}
}


int main(){
	Card c[MAX],d[MAX];
	int N;
	int stable = 1;
	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%s %d",&c[i].type,&c[i].number);
		d[i].type = c[i].type;
		d[i].number = c[i].number;

	}

	quickSort(c, 0, N-1);
	mergeSort(d, 0, N);
	for (int i = 0; i < N; i++){
		if(c[i].type != d[i].type) {
			stable = 0;
			
		}
	}
	if(stable != 0) cout << "Stable\n";
	else cout << "Not stable\n";

	for(int i = 0; i < N; i++){
		cout << c[i].type << " " << c[i].number << endl;
	}
}