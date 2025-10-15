#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

// Sim�lasyon Fonksiyonu 
void kisitli_toplama_simulasyonu() {
	char rakam1_char, rakam2_char;
	int deger1, deger2, toplam;
	
	// 1. A�ama: K�s�tl� Standart Giri�ten (stdin) Karakter Okuma
	// Not: scanf("%c", ...) veya getchar() ile okuma, karakter tabanl� k�s�tl� I/O'yu sim�le eder.
	printf("Lutfen ilk tek haneli rakami girin (ASCII karakteri olarak): ");
	if (scanf (" %c", &rakam1_char) != 1) {
		fprintf(stderr, "Hata: Girdi okunamadi.\n");
		return;
	}
	printf("Lutfen ikinci tek haneli rakami girin (ASCII karakteri olarak): ");
	// �kinci girdiyi al�rken aradaki bo�luklar� atlamak i�in ' ' kullan�l�r.
	if(scanf (" %c", &rakam2_char) != 1 ){
		fprintf(stderr, "Hata: Girdi okunamadi.\n");
		return;
	}

	// 2. A�ama: ASCII Karakterden Say�sal De�ere D�n��t�rme	
	// Karakter '0' ile '9' aras�nda m� kontrol edilir.
	// ASCII sistemlerinde, '0' karakterinin say�sal de�eri di�er rakam karakterlerinin
	// temelini olu�turur. '1' - '0' = 1 gibi.
	
	if (rakam1_char < '0' || rakam1_char > '9' || rakam2_char < '0' || rakam2_char > '9'){
		printf("\nKisitli Sim�lasyon Hatasi: Sadece tek haneli rakam karakterleri (0-9) kabul edilir.\n");
		return;	
	}
		
	deger1 = rakam1_char - '0';
	deger2 = rakam2_char - '0';
		
	// 3. A�ama: Toplama ��lemi (K�s�tl� Aritmetik)
	toplam = deger1 + deger2 ;
		
	// 4. A�ama: Tek Haneli Sonu� Kontrol Mekanizmas�
	// Sim�lasyon k�s�tlamas�: Sonucun 9'u (tek hanenin maksimum de�eri) a�mamas� gerekir.
	if (toplam > 9) {
		// Hata Durumu (K�s�tl� Sistem Kural� �hlali)
		printf("\nKisitli Sim�lasyon Hatasi:\n");
		printf("Girdiler: %d ve %d\n", deger1, deger2);
		printf("Hesaplanan Toplam: %d\n", toplam);
		printf("Kural: Toplama sonucu tek haneli kalmalidir (<= 9).\n");
		printf("Sistem kuralini astiniz. Program sonlandiriliyor.\n");
	} else {
		// Ba�ar�l� Durum
		// Sonucu tekrar ASCII karaktere �evirip ��kt� vermek, k�s�tl� I/O'ya daha uygun olabilir.
		char sonuc_char = toplam + '0';
		printf("\nKisitli Sim�lasyon Basarili:\n");
		printf("Girdiler :'%c' (%d) ve '%c' (%d)\n", rakam1_char, deger1, rakam2_char, deger2);
		printf("Toplam (Sayisal): %d\n", toplam);
		printf("Kisitli Cikti (ASCII Karakteri): '%c'\n", sonuc_char);	
	}
}

// Ana Fonksiyon
int main (){
	printf("--- Unix Oncesi Kisitli I/O ve Aritmrtik Sim�lasyonu ---\n");
	kisitli_toplama_simulasyonu();
	return 0;
}
