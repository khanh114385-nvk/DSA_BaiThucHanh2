#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

// Khai bao cau truc du lieu SV
typedef struct{
	char hoTen[30];
	int ma;
	float d1, d2, d3;
}SV;

// Khai bao node cua DSLK don
typedef struct tagNode{
	SV infor;
	struct tagNode *link; // link: con tro tro den nut tiep theo
}Node;

// Khai bao cau truc quan ly DSLK don
typedef struct{
	Node *pHead; // pHead: con tro den nut dau tien
	Node *pTail; // pTail: con tro den nut cuoi cung
	int spt; // spt: so phan tu trong danh sach
}LList;

// Khoi tao ra mot danh sach rong
void initList(LList *L) {
	L->pHead = NULL;
	L->pTail = NULL;
	L->spt = 0;
}

// Kiem tra danh sach rong
int emptyList(LList L) {
	return (L.spt == 0);
}

// Xu ly 1 sinh vien 
void Nhap(SV *x) {
	printf("Nhap ma sinh vien: ");
	scanf("%d", &(x->ma));
	if ((x->ma) > 0) {
		printf("Nhap ho va ten sinh vien: ");
		scanf("%s", (x->hoTen)); 
		
//		getchar();
//		fgets(x->hoTen, sizeof(x->hoTen), stdin);
//		x->hoTen[strlen(x->hoTen) - 1] = '\0';

		printf("Nhap diem mon thu nhat: ");
		scanf("%f", &(x->d1));
		printf("Nhap diem mon thu hai: ");
		scanf("%f", &(x->d2));
		printf("Nhap diem mon thu ba: ");
		scanf("%f", &(x->d3));
	}
}

float dtb(SV x) {
	return (x.d1 + x.d2 + x.d3) / 3.0;
}

void In(SV x) {
	printf("Ho va ten: %s, Ma sinh vien: %d, Diem mon 1: %.2f, Diem mon 2: %.2f, Diem mon 3: %.2f, Diem trung binh: %.2f\n", x.hoTen, x.ma, x.d1, x.d2, x.d3, dtb(x));
}

// Them X vao dau danh sach
void insertHead(LList *L, SV x) {
	Node *pp = (Node*) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if (emptyList(*L)) {
		L->pHead = pp;
		L->pTail = pp;
	}
	else {
		pp->link = L->pHead;
		L->pHead = pp;
	}
	L->spt++;
}

// Chen X vao cuoi danh sach
void insertTail(LList *L, SV x) {
	Node *pp = (Node*) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if (emptyList(*L)) {
		L->pHead = pp;
		L->pTail = pp;
	}
	else {
		L->pTail->link = pp;
		L->pTail = pp;
	}
	L->spt++;
}

// Chen X vao sau phan tu q trong danh sach
void insertAfter(LList *L, Node *q, SV x) {
	Node *pp;
	if (NULL == q) return;
	else {
		pp = (Node*) malloc(sizeof(Node));
		pp->infor = x;
		pp->link = q->link;
		q->link = pp;
		if (q == (L->pTail)) {
			L->pTail = pp;
		}
		L->spt++;
	}
}

// Chen tang dan theo ma sinh vien (Duyet vi tri sao cho ma luon xep tang dan)
void chenTang(LList *L, SV x) {
	Node *pp = L->pHead;
	Node *q;
	while (pp != NULL && (pp->infor.ma < x.ma)) {
		q = pp;
		pp = pp->link;
	}
	if (pp == L->pHead) {
		insertHead(L, x);
	}
	else {
		insertAfter(L, q, x);
	}
}

// Chen phan tu X vao dau danh sach
void LIFO(LList *L) {
	SV x;
	initList(L);
	do {
		Nhap(&x);
		if (x.ma != 0) { // (x.ma > 0)
			insertHead(L, x);
		}
	}
	while (x.ma != 0);
}

// Chen phan tu X vao cuoi danh sach
void FIFO(LList *L) {
	SV x;
	initList(L);
	do {
		Nhap(&x);
		if (x.ma != 0) { // (x.ma > 0)
			insertTail(L, x);
		}
	}
	while (x.ma != 0);
}

