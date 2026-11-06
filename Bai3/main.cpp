#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char hoten[30];
	char msv[15];
	float d1, d2, d3;
}SV;
void nhap(SV *ds, int n){
	for(int i = 0; i < n; i++){
		scanf("%s %s %f %f %f", (ds + i)->hoten, (ds + i)->msv, &(ds + i)->d1, &(ds + i)->d2, &(ds + i)->d3);
	}
}
void in(SV *ds, int n){
	for(int i = 0; i < n; i++){
		printf("%s %s %.1f %.1f %.1f\n", (ds + i)->hoten, (ds + i)->msv, (ds + i)->d1, (ds + i)->d2, (ds + i)->d3);
	}
}
int main(){
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	SV *ds = (SV*) malloc(n * sizeof(SV));
	nhap(ds, n);
	in(ds, n);
	free (ds);
}
