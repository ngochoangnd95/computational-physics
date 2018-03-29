#include<stdio.h>
#include<math.h>
double f(double x) {return x*x*x-5*x+1;}
int main() { 
	double a, b;
	printf("Nhap khoang a, b: "); scanf("%lf %lf",&a,&b);
	double c, err=1e-12; int k=0;
	c=a;
	while(fabs(f(c))>err) {
		c=(a*f(b)-b*f(a))/(f(b)-f(a));
		if(f(c)*f(a)>0) a=c; else b=c;
		k++;
	}
	printf("Nghiem = %lf\n",c);
	printf("So buoc thuc hien: %d\n",k);
}