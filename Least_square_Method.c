#include<stdio.h>
int main() {
	int m, n, i, j, k;
	printf("Nhap so bac cua da thuc: m= "); scanf("%d",&m);
	printf("Nhap so diem du lieu cho truoc: n= "); scanf("%d",&n);
	double x[n], y[n], X, Y=0, F[m+2][n], a[m+1], p;
	printf("Nhap gia tri cac diem cho truoc:\n");
	for(i=0;i<n;i++) {
		printf("(x%d,y%d)= ",i,i); scanf("%lf %lf",&x[i],&y[i]);
		F[i][0]=1;
		for(j=1;j<m+1;j++) F[i][j]=F[i][j-1]*x[i];
		F[i][m+1]=y[i];
	}
	for(k=0;k<m+1||k<n-1;k++) for(i=k+1;i<n;i++) {
		p=F[i][k]/F[k][k];
		for(j=k;j<m+2;j++) F[i][j]-=p*F[k][j];
	}
	for(k=k-1;k>0;k--) for(i=k-1;i>=0;i--) {
		p=F[i][k]/F[k][k];
		for(j=k;j<m+2;j++) F[i][j]-=p*F[k][j];
	}
	for(k=0;k<m+1||k<n-1;k++) a[k]=F[k][m+1]/F[k][k];
	printf("Nhap X= "); scanf("%lf",&X);
	for(j=m;j>=0;j--) Y=Y*X+a[j];
	printf("Y= %lf\n",Y);
}