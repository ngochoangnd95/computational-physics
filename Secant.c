#include<stdio.h>
#include<math.h>
double f(double x) {return x*x*x-5*x+1;}
int main() { 
	double a, b;
	printf("Nhap khoang a, b: "); scanf("%lf %lf",&a,&b);
	double x0, x1, x2, err=1e-12; int k=0;
	x1=a; x2=b;
	while(fabs(x2-x1)>err) {
		x0=x1;
		x1=x2;
		x2=x0-(x1-x0)/(f(x1)-f(x0))*f(x0);
		k++;
	}
	printf("Nghiem = %lf\n",x2);
	printf("So buoc thuc hien: %d\n",k);
}