#include<stdio.h>
int main() {
	int n, i, j, k=0;
	printf("Nhap co he phuong trinh:\nn= "); scanf("%d",&n);
	double a[n][n+1];
	printf("Nhap gia tri cho ma tran:\n");
	for(i=0;i<n;i++) {
		printf("Hang thu %d: ",i+1);
		for(j=0;j<n+1;j++) scanf("%lf",&a[i][j]);
	}
	double x0[n], x[n], S, err=1e-9, delta;
	for(i=0;i<n;i++) x0[i]=0;
	do {
		for(i=0;i<n;i++) {
			S=0;
			for(j=0;j<n;j++) if(j!=i) S+=a[i][j]*x0[j];
			x[i]=(a[i][n]-S)/a[i][i];
		}
		delta=0;
		for(i=0;i<n;i++) {
			delta+=(x[i]-x0[i])*(x[i]-x0[i]);
			x0[i]=x[i];
		}
		k++;
	} while(delta>err);
	printf("Nghiem he pt la:\n");
	for(i=0;i<n;i++) printf("x[%d]= %lf\n",i+1,x[i]);
	printf("Voi so buoc lap la k= %d\n",k);
}