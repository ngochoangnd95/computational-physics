#include<stdio.h>
#include<math.h>
double f(double x) {return 1/(x*x+1);}
int main() {
	double a, b, s0, s1, s2, h, I, Itemp, err=1e-6;
	int n=1, i;
	printf("Nhap a,b: "); scanf("%lf %lf",&a,&b);
	h=b-a;
	s1=0; s0=(f(a)+f(b))/2;
	I=(s0+s1)*h;
	do {
		Itemp=I;
		n*=2; h/=2;
		s2=0;
		for(i=1;i<n;i+=2) s2+=f(a+i*h);
		s1+=s2;
		I=(s0+s1)*h;
	} while (fabs((I-Itemp)/I)>err);
	printf("Tich phan ham f(x) trong khoang a,b bang: %.18lf\n",I);
}