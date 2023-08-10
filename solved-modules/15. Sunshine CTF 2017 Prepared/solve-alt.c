#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    int randVal;
    int check;
    char target[504];
    char input[512];

    srand(0x135f0f8);

    for (int i = 0; i < 50; i++) {
        randVal = rand() % 100;
        printf("%d days without an incident.\n", i);
        sprintf(target, "%d", randVal);
        
        // Simulate input to the target program
        strncpy(input, target, sizeof(input));
        input[sizeof(input) - 1] = '\0';  // Ensure null-terminated

        // Run the target program and provide input
        FILE *pipe = popen("./your_target_program", "w");
        if (pipe == NULL) {
            perror("Failed to open pipe");
            return 1;
        }

        fprintf(pipe, "%s\n", input);
        pclose(pipe);
    }

    // Assuming level is cleared, print the flag
    printf("Level Cleared! Here's the flag:\n");
    FILE *flagFile = fopen("flag.txt", "r");
    if (flagFile != NULL) {
        char flag[128];
        while (fgets(flag, sizeof(flag), flagFile)) {
            printf("%s", flag);
        }
        fclose(flagFile);
    } else {
        printf("Flag file not found.\n");
    }

    return 0;
}
