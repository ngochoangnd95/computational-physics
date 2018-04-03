#include<stdio.h>
#include<stdlib.h>
double f(double x,double y) {return x*x+y*y;}
double ran() {return (rand()/(double)RAND_MAX);}
int main() {
	double a, b, c=3, d=4, x, y, p, q=0;
	int i, j, N=1e4;
	for(j=0;j<N;j++) {
		y=c+(d-c)*ran();
		p=0;
		for(i=0;i<N;i++){
			a=y-1; b=y;
			x=a+(b-a)*ran();
			p+=f(x,y);
		}
		q+=(b-a)*p/N;
	}
	printf("I = %.9lf\n",(d-c)*q/N);
}