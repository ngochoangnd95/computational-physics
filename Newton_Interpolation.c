#include<stdio.h>
int main() {
	int n, i, j;
	printf("Nhap so diem cho truoc: "); scanf("%d",&n);
	double x[n], y[n], X, Y=0, L, D[n][n];
	for(i=0;i<n;i++) {
		printf("(x%d,y%d)= ",i,i); scanf("%lf %lf",&x[i],&y[i]);
	}
	printf("X= "); scanf("%lf",&X);
	for(j=0;j<n;j++) {
		if(j==0) 
			for(i=0;i<n;i++) D[i][j]=y[i];
		else 
			for(i=j;i<n;i++) D[i][j]=(D[i][j-1]-D[i-1][j-1])/(x[i]-x[i-j]);
		L=1;
		for(i=0;i<j;i++) L*=X-x[i];
		Y+=D[j][j]*L;
	}
	printf("Y= %lf\n",Y);
}