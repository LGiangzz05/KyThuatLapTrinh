#include<stdio.h>
#include<stdlib.h>
struct DayNguyen{
	int n;
	int *a;
};
void Nhap(DayNguyen *dn){
	printf("Nhap so phan tu cua day:"); scanf("%d",&dn->n);
	dn->a=(int*)malloc((dn->n)*sizeof(int));
	for (int i=0;i<dn->n;i++)
	{
		printf("a[%d]=",i+1);
		scanf("%d",&dn->a[i]);
	}
}
void Xuat(DayNguyen dn){
	for(int i=0;i<dn.n;i++){
		printf("%d ",dn.a[i]);
	}
}
int Max(DayNguyen *dn){
	int max=dn->a[0];
	for(int i=0;i<dn->n;i++){
		if(dn->a[i]>max){
			max=dn->a[i];
		}
	}
	return max;
}
int tinhtong(DayNguyen *dn){
	int s=0;
	for(int i=0;i<dn->n;i++){
		s+=dn->a[i];
	}
	return s;
}
float tbc(DayNguyen *dn,float x,int *c){
	*c=0;
	int s=0,dem=0;
	for(int i=0;i<dn->n;i++){
		if(dn->a[i]>x){
			*c=1;
			 s+=dn->a[i];
			 dem++;
		}	
	}
	return 1.0*s/dem;
}
main(){
	DayNguyen dn;
// Nhap vao day so nguyen, in ra man hinh
	Nhap(&dn);
	printf("Day so vua nhap la:\n");
	Xuat(dn);
// Tim max day so
	printf("\nMax cua day so la: %d",Max(&dn));
// Tinh tong day so
	printf("\nTong cua day so la: %d",tinhtong(&dn));
	float x;
// Nhap x, tinh TBC cac phan tu lon hon x
	printf("\nx="); scanf("%f",&x);
	int c;
	float tb=tbc(&dn,x,&c);
	if(c==0) printf("Khong co phan tu nao lon hon x");
	else
	{
		printf("Trung binh cong cac phan tu lon hon x la: %.2f",tb);	
	}
}
