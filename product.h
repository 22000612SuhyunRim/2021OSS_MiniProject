//product.h

typedef struct {
    char name[50];
    int gram;
    int price;
    int rate;
    int rateNum;
} Product;

int selectMenu();
void addProduct(Product *p);
void readProduct(Product p);
int updateProduct(Product *p);
int deleteProduct(Product *p);
