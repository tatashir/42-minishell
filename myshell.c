#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 50

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("myshell> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';

        if (strlen(command) == 0) {
            continue;
        }

        for (int i = 0; command[i]; i++) {
            command[i] = tolower(command[i]);
        }

        if (strcmp(command, "date") == 0) {
            // 現在の日付と時刻を表示
            system("date");
        } else if (strcmp(command, "clear") == 0) {
            // clearコマンドを実行
            //clearTerminal();
            system("clear");
        } else if (strcmp(command, "exit") == 0) {
            printf("exit\n");
            break;
        } else {
            printf("command not found\n");
        }
    }

    return 0;
}