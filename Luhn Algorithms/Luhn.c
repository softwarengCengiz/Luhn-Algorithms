#include <stdio.h>
#include <stdlib.h>
#pragma warning (disable :4996)


int main() {

    FILE* dosya;
    dosya = fopen("Numbers.txt", "r");

    if (dosya == NULL) {
        printf("Dosya bulunamadi!");
        exit(0);
    }

    int dizi[200];
    char karakter;

    int i = 0;

    do {
        karakter = fgetc(dosya);
        dizi[i] = (int)karakter - 48;
        i++;
    } while (karakter != EOF);

	fclose(dosya);


	int onlar, birler, toplaSayi = 0, realToplam = 0;

	printf("Dosyadan Okunan Sayilar--->>> ");
	for (int i = 0; i <= 15; i++) {
		printf("%d ", dizi[i]);
	}
	printf("\n\n");

	dizi[0] *= 2;
	dizi[2] *= 2;
	dizi[4] *= 2;
	dizi[6] *= 2;
	dizi[8] *= 2;
	dizi[10] *= 2;
	dizi[12] *= 2;
	dizi[14] *= 2;

	printf("Formatli Hali------------->>> ");
	for (int i = 0; i <= 15; i++) {
		printf("%d ", dizi[i]);

		if (dizi[i] > 9) {
			birler = dizi[i] % 10;
			onlar = dizi[i] /= 10;
			toplaSayi = birler + onlar;
			dizi[i] = toplaSayi;
		}
	}

	printf("\n\n");
	printf("Toplama Girecek Hali------>>> ");
	for (int i = 0; i <= 15; i++) {
		printf("%d ", dizi[i]);
	}

	printf("\n\n");
	for (int i = 0; i <= 15; i++) {
		realToplam += dizi[i];
	}
	printf("Dizinin Toplami----->>>  %d", realToplam);

	if (realToplam % 10 == 0) {
		printf("  ---Gecerli");
	}
	else {
		printf("  ---Gecersiz");
	}
	printf("\n\n");
}