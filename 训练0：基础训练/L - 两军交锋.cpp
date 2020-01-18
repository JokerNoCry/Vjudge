#include <stdio.h>
int main ()
{
	float u,v,w,l,t,time,s;
	scanf("%f",&t);
	while(t--)
	{
		scanf("%f%f%f%f",&u,&v,&w,&l);
		time=l/(u+v);
		s=time*w;
		printf("%.3f\n",s);
	}
	return 0;
 } 
