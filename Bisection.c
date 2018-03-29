#include<stdio.h>
#include<math.h>
double f(double x) {return x*x*x-5*x+1;}
int main() {
	double a, b;
	printf("Nhap khoang a, b: "); scanf("%lf %lf",&a,&b);
	double mid, err=1e-12;
	int k=0;
	while(fabs(b-a)>err) {
		mid=(a+b)/2;
		if(f(a)*f(mid)<0) b=mid;
		if(f(a)*f(mid)>0) a=mid;
		if(f(a)*f(mid)==0) break;
		k++;
	}
	printf("Nghiem = %lf\n",mid);
	printf("So buoc thuc hien k = %d\n",k);
}