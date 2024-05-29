#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <termios.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

// 시그널 핸들러 함수 정의
void handle_signal(int signal) {
    if (signal == SIGINT) {
        // 사용자 정의 처리 (아무 것도 하지 않음)
    }
}

// 터미널 설정 변경 함수
void disable_ctrl_c_output() {
    struct termios t;

    // 현재 터미널 설정 가져오기
    if (tcgetattr(STDIN_FILENO, &t) == -1) {
        perror("tcgetattr");
        exit(EXIT_FAILURE);
    }

    // ISIG 플래그 제거 (SIGINT, SIGQUIT 및 SIGTSTP 시그널을 무시)
    t.c_lflag &= ~ISIG;

    // 변경된 설정을 터미널에 적용
    if (tcsetattr(STDIN_FILENO, TCSANOW, &t) == -1) {
        perror("tcsetattr");
        exit(EXIT_FAILURE);
    }
}

int main() {
    // 시그널 핸들러 등록
    struct sigaction sa;
    sa.sa_handler = handle_signal;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    // Ctrl+C 출력 비활성화
    disable_ctrl_c_output();

    char *input;

    // 무한 루프를 통해 사용자 입력을 받음
    while ((input = readline("프로그램> ")) != NULL) {
        // 히스토리에 추가
        add_history(input);

        // "exit" 명령어를 입력하면 종료
        if (strcmp(input, "exit") == 0) {
            free(input);
            break;
        }

        printf("입력한 내용: %s\n", input);
        free(input);
    }

    return 0;
}