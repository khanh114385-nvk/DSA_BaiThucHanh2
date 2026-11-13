#include<stdio.h>
#include<stdlib.h>
typedef struct{
	char hoten[30];
	int msv;
	float d1, d2, d3;
}Data;
typedef struct tagNode{
	Data infor;
	struct tagNode *link;
}Node;
typedef struct{
	Node *pHead;
	Node *pTail;
	int spt;
}LList;
//
void initList(LList *L){
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}
//
int emptyList(LList L){
	return (L.spt == 0);
}
//
Node *search(LList L, char hoten[30]){
	Node *pp = L.pHead;
	while (pp != NULL && !strstr(pp->infor.hten, name)){
		pp = pp->link;
	}
	return pp; 
}
void insert_Head(LList *L, Data x){
	Node *pp;
	pp = (Node*) malloc (sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}
	else {
		pp->link = L->pHead;
		L->pHead = pp;
	}
	L->spt++;
}
//
void insert_Tail(LList *L, Data x){
	Node *pp;
	pp = (Node*) malloc (sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead = pp;
		L->pTail = pp;
	}
	else {
		L->pTail->link = pp;
		L->pTail = pp;
	}
	L->spt++;
}
//
void insert_After(LList *L, Node *q, Data x){
	Node *pp;
	if (NULL == q) return;
	else {
		pp = (Node*) malloc (sizeof (Node));
		pp->infor = x;
		pp->link = q->link;
		q->link = pp;
		if (q == L->pTail) L->pTail = pp;
		L->spt++;
	}
}
//
void ChenTang(LList *L, Data x){
	Node *pp = L->pHead, *q;
	while (pp != NULL && pp->infor.msv < x.msv){
		q = pp;
		pp = pp->link;
	}
	if (pp == L->pHead) insert_Head(L, x);
	else insert_After(L, q, x);
}
//
void Tach(LList L, LList *L1, LList *L2){
	initList(L1);
	initList(L2);
	Node *pp = L.pHead;
	while (pp != NULL){
		if(pp->infor.d1 < ??? || d2 || d3){
			insert_Head(L1, pp->infor);
		}
		else {
			insert_Head(L2, pp->infor);
		}
		pp = pp->link;
	}
}
//
void Ghep(LList L1, LList L2, LList *L){
	initList(L);
	Node *p1 = L1.pHead;
	Node *p2 = L2.pHead;
	if (L1.spt < L2.spt){
		while (p1 != NULL){
			insert_Head(L, p1->infor);
			insert_Head(L, p2->infor);
			p1 = p1->link;
			p1 = p2->link;
		}
		while (p2 != NULL){
			insert_Head(L, p2->infor);
			p2 = p2->link;
		}
	}
	else{
		//...
	}
}
//
void del_Head(LList *L){
	Node *pp;
	if (emptyList(*L)) return;
	else {
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt-;
		if(L->pHead == NULL) L->pTail = NULL;
	}
}
//
void del_After(LList *L, Node *q){
	Node *pp;
	if(NULL == q) return;
	else{
		pp = q->link;
		if(q->link == L->pTail){
			L->pTail = q;
		}
		q->link = pp->link;
		free(pp);
		L->spt-;
	}
}
//
void del_K(LList *L, char K[30]){
	Node *pp = L->pHead, *q;
	while (pp != NULL && !strstr(pp->infor.ten, K)){
		q = pp;
		pp = pp->link;
	}
	if(NULL == pp) return;
	else{
		if(pp == L->pHead) del_Head(L);
		else del_After(L, q);
	}
}
void Nhap(Data *x){
	printf("Nhap ma sinh vien: ");
	scanf("%d", &(x->msv));
	if (x->msv > 0){
		printf("Nhap ma sinh vien: ");
		scanf("%s", (x->hoten));
		printf("Nhap diem mon 1: ");
		scanf("%f", &(x->d1));
		printf("Nhap diem mon 2: ");
		scanf("%f", &(x->d2));
		printf("Nhap diem mon 3: ");
		scanf("%f", &(x->d3));
	}
}
void In(Data x){
	printf("Ten: %s, MSV: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", x.hoten, x.msv, x.d1, x.d2, x.d3);
}
void processList(LList L){
	Node *pp = L.pHead;
	while (pp != NULL){
		in(pp->infor);
		pp = pp->link;
	}
}
//
int main(){
	LList L;
	int kt = 0;
	Data x;
	initList (&L);
	do{
		printf("\nChuong trinh lam viec voi DSLK don SV\n");
		printf("\n1: Them nut vao dau danh sach");
		printf("\n2: Them nut vao cuoi danh sach");
		printf("\n3: Them nut vao sau 1 nut khac trong danh sach");
		printf("\n9: Duyet danh sach");
		printf("\n0: Thoat");
		printf("\nMoi ban chon");
		int chon;
		scanf("%d", &chon);
		switch(chon){
			case 1:
				printf("Nhap so sinh vien can them\n");
				nhap(&x);
				if(x.msv > 0){
					insert_Head(&L, x);
					break;
				}
			case 2:
				//...
				break;
			case 3:
				//...
				break;
			case 4:
				//...
				break;
			case 9:
				processList(L);
				break;
			case 0:
				printf("Bye bye\n");
				kt = 1;
		}
	}
	while (kt == 0);
}
