#include<bits/stdc++.h>
using namespace std;
int cnt = 0;
int MAX = INT_MIN;
int MIN = INT_MAX;
struct node{
	int data;
	struct node *pLeft;
	struct node *pRight;	
};
typedef struct node NODE;
typedef NODE* TREE;
void KhoiTaoCay(TREE &t){
	t = NULL;
}
bool checksnt(int n){
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0){
			return false;
		}
	}
	return n>1;
}
void ThemNodeVaoCay(TREE &t,int x){
	if(t == NULL){
		NODE *p = new NODE;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}else{
		if(t->data > x){
			ThemNodeVaoCay(t->pLeft,x);
		}else if(t->data < x){
			ThemNodeVaoCay(t->pRight,x);
		}
	}
}
// duyet cay theo NLR;
void Duyet_NLR(TREE t){
	if(t!=NULL){
		cout <<t->data << " ";
		Duyet_NLR(t->pLeft);
		Duyet_NLR(t->pRight);
	}
}
// duyet cay theo NRL;
void Duyet_NRL(TREE t){
	if(t!=NULL){
		cout <<t->data << " ";
		Duyet_NRL(t->pRight);
		Duyet_NRL(t->pLeft);
	}
}
// duyet cay theo LNR, duyet tu be den lon.
void Duyet_LNR(TREE t){
	if(t!=NULL){
		Duyet_LNR(t->pLeft);
		cout << t->data << " ";
		Duyet_LNR(t->pRight);
	}
}
// duyet cay theo RNL, duyet tu lon den be.
void Duyet_RNL(TREE t){
	if(t!=NULL){
		Duyet_RNL(t->pRight);
		cout << t->data << " ";
		Duyet_RNL(t->pLeft);
	}
}
// duyet cay theo LRN
void Duyet_LRN(TREE t){
	if(t!=NULL){
		Duyet_LRN(t->pLeft);
		Duyet_LRN(t->pRight);
		cout << t->data << " ";
	}
}
// duyet cay theo RLN
void Duyet_RLN(TREE t){
	if(t!=NULL){
		Duyet_RLN(t->pRight);
		Duyet_RLN(t->pLeft);
		cout << t->data << " ";
	}
}
void DemSoNT(TREE t){
	if(t!=NULL){
		if(checksnt(t->data)) cnt++;
		DemSoNT(t->pRight);
		DemSoNT(t->pLeft);
	}
}
NODE *TimKiem(TREE t,int x){
	if(t == NULL){
		return NULL;
	}else{
		if(x<t->data){
			TimKiem(t->pLeft,x);
		}else if(x> t->data){
			TimKiem(t->pRight,x);
		}else{
			return t;
		}
	}
}
// Node co 2 con
void Nodeco2con(TREE t){
	if(t!= NULL){
		if(t->pLeft != NULL && t->pRight != NULL){
			cout << t->data << " ";
		}
		Nodeco2con(t->pLeft);
		Nodeco2con(t->pRight);
	}
}
// Node co 1 con
void Nodeco1con(TREE t){
	if(t!= NULL){
		if((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL)){
			cout << t->data << " ";
		}
		Nodeco1con(t->pLeft);
		Nodeco1con(t->pRight);
	}
}
// Node la (ko co con nao)
void NodeLa(TREE t){
	if(t!= NULL){
		if(t->pLeft == NULL && t->pRight == NULL){
			cout << t->data << " ";
		}
		NodeLa(t->pLeft);
		NodeLa(t->pRight);
	}
}
int MaxNode(TREE t){
	if(t->pRight == NULL){
		return t->data;
	}
	return MaxNode(t->pRight);
}
int MinNode(TREE t){
	if(t->pLeft == NULL){
		return t->data;
	}
	return MinNode(t->pLeft);
}
void DiTimNodeTheMang(TREE &X,TREE &Y){
	if(Y->pLeft != NULL){
		DiTimNodeTheMang(X,Y->pLeft);
	}else{
		X->data = Y->data;
		X = Y;
		Y = Y->pRight;
	}
}
void XoaNode(TREE &t,int data){
	if(t== NULL){
		return;
	}else{
		if(data <t->data){
			XoaNode(t->pLeft,data);
		}else if(data > t->data){
			XoaNode(t->pRight,data);
		}else{
			NODE *X = t;
			if(t->pLeft == NULL){
				t = t->pRight;
			}else if(t->pRight == NULL){
				t = t->pLeft;
			}else{
				NODE *Y = t->pRight;
				DiTimNodeTheMang(X,Y);
			}
			delete X;
		}
	}
	
}
int countNode(TREE t){
	if(t == NULL){
		return 0;
	}else{
		int ld = countNode(t->pLeft);
		int rd = countNode(t->pRight);
		return 1+ld+rd;
	}
}
int depth(TREE t){
	if(t == NULL){
		return 0;
	}
	int ld = depth(t->pLeft);
	int rd = depth(t->pRight);
	if(ld>rd) return ld+1;
	else return rd+1;
}
void Menu(TREE &t){
	while(1){
		cout << "\n---------------------MENU--------------------" << endl;
		cout << "1.Nhap du lieu vao cay" << endl;
		cout << "2.Xuat cay nhi phan NLR" << endl;
		cout << "3.Xuat cay nhi phan NRL" << endl;
		cout << "4. Xuat cay nhi phan LNR" << endl;
		cout << "5. Xuat cay nhi phan RNL" << endl;
		cout << "6. Xuat cay nhi phan LRN" << endl;
		cout << "7. Xuat cay nhi phan RLN" << endl;
		cout << "8. Dem so nguyen to trong cay" << endl;
		cout << "9. Tim kiem" << endl;
		cout <<"10. Xuat cac node co 2 con" << endl;
		cout << "11. Xuat cac node co 1 con" << endl;
		cout << "12. Xuat cac node La" << endl;
		cout << "13. Tim max tren cay" << endl;
		cout << "14 Tim min tren cay" << endl;
		cout << "15.Xoa Node" << endl;
		cout << "16.Dem so Node" << endl;
		cout << "17.Do Sau cua cay" << endl;
		cout << "0.Ket thuc" << endl;
		cout << "---------------------------------------------" << endl;
		int lc;
		cout << "Nhap lua chon: ";
		cin >> lc;
		if(lc <0 || lc>17){
			cout << "Lua chon khong hop le !";
		}
		if(lc == 1){
			int x;
			cout << "Nhap so nguyen x: ";
			cin >> x;
			ThemNodeVaoCay(t,x);
		}
		if(lc == 2){
			cout << "NLR: ";
			Duyet_NLR(t);
		}
		if(lc == 3){
			cout << "NRL: ";
			Duyet_NRL(t);
		}
		if(lc == 4){
			cout << "LNR: ";
			Duyet_LNR(t);
		}
		if(lc == 5){
			cout << "RNL ";
			Duyet_RNL(t);
		}
		if(lc == 6){
			cout << "LRN ";
			Duyet_LRN(t);
		}
		if(lc == 7){
			cout << "RLN ";
			Duyet_RLN(t);
		}
		if(lc == 8){
			DemSoNT(t);
			cout << "Co " << cnt << " so nguyen to trong cay nhi phan";
		}
		if(lc == 9){
			int x;
			cout << "Nhap phan tu can tim kiem: ";
			cin >> x;
			NODE *p = TimKiem(t,x);
			if(p==NULL){
				cout << "Phan tu " << x << " khong co trong cay";
			}else{
				cout << "Phan tu " << x << " co trong cay";
			}
		}
		if(lc == 10){
			cout << "Cac node co 2 con la: ";
			Nodeco2con(t);
		}
		if(lc == 11){
			cout << "Cac node co 1 con la: ";
			Nodeco1con(t);
		}
		if(lc == 12){
			cout << "Cac node La la: ";
			NodeLa(t);
		}
		if(lc == 13){
			cout << "Node lon nhat la: " << MaxNode(t);
		}
		if(lc== 14){
			cout << "Node nho nhat la: " << MinNode(t);
		}
		if(lc == 15){
			int x;
			cout << "Nhap gia tri can xoa: ";
			cin >> x;
			XoaNode(t,x);
		}
		if(lc == 16){
			cout << "Co " << countNode(t) << " Node trong cay";  
		}
		if(lc == 17){
			cout << "Do Sau cua cay: " << depth(t);
		}
		if(lc == 0){
			cout << "Da thoat chuong trinh !";
			break;
		}
	}
}
int main(){
	TREE t;
	KhoiTaoCay(t);
	Menu(t);
	
}