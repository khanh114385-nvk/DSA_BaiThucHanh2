#include <iostream>
using namespace std;
void nhap(float *a, int h, int c){
	for(int i = 0; i < h; i++)
	for(int j = 0; j < c; j++){
		cout << "Nhap phan tu hang " << i << " cot " << j << " ";
		cin >> a[i * c + j];
	}
}
void in(float *a, int h, int c){
	for(int i = 0; i < h; i++){
		for(int j = 0; j < c; j++)
			cout << a[i * c + j] << " ";
		cout << endl;
	}
}
int main(){
	float *a;
	int n, m;
	cout << "Nhap so hang, so cot cua ma tran: ";
	cin >> n >> m;
	a = new float[n * m];
	nhap(a, m, n);
	in(a, m, n);
	delete []a;
	a = NULL;
	return 0;
}
