#include <stdio.h>
#include <stdlib.h>
typedef struct{
	char hoten[30];
	int msv;
	float d1, d2, d3;
}SV;
typedef struct tagNode{
	SV infor;
	struct tagNode *link;
}Node;
typedef struct {
	Node *pHead;
	Node *pTail;
	int spt;
}LList;
void initList(LList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}
Node *createNode(SV sv){
	Node *p = (Node*) malloc(sizeof(Node));
	if(p == NULL) return NULL;
	p->infor = sv;
	p->link = NULL;
	return p;
}
void addTail(LList *L, Node *p){
	if(p == NULL) return;
	if(L->pHead == NULL){
		L->pHead = L->pTail = p;
	}
	else{
		L->pTail->link = p;
		L->pTail = p;
	}
	L->spt++;
}
void nhap(LList *L, int n){
	for(int i = 0; i < n; i++){
		SV sv;
		scanf("%s %d %f %f %f", sv.hoten, &sv.msv, &sv.d1, &sv.d2, &sv.d3);
		Node *p = createNode(sv);
		addTail(L, p);
	}
}
void in(LList *L, int n){
	Node *p = L->pHead;
	for(int i = 0; i < n && p != NULL; i++){
		printf("%s %d %.1f %.1f %.1f\n", p->infor.hoten, p->infor.msv, p->infor.d1, p->infor.d2, p->infor.d3);
		p = p->link;
	}
}
void freeList(LList *L){
	Node *p = L->pHead;
	while(p != NULL){
		Node *temp = p;
		p = p->link;
		free(temp);
	}
	L->pHead = L->pTail = NULL;
	L->spt = 0;
}
int main(){
	LList L;
	initList(&L);
	int n;
	printf("Nhap so luong sinh vien: ");
	scanf("%d", &n);
	nhap(&L, n);
	in(&L, n);
	freeList (&L);
}
