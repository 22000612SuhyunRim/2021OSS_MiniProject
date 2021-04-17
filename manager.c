//manager.c

#include <stdio.h>
#include "manager.h"
void listProduct(Product *p[], int count){
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for (int i=0;i<count;i++) {
		if(p[i]==NULL) continue;
		printf("%d", i+1);
		readProduct(*p[i]);
	}
}
int selectionDataNo(Product *p[], int count) {
	int n=0;
	listProduct(p, count);
	printf("번호는? (취소:0) ");
	scanf("%d", &n);
	return n;
}
