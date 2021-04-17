//main.c
#include <stdio.h>
#include <stdlib.h>
#include "manager.h"

int main() {
	Product *plist[20];
	int idx=0;
	int menu;
	int count=0;

	while(1) {
		menu=selectMenu();
		if(menu==0) break;
		else if(menu==1) {
			#ifdef DEBUG
				printf("=> DEBUGMODE\n");
			#endif
				if (count>0) listProduct(plist, idx);
				else printf("저장된 과일이 없습니다.\n");
		}
		else if(menu==2) {
			plist[idx] = (Product*)malloc(sizeof(Product));
			#ifdef DEBUG
				printf("=> DEBUGMODE\n");
			#endif
				addProduct(plist[idx++]);
			count++;
		}
		else if(menu==3) {
			#ifdef DEBUG
				printf("=> DEBUGMODE\n");
			#endif
				int n = selectionDataNo(plist, idx);
			if (count>0) listProduct(plist, idx);
			else printf("저장된 과일이 없습니다.\n");
			#ifdef DEBUG
				printf("=> DEBUGMODE\n");
			#endif
				if (n>0) updateProduct(plist[n-1]);
				else printf("취소됨\n");
		}
		else if(menu==4) {
			int n = selectionDataNo(plist, idx);
			if (n>0) {
				printf("정말로 삭제하시겠습니까? (삭제:1) ");
				int delok;
				scanf("%d", &delok);
				if (delok==1) { 
					if(plist[n-1]) free(plist[n-1]);
					plist[n-1] = NULL;
					printf("=> 삭제됨!\n");
					count--;
				}
			}
		}
		else if(menu==5) {
			saveData(plist, idx);
		}
		else if(menu==6) {
			searchName(plist, idx);
		}
		else if(menu==7) {
			searchRate(plist, idx);
		}
		else if(menu==8) {
			searchPrice(plist, idx);
		}
	}
	printf("=> 종료됨!\n");
	return 0;
}
