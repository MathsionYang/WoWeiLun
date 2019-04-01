
#include "math.h"
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
double recurve(int n, int m) {
	double kinds;
	if (n == 1) {
		kinds = m;
	}
	if (n == 2) {
		kinds = m * (m - 1);
	}
	if (n == 3) {
		kinds = m * (m - 1)*(m - 2);
	}
	if (n > 3) {
		kinds = m * pow(m - 1, n - 1) - recurve(n - 1, m);
	}
	return kinds;
}
int main()
{
	int n, m;
	double kind;
	scanf("%d %d", &n, &m);
	kind = recurve(n, m);
	printf("%f", kind);
	system("pause");
	return 0;
}

