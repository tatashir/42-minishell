#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        // プロンプトを表示
        printf("myshell> ");
        fflush(stdout);

        // ユーザーからの入力を受け取る
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break; // 入力がない場合、ループを終了
        }

        // 改行文字を削除
        input[strcspn(input, "\n")] = '\0';

        // ユーザーがexitコマンドを入力したら終了
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // 子プロセスを作成してコマンドを実行
        pid_t pid = fork();

        if (pid == -1) {
            perror("fork");
        } else if (pid == 0) { // 子プロセス
            // コマンドを実行
            int result = execlp(input, input, NULL);
            
            // execlpが成功しなかった場合
            if (result == -1) {
                perror("execlp");
                exit(1);
            }
        } else { // 親プロセス
            // 子プロセスの終了を待つ
            wait(NULL);
        }
    }

    return 0;
}

