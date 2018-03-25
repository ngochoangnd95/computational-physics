#include<stdio.h>
#include<math.h>
int main() {
	int n, i, j, k, imax, sign=1;
	printf("Nhap co ma tran vuong n*n:\nn= "); scanf("%d",&n);
	double a[n][n], p;
	printf("Nhap gia tri cho ma tran:\n");
	for(i=0;i<n;i++) {
		printf("Hang thu %d: ",i+1);
		for(j=0;j<n;j++) scanf("%lf",&a[i][j]);
	}
	for(k=0;k<n-1;k++) {
		imax=k;
		for(i=k+1;i<n;i++) if(fabs(a[i][k])>fabs(a[imax][k])) imax=i;
		if(imax!=k) sign*=-1;
		for(j=0;j<n;j++) {
			p=a[k][j];
			a[k][j]=a[imax][j];
			a[imax][j]=p;
		}
		for(i=k+1;i<n;i++) {
			p=a[i][k]/a[k][k];
			for(j=k;j<n;j++) a[i][j]-=p*a[k][j];
		}
	}
	p=1;
	for(i=0;i<n;i++) p*=a[i][i];
	printf("Det= %.3lf\n",sign*p);
}