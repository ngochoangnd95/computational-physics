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
	double x[n], S, temp, err=1e-9, delta;
	for(i=0;i<n;i++) x[i]=0;
	do {
		delta=0;
		for(i=0;i<n;i++) {
			S=0;
			for(j=0;j<n;j++) if(j!=i) S+=a[i][j]*x[j];
			temp=x[i];
			x[i]=(a[i][n]-S)/a[i][i];
			delta+=(x[i]-temp)*(x[i]-temp);
		}
		k++;
	} while(delta>err);
	printf("Nghiem he pt la:\n");
	for(i=0;i<n;i++) printf("x[%d]= %lf\n",i+1,x[i]);
	printf("Voi so buoc lap la k= %d\n",k);
}
