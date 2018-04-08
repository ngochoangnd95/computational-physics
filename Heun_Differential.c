#include<stdio.h>
double f(double x,double y) {return 4*x-2*x*y;}
int main() {
	int i, n=1e6;
	double h, x=0, y=1, X=0.5, p;
	h=(X-x)/n;
	for(i=0;i<n;i++) {
		p=y+h*f(x,y);
		y+=h/2*(f(x,y)+f(x+h,p));
		x+=h;
	}
	printf("Tai X=0.5, Y= %.18lf\n",y);
}