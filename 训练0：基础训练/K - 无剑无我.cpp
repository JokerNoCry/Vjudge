#include <stdio.h>
#include <math.h>
float f(float a,float b,float c,float d)
{
	float x,y;
	x=a-c;
	y=b-d;
	float dx=sqrt(x*x+y*y);
	return dx;
}
int main ()
{
	int t;
	float a,b,c,d;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%f%f%f%f",&a,&b,&c,&d);
		printf("%.1f\n",f(a,b,c,d));
	}
	return 0;
}
