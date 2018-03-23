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
	/*Gauss-Jordan Elimination*/
	for(k=0;k<n;k++) {
		p=a[k][k];
		for(j=k;j<n+1;j++) a[k][j]/=p;
		for(i=0;i<n;i++) if(i!=k) {
			p=a[i][k];
			for(j=k;j<n+1;j++) a[i][j]-=p*a[k][j];
		}
	}
	/*Show solution*/
	printf("Nghiem he phuong trinh la:\n");
	for(i=0;i<n;i++) printf("x%d= %.3lf\n",i+1,a[i][n]/a[i][i]);
}