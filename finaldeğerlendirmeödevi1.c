#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Simülasyon Fonksiyonu 
void kisitli_toplama_simulasyonu() {
	char rakam1_char, rakam2_char;
	int deger1, deger2, toplam;
	
	// 1. Aþama: Kýsýtlý Standart Giriþten (stdin) Karakter Okuma
	// Not: scanf("%c", ...) veya getchar() ile okuma, karakter tabanlý kýsýtlý I/O'yu simüle eder.
	printf("Lutfen ilk tek haneli rakami girin (ASCII karakteri olarak): ");
	if (scanf (" %c", &rakam1_char) != 1) {
		fprintf(stderr, "Hata: Girdi okunamadi.\n");
		return;
	}
	printf("Lutfen ikinci tek haneli rakami girin (ASCII karakteri olarak): ");
	// Ýkinci girdiyi alýrken aradaki boþluklarý atlamak için ' ' kullanýlýr.
	if(scanf (" %c", &rakam2_char) != 1 ){
		fprintf(stderr, "Hata: Girdi okunamadi.\n");
		return;
	}

	// 2. Aþama: ASCII Karakterden Sayýsal Deðere Dönüþtürme	
	// Karakter '0' ile '9' arasýnda mý kontrol edilir.
	// ASCII sistemlerinde, '0' karakterinin sayýsal deðeri diðer rakam karakterlerinin
	// temelini oluþturur. '1' - '0' = 1 gibi.
	
	if (rakam1_char < '0' || rakam1_char > '9' || rakam2_char < '0' || rakam2_char > '9'){
		printf("\nKisitli Simülasyon Hatasi: Sadece tek haneli rakam karakterleri (0-9) kabul edilir.\n");
		return;	
	}
		
	deger1 = rakam1_char - '0';
	deger2 = rakam2_char - '0';
		
	// 3. Aþama: Toplama Ýþlemi (Kýsýtlý Aritmetik)
	toplam = deger1 + deger2 ;
		
	// 4. Aþama: Tek Haneli Sonuç Kontrol Mekanizmasý
	// Simülasyon kýsýtlamasý: Sonucun 9'u (tek hanenin maksimum deðeri) aþmamasý gerekir.
	if (toplam > 9) {
		// Hata Durumu (Kýsýtlý Sistem Kuralý Ýhlali)
		printf("\nKisitli Simülasyon Hatasi:\n");
		printf("Girdiler: %d ve %d\n", deger1, deger2);
		printf("Hesaplanan Toplam: %d\n", toplam);
		printf("Kural: Toplama sonucu tek haneli kalmalidir (<= 9).\n");
		printf("Sistem kuralini astiniz. Program sonlandiriliyor.\n");
	} else {
		// Baþarýlý Durum
		// Sonucu tekrar ASCII karaktere çevirip çýktý vermek, kýsýtlý I/O'ya daha uygun olabilir.
		char sonuc_char = toplam + '0';
		printf("\nKisitli Simülasyon Basarili:\n");
		printf("Girdiler :'%c' (%d) ve '%c' (%d)\n", rakam1_char, deger1, rakam2_char, deger2);
		printf("Toplam (Sayisal): %d\n", toplam);
		printf("Kisitli Cikti (ASCII Karakteri): '%c'\n", sonuc_char);	
	}
}

// Ana Fonksiyon
int main (){
	printf("--- Unix Oncesi Kisitli I/O ve Aritmrtik Simülasyonu ---\n");
	kisitli_toplama_simulasyonu();
	return 0;
}
