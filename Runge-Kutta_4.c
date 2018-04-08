#include<stdio.h>
double f(double x,double y) {return 4*x-2*x*y;}
int main() {
	int i, n=1e6;
	double h, x=0, y=1, X=0.5, k1, k2, k3, k4;
	h=(X-x)/n; printf("%lf\n",h*n);
	for(i=0;i<n;i++) {
		k1=f(x,y);
		k2=f(x+h/2,y+h/2*k1);
		k3=f(x+h/2,y+h/2*k2);
		k4=f(x+h,y+h*k3);
		y+=h/6*(k1+2*k2+2*k3+k4);
		x+=h;
	}
	printf("Tai X=0.5, Y= %.18lf\n",y);
}