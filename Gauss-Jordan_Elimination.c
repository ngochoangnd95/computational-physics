#include<stdio.h>
int main() {
	int n, i, j, k;
	printf("Nhap co ma tran cua Ax=b\nn= "); scanf("%d",&n);
	double a[n][n+1], p;
	printf("Nhap gia tri cho ma tran:\n");
	for(i=0;i<n;i++) {
		printf("Hang thu %d: ",i+1);
		for(j=0;j<n+1;j++) scanf("%lf",&a[i][j]);
	}
	/*Gauss Elimination*/
	for(k=0;k<n-1;k++) for(i=k+1;i<n;i++) {
		p=a[i][k]/a[k][k];
		for(j=k;j<n+1;j++) a[i][j]-=p*a[k][j];
	}
	/*Jordan Elimination*/
	for(k=n-1;k>0;k--) for(i=k-1;i>=0;i--) {
		p=a[i][k]/a[k][k];
		for(j=k;j<n+1;j++) a[i][j]-=p*a[k][j];
	}
	/*Show solution*/
	printf("Nghiem he phuong trinh la:\n");
	for(i=0;i<n;i++) printf("x%d= %.3lf\n",i+1,a[i][n]/a[i][i]);
}