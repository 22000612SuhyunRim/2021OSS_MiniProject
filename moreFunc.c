//moreFunc.c

#include <stdio.h>

void saveData(Product *p, int count) {
	FILE *fp;
	fp = fopen("fruitshop.txt", "wt");
	for(int i=0;i<count;++i) {
		if(p[i]->price == NULL) continue;
		fprintf(fp, "%s, %d, %d, %d, %d", p[i]->name, p[i]->gram, p[i]->price, p[i]->rate, p[i]->rateNum );
	}
	fclose(fp);
	printf("=> 저장됨!\n");
}
int loadData(Product *p) {
	FILE *fp;
	fp = fopen("fruitshop.txt", "rt");
	if (fp==NULL) {
		printf("=> 파일없음!\n");
		return 0;
	}
	for(int i=0;i<20;++i) {
		fscanf(fp, "%s", p[i]->name);
		fscanf(fp, "%d", p[i]->gram);
		fscanf(fp, "%d", p[i]->price);
		fscanf(fp, "%d", p[i]->rate);
		fscanf(fp, "%d", p[i]->rateNum);
		if(feof(fp)) break;
	}
	fclose(fp);
	printf("=> 로딩성공!\n");
	return i;

}
void searchName(Product *p[], int count) {

}
void searchRate(Product *p[], int count) {

}
void searchPrice(Product *p[], int count) {

}
