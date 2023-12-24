#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX_LEN 100
#define MAX_LINES 100

struct music {
    char name[10];
    double Hz;
    int time;
};

int main() {
    struct music notes[] = {
        {"C", 1046.502, 0},
        {"D", 1174.659, 0},
        {"E", 1318.510, 0},
        {"F", 1396.913, 0},
        {"G", 1567.982, 0},
        {"A", 1760.000, 0},
        {"B", 1975.533, 0}
    };

    int line = 0;
    FILE *pFile;

    printf("[1]새 곡 만들기\n[2]곡 추가하기\n");
    int q;
    scanf("%d", &q);

    if (q == 1) {
        pFile = fopen("include.txt", "w");
    } else if (q == 2) {
        pFile = fopen("include.txt", "a");
    }

    while (1) {
        printf("연주하고 싶은 음을 입력해주세요! (C,D,E,F,G,A,B)\n다 입력하셨다면 'play'를 입력해주세요!\n");
        char input[MAX_LEN];
        scanf("%s", input);
        if (strcmp(input, "play") == 0) {
            break;
        }
        printf("연주할 시간(0~4000)을 입력해주세요!\n");
        int time;
        scanf("%d", &time);

        int i;
        for (i = 0; i < 7; i++) {
            if (strcmp(input, notes[i].name) == 0) {
                fprintf(pFile, "%s %d\n", input, time);
                break;
            }
        }
        if (i == 7) {
            printf("올바른 음을 입력해주세요!\n");
        }
    }
    fclose(pFile);

    pFile = fopen("include.txt", "r");
    int i;
    for (i = 0; fscanf(pFile, "%s %d", notes[i].name, &notes[i].time) != EOF; i++) {
        // 파일에서 음계와 시간을 읽어옴
    }
    line = i; // 읽어온 라인 수 저장
    fclose(pFile);

    printf("노래를 재생하겠습니다\n");
    Sleep(100);
    for (i = 0; i < line; i++) {
        int j;
        for (j = 0; j < 7; j++) {
            if (strcmp(notes[i].name, notes[j].name) == 0) {
                Beep((DWORD)notes[j].Hz, (DWORD)notes[i].time);
                break;
            }
        }
        Sleep(100); // 각 음계 재생 후 정해진 시간만큼 기다림
    }

    return 0;
}
