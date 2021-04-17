//product.c
#include <stdio.h>
#include "product.h"

int selectMenu() {
	int menu;
	printf("\n****Fruit Shop****\n");
	printf("1. 조회\n");
	printf("2. 추가\n");
	printf("3. 수정\n");
	printf("4. 삭제\n");
	printf("5. 파일저장\n");
	printf("6. 제품이름검색\n");
	printf("7. 별점검색\n");
	printf("8. 가격검색\n");
	printf("0. 종료\n");
	printf("=> 원하는 메뉴는?\n");
	scanf("%d", &menu);
	return menu;
}

void addProduct(Product *p) {
	printf("제품명은? ");
	scanf(" %[^\n]", p->name);
	printf("중량은? ");
	scanf("%d", &p->gram);
	printf("판매가격은? ");
	scanf("%d", &p->price);
	printf("별점은? ");
	scanf("%d", &p->rate);
	printf("별점개수는? ");
	scanf("%d", &p->rateNum);
	printf("=> 추가됨!\n");
}

void readProduct(Product p) {
	printf("  %10s %6d %10d %5d %10d\n", p.name, p.gram, p.price, p.rate, p.rateNum);
}

int updateProduct(Product *p) {
	printf("새 제품명은? ");
	scanf(" %[^\n]", p->name);
	printf("새 제품의 중량은? ");
	scanf("%d", &p->gram);
	printf("새 제품의 판매가격은? ");
	scanf("%d", &p->price);
	printf("새 제품의 별점은? ");
	scanf("%d", &p->rate);
	printf("새 제품의 별점개수는? ");
	scanf("%d", &p->rateNum);
	printf("=> 수정성공!\n");

	return 1;
}

int deleteProduct(Product *p) {
	p->gram=-1;
	p->price=-1;
	p->rate=-1;
	p->rateNum=-1;

	return 1;
}
