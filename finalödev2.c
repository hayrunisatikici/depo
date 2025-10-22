#include <stdio.h>

// Sharpe Oranýný hesaplayan fonksiyon
double hesaplaSharpeOrani(double yatirimGetirisi, double risksizFaizOrani, double standartSapma) {
    // Standart sapmanýn sýfýr olmasý durumunu kontrol et
    if (standartSapma == 0.0) {
        // Bu durumda Sharpe Oraný tanýmsýzdýr veya sonsuzdur (pratikte sýfýr risk kabul edilmez)
        return -1.0; // Hata sinyali olarak negatif deðer döndürelim
    }

    // Sharpe Oraný Formülü: (Yatýrým Getirisi - Risksiz Faiz Oraný) / Standart Sapma
    return (yatirimGetirisi - risksizFaizOrani) / standartSapma;
}

// Ana fonksiyon
int main() {
    // Deðiþken tanýmlamalarý
    double getiri, risksizFaiz, standartSapma, sharpeOrani;

    // Kullanýcýdan giriþleri al
    printf("--- Sharpe Oraný Hesaplama Programý ---\n\n");

    // Yatýrým Getirisi
    printf("Yatýrýmýn Yýllýk Getirisini (örneðin %%15 için 0.15) giriniz: ");
    if (scanf("%lf", &getiri) != 1) {
        printf("Hatalý giriþ yaptýnýz.\n");
        return 1;
    }

    // Risksiz Faiz Oraný
    printf("Risksiz Faiz Oranýný (örneðin %%5 için 0.05) giriniz: ");
    if (scanf("%lf", &risksizFaiz) != 1) {
        printf("Hatalý giriþ yaptýnýz.\n");
        return 1;
    }

    // Portföyün Standart Sapmasý (Risk)
    printf("Portföyün Standart Sapmasýný (Riskini) (örneðin %%12 için 0.12) giriniz: ");
    if (scanf("%lf", &standartSapma) != 1) {
        printf("Hatalý giriþ yaptýnýz.\n");
        return 1;
    }

    // Sharpe Oranýný hesapla
    sharpeOrani = hesaplaSharpeOrani(getiri, risksizFaiz, standartSapma);

    // Sonucu ekrana yazdýr ve deðerlendir
    if (sharpeOrani < 0) {
        printf("\nUYARI: Standart Sapma sýfýr olamaz veya hesaplamada bir hata oluþtu.\n");
    } else {
        printf("\n--- Hesaplama Sonucu ---\n");
        printf("Sharpe Oraný = (%.4f - %.4f) / %.4f = %.4f\n",
               getiri, risksizFaiz, standartSapma, sharpeOrani);

        printf("\n--- Deðerlendirme ---\n");
        if (sharpeOrani >= 3.0) {
            printf("Sharpe Oraný deðeri mükemmel (>= 3.0) kabul edilir.\n");
        } else if (sharpeOrani >= 2.0) {
            printf("Sharpe Oraný deðeri çok iyi (>= 2.0) kabul edilir.\n");
        } else if (sharpeOrani >= 1.0) {
            printf("Sharpe Oraný deðeri iyi (>= 1.0) kabul edilir.\n");
        } else {
            printf("Sharpe Oraný deðeri 1.0'in altýndadýr.\n");
        }
    }

    return 0;
}
