#include "stdafx.h"
#include "Color.h"
#include"product.h"
#include "myStoreroom.h"

void ProductInputAndPutData(STOREROOM *sRoom){
	
	PRODUCT *product;
	int nProduct;
	printf("Number of product to enter: ");
	scanf("%d", &nProduct);
	product = (PRODUCT*)calloc(nProduct, sizeof(PRODUCT));
	for (size_t filled = 0; filled < nProduct; ++filled) {
		ProdductInpuAndPushtData(product,filled);
	}

}
void ProdductInpuAndPushtData(PRODUCT *product,size_t filled) {
	//TITLE
	char str[64];
	printf("Enter name of product: ");
	scanf("%s", &str);
	strcpy(product[filled].title, str);

	while (getchar() != '\n');
	//PRICE
	printf("Enter price: ");
	scanf("%lf", product[filled].price);
	//WEIGHT
	printf("Enter weight: ");
	scanf("%lf", product->weight);
	//COLOR
	int std = 0;
	printf("CHOOSE COLOR\n");
	printf("[0]-CZARNY\n"
		"[1]-BIA£Y\n"
		"[2]-ZIELONY\n"
		"[3]-RÓ¯OWY\n"
		"[4]-POMARAÑCZOWY\n"
		"[5]-BR¥ZOWY\n"
		"[6]-¯Ó£TY\n"
		"[7]-CZERWONY\n"
		"[8]-NIEBIESKI\n"
		"[9]-FIOLETOWY\n"
		"[10]-SZARY\n");
	scanf("%d", &std);
	switch (std)
	{
	case CZARNY:
		product[filled].color = COLOR::CZARNY;
		break;
	case BIA£Y:
		product[filled].color = COLOR::BIA£Y;
		break;
	case ZIELONY:
		product[filled].color = COLOR::ZIELONY;
		break;
	case RÓ¯OWY:
		product[filled].color = COLOR::RÓ¯OWY;
		break;
	case POMARAÑCZOWY:
		product[filled].color = COLOR::POMARAÑCZOWY;
		break;
	case BR¥ZOWY:
		product[filled].color = COLOR::BR¥ZOWY;
		break;
	case ¯Ó£TY:
		product[filled].color = COLOR::¯Ó£TY;
		break;
	case CZERWONY:
		product[filled].color = COLOR::CZERWONY;
		break;
	case NIEBIESKI:
		product[filled].color = COLOR::NIEBIESKI;
		break;
	case FIOLETOWY:
		product[filled].color = COLOR::FIOLETOWY;
		break;
	case SZARY:
		product[filled].color = COLOR::SZARY;
		break;
	}
}
void ProductPrint(void *ptr) {
	PRODUCT *product = (PRODUCT*)ptr;
	size_t filled;
	for (filled = 0; filled < 3; ++filled) {
		printf("%s\n%lf\%lf\n", product[filled].title, product[filled].price, product[filled].weight);
		printf("%d\n", product[filled].price);
	}

	for
}
