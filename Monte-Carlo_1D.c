#include<stdio.h>
#include<stdlib.h>
double f(double x) {return 1/(x*x+1);}
double ran() {return rand()/(double)RAND_MAX;}
int main() {
	double a, b, x, s=0;
	int i, N=1e6;
	printf("Nhap a,b: "); scanf("%lf %lf",&a,&b);
	for(i=0;i<N;i++) {
		x=a+(b-a)*ran();
		s+=f(x)/N;
	}
	printf("Tich phan I = %.18lf\n",(b-a)*s);
}