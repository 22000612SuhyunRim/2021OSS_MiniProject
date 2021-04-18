//manager.c

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "manager.h"
void listProduct(Product *p[], int count){
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for (int i=0;i<count;i++) {
		if(p[i]==NULL) continue;
		if(p[i]->price==0) continue;
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
void saveData(Product *p[], int count) {
	FILE *fp;
	fp = fopen("fruitshop.txt", "w");
	for(int i=0;i<count;++i) {
		//if(p[i].price == NULL) continue;
		fprintf(fp, "%d %d %d %d %s\n", p[i]->gram, p[i]->price, p[i]->rate, p[i]->rateNum, p[i]->name);
	}
	fclose(fp);
	printf("=> 저장됨!\n");
}
int loadData(Product *p[]) {
	FILE *fp;
	int i=0;
	fp = fopen("fruitshop.txt", "r");
	if (fp==NULL) {
		printf("=> 파일없음!\n");
		return 0;
	}
	for(i=0;i<20;++i) {
		fscanf(fp, "%d", &p[i]->gram);
		fscanf(fp, "%d", &p[i]->price);			
		fscanf(fp, "%d", &p[i]->rate);
		fscanf(fp, "%d", &p[i]->rateNum);
		fgets(p[i]->name, 50, fp);
		p[i]->name[strlen(p[i]->name)-1] = '\0';
		printf("%s\n", p[i]->name);
		if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩성공!\n");
	return i+1;
}
void searchName(Product *p[], int count) {
	int check=0;
	char search[20];

	printf("검색할 과일 이름? ");
	scanf(" %[^\n]", search);
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for(int i=0;i<count;++i) {
		//if(p[i]->pice==NULL) continue;
		if(strstr(p[i]->name, search)!=NULL) {
			printf("%d", i+1);
			readProduct(*p[i]);
			check++;
		}
	}
	if(check==0) printf("검색된 데이터 없음!\n");
}
void searchPrice(Product *p[], int count) {
	int check=0;
	int search=0;

	printf("검색할 과일 가격? ");
	scanf(" %d", &search);
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for(int i=0;i<count;++i) {
		//if(p[i]->pice==NULL) continue;
		if(p[i]->price==search) {
			printf("%d", i+1);
			readProduct(*p[i]);
			check++;
		}
	}
	if(check==0) printf("검색된 데이터 없음!\n");
}
void searchRate(Product *p[], int count) {
	int check=0;
	int search=0;


	printf("검색할 과일 별점? ");
	scanf(" %d", &search);
	printf("      Name     gram    price    rate    rateNum\n");
	printf("=================================================\n");
	for(int i=0;i<count;++i) {
		//if(p[i]->price==NULL) continue;
		if(p[i]->rate==search) {
			printf("%d", i+1);
			readProduct(*p[i]);
			check++;
		}
	}
	if(check==0) printf("검색된 데이터 없음!\n");
}
