#include <stdio.h>
#include <stdint.h> 
#include <stdlib.h>

// Enum tanımları
 enum GRange{
    G_2G = 0b00,
    G_4G = 0b01,
    G_8G = 0b10,
    G_16G = 0b11
} ;
 enum Bandwidth{
    BW_7_81Hz = 0b000,
    BW_15_63Hz = 0b001,
    BW_31_25Hz = 0b010,
    BW_62_5Hz = 0b011,
    BW_125Hz = 0b100,
    BW_250Hz = 0b101,
    BW_500Hz = 0b110,
    BW_1000Hz = 0b111
} ;
 enum OperationMode{
    Normal = 0b000,
    Suspend = 0b001,
    LowPower1 = 0b010,
    Standby = 0b011,
    LowPower2 = 0b100,
    DeepSuspend = 0b101
} ;

// Struct tanımılıyoruz
struct parameters{
    int gRange;
    int bandwidth;
    int operationMode;
    uint8_t AccConfigValue; 
} ;




int main() {
    int gRangeChoice, bandwidthChoice, operationModeChoice;
    // Kullanıcıdan parametreleri alma  
    printf("G Range Secin (0: 2G, 1: 4G, 2: 8G, 3: 16G): ");
    scanf("%d", &gRangeChoice);

    printf("Bandwidth Secin (0: 7.81Hz, 1: 15.63Hz, 2: 31.25Hz, 3: 62.5Hz, 4: 125Hz, 5: 250Hz, 6: 500Hz, 7: 1000Hz): ");
    scanf("%d", &bandwidthChoice);

    printf("Operation Mode Secin (0: Normal, 1: Suspend, 2: LowPower1, 3: Standby, 4: LowPower2, 5: DeepSuspend): ");
    scanf("%d", &operationModeChoice);

    // Struct olusturma ve hesaplama
    struct parameters config;
    config.gRange = gRangeChoice;
    config.bandwidth = bandwidthChoice;
    config.operationMode = operationModeChoice;

    // Konfigürasyon değerini hesaplayan fonksiyonu cagır
    binaryH(&config);

    // istenilenturlerde çıktılar veriliyor
    printf("\nAccConfigValue (Decimal): %d\n", config.AccConfigValue);
    printf("AccConfigValue (Hexadecimal): 0x%X\n", config.AccConfigValue);
    printf("AccConfigValue (Binary): 0b");
    binaryYaz(config.AccConfigValue);
    printf("\n");


    return 0;
}

// binary değerleri birlestiren fonksiyon
void binaryH(struct parameters* config) {
    // Bitwise işlemlerle AccConfigValue hesaplanıyor
    //-> ile config adlı structtan değişkenler çekiliyor                                                                                                                                       
    config->AccConfigValue = (config->gRange ) | (config->bandwidth << 2) | (config->operationMode<<5);
}

// binary çıktısı için fonksiyon
void binaryYaz(uint8_t value) {
    for (int i = 7; i >= 0; i--) {
        printf("%c", (value & (1 << i)) ? '1' : '0');
    }
}