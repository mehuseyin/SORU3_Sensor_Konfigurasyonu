#include <stdio.h>

enum GRange {
    G_2G = 0b00,
    G_4G = 0b01,
    G_8G = 0b10,
    G_16G = 0b11
};
enum Bandwidth {
    BW_7_81Hz = 0b000,
    BW_15_63Hz = 0b001,
    BW_31_25Hz = 0b010,
    BW_62_5Hz = 0b011,
    BW_125Hz = 0b100,
    BW_250Hz = 0b101,
    BW_500Hz = 0b110,
    BW_1000Hz = 0b111
};
enum OperationMode {
    Normal = 0b000,
    Suspend = 0b001,
    LowPower1 = 0b010,
    Standby = 0b011,
    LowPower2 = 0b100,
    DeepSuspend = 0b101
};

int a,b,i;
int main(){
i=G_16G+BW_1000Hz;
printf("%x",i);


}