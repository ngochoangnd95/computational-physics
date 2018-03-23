#include<stdio.h>
#include<math.h>
int main() {
	int n, i, j, k, imax;
	printf("Nhap co ma tran cua Ax=b:\nn= "); scanf("%d",&n);
	double a[n][n+1], p, q, s, x[n];
	printf("Nhap gia tri cho ma tran:\n");
	for(i=0;i<n;i++) {
		printf("Hang thu %d: ",i+1);
		for(j=0;j<n+1;j++) scanf("%lf",&a[i][j]);
	}
	/*Gauss Elimination + Interchange*/
	for(k=0;k<n-1;k++) {
		imax=k;
		for(i=k+1;i<n;i++) if(fabs(a[i][k])>fabs(a[imax][k])) imax=i;
		for(j=0;j<n+1;j++) {
			p=a[k][j];
			a[k][j]=a[imax][j];
			a[imax][j]=p;
		}
		for(i=k+1;i<n;i++) {
			q=a[i][k]/a[k][k];
			for(j=k;j<n+1;j++) a[i][j]-=q*a[k][j];
		}
	}
	/*Back subtraction + Show solution*/
	printf("Nghiem he phuong trinh la:\n");
	for(i=n-1;i>=0;i--) {
		s=0;
		for(j=i+1;j<n;j++) s+=a[i][j]*x[j];
		x[i]=(a[i][n]-s)/a[i][i];
		printf("x%d= %.3lf\n",i+1,x[i]);
	}
}