// Duyet toan bo va in danh sach ra
void processList(LList L) {
	Node *pp = L.pHead;
	while (pp != NULL) {
		In(pp->infor);
		pp = pp->link;
	}
}

// Tuong duong processList, nhung chi in nhung SV duoi 4.0 
void SVHocLai(LList L) {
	Node *pp = L.pHead;
	int dem = 0;
	while (pp != NULL) {
		if (pp->infor.d1 < 4 || pp->infor.d2 < 4 || pp->infor.d3 < 4) {
			dem++;
			In(pp->infor);
		}
		pp = pp->link;
	}
	printf("So sinh vien phai hoc lai la: %d\n", dem);
}

// Tim kiem theo ten
Node *TimKiemTen(LList L, char ten[30]) {
	Node *pp = L.pHead;
	while (pp != NULL && !strstr(pp->infor.hoTen, ten)) {
		pp = pp->link;
	}
	return pp;
}

// Tim kiem theo id
Node *TimKiemMa(LList L, int id) {
	Node *pp = L.pHead;
	while (pp != NULL && (pp->infor.ma != id)) {
		pp = pp->link;
	}
	return pp;
}

// Tach danh sach thanh nhieu danh sach
void Tach(LList L, LList *L1, LList *L2) {
	initList(L1);
	initList(L2);
	Node *pp = L.pHead;
	while (pp != NULL) {
		if (pp->infor.d1 < 4.0 || pp->infor.d2 < 4.0 || pp->infor.d3 < 4.0) {
			insertHead(L1, pp->infor);
		}
		else {
			insertHead(L2, pp->infor);
		}
		pp = pp->link;
	}
}

// Ghep nhieu danh thanh mot danh sach 
void Ghep(LList L1, LList L2, LList *L) {
	initList(L);
	Node *p1 = L1.pHead;
	Node *p2 = L2.pHead;
	if (L1.spt < L2.spt) {
		while (p1 != NULL) {
			insertHead(L, p1->infor);
			insertHead(L, p2->infor);
			p1 = p1->link;
			p2 = p2->link;
		}
		while (p2 != NULL) {
			insertHead(L, p2->infor);
			p2 = p2->link;
		}
	}
	else {
		while (p2 != NULL) {
			insertHead(L, p1->infor);
			insertHead(L, p2->infor);
			p1 = p1->link;
			p2 = p2->link;
		} 
		while (p1 != NULL) {
			insertHead(L, p1->infor);
			p1 = p1->link;
		}
	}
}

// Xoa phan tu o dau danh sach 
void delHead(LList *L) {
	Node *pp;
	if (emptyList(*L)) return;
	else {
		pp = L->pHead;
		L->pHead = pp->link;
		free(pp);
		L->spt--;
		if (L->pHead == NULL) {
			L->pTail = NULL;
		}
	}
}

// Xoa phan tu o sau phan tu q trong danh sach
void delAfter(LList *L, Node *q) {
	Node *pp;
	if (NULL == q) return;
	else {
		pp = q->link;
		if (q->link == L->pTail) {
			L->pTail = q;
		}
		q->link = pp->link;
		free(pp);
		L->spt--;
	}
}

// Xoa phan tu co khoa K trong danh sach - Xoa theo ten
void delTen(LList *L, char ten[30]) {
	Node *pp = L->pHead;
	Node *q;
	while (pp != NULL && !strstr(pp->infor.hoTen, ten)) {
		q = pp;
		pp = pp->link;
	}
	if (NULL == pp) return;
	else {
		if (pp == L->pHead) {
			delHead(L);
		}
		else {
			delAfter(L, q);
		}
	}
}

// Xoa phan tu co khoa K trong danh sach - Xoa theo ID
void delMa(LList *L, int id) {
	Node *pp = L->pHead;
	Node *q;
	while (pp != NULL && (pp->infor.ma != id)) {
		q = pp;
		pp = pp->link;
	}
	if (NULL == pp) return;
	else {
		if (pp == L->pHead) {
			delHead(L);
		}
		else {
			delAfter(L, q);
		}
	}
}

