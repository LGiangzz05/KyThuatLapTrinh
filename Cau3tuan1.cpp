#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void Nhap(int **a, int n, int m){
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
		{
			printf("Nhap a[%d][%d]: ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}
}
void Xuat(int **a, int n, int m)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			printf("%5d ", a[i][j]);
		printf("\n");
	}
}
float TBCc(int **a,int n,int m,int *kt)
{
	float s = 0;
	*kt = 0;
	int dc=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
	    if(a[i][j]%2==0)
		{
			s=s+a[i][j];
			dc=dc+1;	
		}	
	}
	if(dc!=0)
		{
		    *kt = 1;
			return s/dc;
		}
	else
		{
			*kt = 0;
			return 0;
			}	
}
float TBNl(int **a,int n,int m,int *kt)
{
	float t=1;
	*kt = 0;
	int dl=0;
	for(int i=0;i<n;i++)
	for(int j=0;j<m;j++)
	{
		if(a[i][j]%2!=0)
			{
				t=t*a[i][j];
				dl=dl+1;	
			}	
	}
	if(dl!=0)
		{
			*kt = 1;
		    return pow(t,(1.0/dl));
		}
	else
		{
			*kt = 0;
			return 0;
		}		
}
int* TongHang(int **a, int n, int m) 
{
    int *b = (int*)malloc(n * sizeof(int)); 
    for(int i = 0; i < n; i++) 
		{
	        b[i] = 0; 
	        for(int j = 0; j < m; j++)
	            b[i] += a[i][j]; 
	    }
    return b;
}
int maxHang(int **a,int n,int m)
{
	int *b = TongHang(a, n, m);
	int max = 0,h = 0;
	for(int i=0;i<n;i++)
		{
			if(max<b[i])
			{
				max = b[i];
				h = i+1;
			}
		}
	return h;
}
int main(){
	int **a;
	int n,m;
	printf("So hang va so cot la: "); scanf("%d %d", &n, &m);
	a = (int**)malloc(n*sizeof(int *));
	for(int i=0;i<n;i++)
	{
		a[i] = (int*)malloc(m*sizeof(int));
	}
// Nhap vao ma tran va in ra man hinh
	Nhap(a, n, m);
	printf("Ma tran vua nhap la:\n");
	Xuat(a, n, m);
// Trung binh cong cac phan tu chan
	int kt1,kt2;
	float t1 = TBCc(a, n, m, &kt1);
	if(kt1 == 0)
	{
		printf("Khong co phan tu chan");
	}
	else
	{
		printf("Trung binh cong cac phan tu chan la: %.1f",t1);
	}
// Trung binh nhan cac phan tu le
	float t2 = TBNl(a, n, m, &kt2);
	if(kt2 == 0)
		{
			printf("\nKhong co phan tu le");
		}
	else
	{
		printf("\nTrung binh nhan cac phan tu le la: %.3f",t2);
	}
	int *b = TongHang(a, n, m);
// Tinh tong tung hang
    printf("\nTong tung hang:\n");
    for(int i=0;i<n;i++) 
	{
        printf("Tong hang %d: %d\n", i+1, b[i]);
    }
// Hang co tong lon nhat
    int t3 = maxHang(a, n, m);
    printf("Hang co tong lon nhat la: Hang %d",t3);
}
