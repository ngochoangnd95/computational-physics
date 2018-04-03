#include<stdio.h>
#include<math.h>
double f(double x) {return 1/(x*x+1);}
int main() {
	double a, b, h, I, s0, s1, s2, Itemp, err=1e-6;
	int i, n=1;
	printf("Nhap a,b: "); scanf("%lf %lf",&a,&b);
	h=(b-a);
	s1=0; s2=0; s0=f(a)+f(b);
	I=h/3*s0;
	do {
		Itemp=I;
		n*=2; h/=2;
		s1+=s2; s2=0;
		for(i=1;i<n;i+=2) s2+=f(a+i*h);
		I=h/3*(s0+2*s1+4*s2);
	} while(fabs((I-Itemp)/I)>err);
	printf("Tich phan ham f(x) trong khoang a,b bang: %.18lf\n",I);
}