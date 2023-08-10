#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int local_268[6];
    int local_290;

    srand(time(NULL));  // Seed with current time
    local_268[0] = 0x79;
    local_268[1] = 0x12c97f;
    local_268[2] = 0x135f0f8;
    local_268[3] = 0x74acbc6;
    local_268[4] = 0x56c614e;
    local_268[5] = 0xffffffe2;

    for (int local_28c = 0; local_28c < 6; local_28c++) 
    {
        int iVar1 = rand();
        local_268[local_28c] = local_268[local_28c] - (iVar1 % 10 + -1);
    }

    int local_288 = 0;
    for (int local_284 = 0; local_284 < 6; local_284++) 
    {
        local_288 = local_288 + local_268[local_284];
    }

    local_290 = local_288;
    printf("%d\n", local_290);
    return 0;
}
