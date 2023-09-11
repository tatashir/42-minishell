#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_COMMAND_LENGTH 50

int main() {
    char command[MAX_COMMAND_LENGTH];

    while (1) {
        printf("シェル> ");
        fgets(command, sizeof(command), stdin);
        command[strlen(command) - 1] = '\0';  // 改行文字を削除

        // エンターキーが押された場合、新しいプロンプトを表示
        if (strlen(command) == 0) {
            continue;
        }

        // 入力を小文字に変換して処理を簡略化
        for (int i = 0; command[i]; i++) {
            command[i] = tolower(command[i]);
        }

        // コマンド別に処理を実行
        if (strcmp(command, "hello") == 0) {
            printf("こんにちは！\n");
        } else if (strcmp(command, "date") == 0) {
            // 現在の日付と時刻を表示
            system("date");
        } else if (strcmp(command, "exit") == 0) {
            printf("シェルを終了します。\n");
            break;
        } else {
            printf("コマンドが不明です。\n");
        }
    }

    return 0;
}

