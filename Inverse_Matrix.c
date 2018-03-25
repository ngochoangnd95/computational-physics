#include<stdio.h>
int main() {
	int n, i, j, k;
	printf("Nhap co ma tran A:\nn= "); scanf("%d",&n);
	double a[n][2*n],p;
	printf("Nhap gia tri cho ma tran A:\n");
	for(i=0;i<n;i++) {
		printf("Hang thu %d: ",i+1);
		for(j=0;j<n;j++) scanf("%lf",&a[i][j]);
		for(j=n;j<2*n;j++) if((j-n)==i) a[i][j]=1; else a[i][j]=0;
	}
	for(k=0;k<n;k++) {
		if(a[k][k]==0) {
			printf("Ma tran A khong the nghich dao.\n");
			return 0;
		}
		else p=a[k][k];
		for(j=k;j<2*n;j++) a[k][j]/=p;
		for(i=0;i<n;i++) if(i!=k) {
			p=a[i][k];
			for(j=k;j<2*n;j++) a[i][j]-=p*a[k][j];
		}
	}
	printf("Ma tran nghich dao cua A la:\n");
	for(i=0;i<n;i++) {
		for(j=n;j<2*n;j++) printf("%.3lf\t",a[i][j]);
		printf("\n");
	}
}