int main(){
	LList L;
	int kt = 0;
	SV x;
	initList(&L); // Tao ra mot danh sach rong
	LList L1, L2, LGhep;
	int timMa;
	char timTen[30];
	Node *q;
	do {
		printf("Chuong trinh lam viec voi mot danh sach lien ket don sinh vien\n");
		printf("1: Them nut vao dau danh sach\n");
		printf("2: Them nut vao cuoi danh sach\n");
		printf("3: Them nut vao sau sinh vien co ma X\n");
		printf("4: Chen tang dan theo ma sinh vien\n");
		printf("5: Nhap danh sach kieu LIFO (chen dau)\n");
		printf("6: Nhap danh sach kieu FIFO (chen cuoi)\n");
		printf("7: Tim kiem sinh vien theo ten\n");
		printf("8: Tim kiem sinh vien theo ma\n");
		printf("9: Duyet toan bo danh sach\n");
		printf("10: Liet ke sinh vien phai hoc lai (diem < 4)\n");
		printf("11: Xoa phan tu dau danh sach\n");
		printf("12: Xoa sinh vien theo ten\n");
		printf("13: Xoa sinh vien theo ma\n");
		printf("14: Tach danh sach (truot/dat) va ghep lai\n");
		printf("0: Thoat\n");
		printf("Moi ban chon: ");
		int chon;
		scanf("%d", &chon);
		switch (chon) {
			case 1: 
				printf("Nhap so thong tin sinh vien can them\n");
				Nhap(&x);
				if (x.ma > 0) {
					insertHead(&L, x);
				}
				break;
			case 2:
				printf("Nhap so thong tin sinh vien can them\n");
				Nhap(&x);
				if (x.ma > 0) {
					insertTail(&L, x);
				}
				break;
			case 3:
				printf("Nhap ma sinh vien dung truoc: ");
				scanf("%d", &timMa);
				q = TimKiemMa(L, timMa);
				if (q == NULL) {
					printf("Khong tim thay sinh vien co ma %d!\n", timMa);
				} else {
					Nhap(&x);
					if (x.ma > 0) insertAfter(&L, q, x);
				}
				break;
			case 4:
				Nhap(&x);
				if (x.ma > 0) chenTang(&L, x);
				break;
			case 5:
				LIFO(&L);
				break;
			case 6:
				FIFO(&L);
				break;
			case 7:
				printf("Nhap ten sinh vien can tim: ");
				getchar();
				fgets(timTen, sizeof(timTen), stdin);
				timTen[strlen(timTen) - 1] = '\0';
				q = TimKiemTen(L, timTen);
				if (q != NULL) In(q->infor);
				else printf("Khong tim thay sinh vien!\n");
				break;
			case 8:
				printf("Nhap ma sinh vien can tim: ");
				scanf("%d", &timMa);
				q = TimKiemMa(L, timMa);
				if (q != NULL) In(q->infor);
				else printf("Khong tim thay sinh vien!\n");
				break;
			case 9:
				processList(L);
				break;
			case 10:
				SVHocLai(L);
				break;
			case 11:
				delHead(&L);
				printf("Da xoa dau danh sach.\n");
				break;
			case 12:
				printf("Nhap ten sinh vien can xoa: ");
				getchar();
				fgets(timTen, sizeof(timTen), stdin);
				timTen[strlen(timTen) - 1] = '\0';
				delTen(&L, timTen);
				break;
			case 13:
				printf("Nhap ma sinh vien can xoa: ");
				scanf("%d", &timMa);
				delMa(&L, timMa);
				break;
			case 14:
				Tach(L, &L1, &L2);
				printf("\nDanh sach L1 (Co mon < 4.0)\n");
				processList(L1);
				printf("\nDanh sach L2 (Dat tat ca cac mon)\n");
				processList(L2);
				Ghep(L1, L2, &LGhep);
				printf("\nDanh sach sau khi ghep L1 va L2\n");
				processList(LGhep);
				break;
			case 0:
				printf("BYE BYE");
				kt = 1;
				break;
			default:
				printf("Lua chon khong hop le!\n");
		}
	}
	while (kt == 0);
}
