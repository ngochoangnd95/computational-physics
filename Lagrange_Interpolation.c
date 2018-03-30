#include<stdio.h>
int main() {
	int n, i, j;
	printf("Nhap so diem cho truoc: "); scanf("%d",&n);
	double x[n], y[n], X, Y=0, L;
	printf("Nhap toa do cac diem:\n");
	for(i=0;i<n;i++) {
		printf("(x%d,y%d)= ",i,i); scanf("%lf %lf",&x[i],&y[i]);
	}
	printf("X= "); scanf("%lf",&X);
	for(i=0;i<n;i++) {
		L=1;
		for(j=0;j<n;j++) if(j!=i) L*=(X-x[j])/(x[i]-x[j]);
		Y+=L*y[i];
	}
	printf("Y= %lf\n",Y);
}