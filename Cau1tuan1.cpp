#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Congty{
	char ma[10],ten[100];
	int nam,sNV;
};
void Nhap(Congty *ct){
	printf("Ma cong ty:");gets(ct->ma);
	printf("Ten cong ty:");gets(ct->ten);
	printf("Nam thanh lap:");scanf("%d",&ct->nam); fflush(stdin);
	printf("So luong nhan vien:");scanf("%d", &ct->sNV); fflush(stdin);
}
void Nhap(Congty *ct, int n){
	for (int i=0;i<n;i++){
		printf("Cong ty thu %d:\n",i+1);
		Nhap((ct+i));
	}
}
void Xuat(Congty ct){
	printf("Ma:%s Ten:%s Nam thanh lap:%d So nhan vien:%d\n",ct.ma,ct.ten,ct.nam,ct.sNV);
}
void Xuat(Congty *ct,int n){
	for (int i=0;i<n;i++){
		Xuat(*(ct+i));
	}
}
Congty *LauNhat(int n,Congty *ct,int *k){
	*k = 0;
	Congty *a;
	a = (Congty*) malloc((n+1) * sizeof(Congty));
	float max = ct[0].nam;
	for(int i=0;i<n;i++)
		if(ct[i].nam < max)
			max = ct[i].nam;
	for(int i=0;i<n;i++)
		if(ct[i].nam == max)
			{
				a[*k] = ct[i];
				*k=*k+1;
			}
	return a;
}
Congty *congtythoaman(int n,Congty *ct,int *k,int *kt,int x,int y){
    *k = 0;
	*kt = 0;
	Congty *b;
	b = (Congty*) malloc((n+1) * sizeof(Congty));
	for(int i=0;i<n;i++)
		{
			if(ct[i].sNV>x && ct[i].nam<y)
				{
					b[*k] = ct[i];
					*k=*k+1;	
					*kt = 1;
				}
		}
	return b;
}
int main(){
	int n,k,X,Y,kt,d;
	printf("Nhap so cong ty:");scanf("%d",&n);fflush(stdin);
	Congty *ct;
    ct = (Congty*)malloc(n*sizeof(Congty));
// Nhap vao n cong ty, in ra man hinh
    Nhap(ct, n);
    printf("Cac cong ty vua nhap la:\n");
    Xuat(ct, n);
// Cong ty thanh lap lau nhat
    Congty *a = LauNhat(n, ct, &k);
	printf("Cong ty thanh lap lau nhat la:\n ");
	Xuat(a,k);
// In ra cac cong ty co nhieu hon X nhan vien, thanh lap truoc nam Y
    printf("Nhap X,Y:");scanf("%d %d",&X,&Y);
    Congty *tm = congtythoaman(n, ct, &d, &kt, X, Y);
	if(kt == 0)
		printf("Khong co cong ty nao thoa man");
	else
	{
		printf("Cac cong ty thoa man la:\n");
		Xuat(tm,d);	
	}
	free(ct);
	return 0;
}
