#include<stdio.h>
double f(double x,double y,double z) {return 6*y-z;}
double g(double x,double y,double z) {return z;}
int main() {
	int i,n=1e6;
	double h, x=0, y=3, z=1, X=1, k11, k12, k21, k22, k31, k32, k41, k42;
	h=(X-x)/n;
	for(i=0;i<n;i++) {
		k11=g(x,y,z);
		k12=f(x,y,z);
		k21=g(x+h/2,y+h/2*k11,z+h/2*k12);
		k22=f(x+h/2,y+h/2*k11,z+h/2*k12);
		k31=g(x+h/2,y+h/2*k21,z+h/2*k22);
		k32=f(x+h/2,y+h/2*k21,z+h/2*k22);
		k41=g(x+h,y+h*k31,z+h*k32);
		k42=f(x+h,y+h*k31,z+h*k32);
		y+=h/6*(k11+2*k21+2*k31+k41);
		z+=h/6*(k12+2*k22+2*k32+k42);
		x+=h;
	}
	printf("Tai X=1, Y= %.18lf\n",y);
}