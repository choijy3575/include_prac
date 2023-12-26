#include <stdio.h>
#include <windows.h>
#include <string.h>
#define MAX_LEN 100
#define MAX_LINES 100

// 음을 위한 구조체 정의
struct music {
    char name[10];
    double Hz;
    int time;
};

int main() {
    
    // 음을 담을 구조체 배열
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
    
// 파일 오픈 형식을 입력받음(덮어 쓰기/ 이어쓰기)
    printf("[1]새 곡 만들기\n[2]곡 추가하기\n");
    int q;
    scanf("%d", &q);

    if (q == 1) {
        pFile = fopen("include.txt", "w");
    } else if (q == 2) {
        pFile = fopen("include.txt", "a");
    }
    
// 음과 연주시간을 입력받는 반복문
    while (1) {
        
        // 음을 입력받고 저장
        printf("연주하고 싶은 음을 입력해주세요! (C,D,E,F,G,A,B)\n다 입력하셨다면 'play'를 입력해주세요!\n");
        char input[MAX_LEN];
        scanf("%s", input);
        // play 입력시 반복문 탈출
        if (strcmp(input, "play") == 0) {
            break;
        }
        
        // 연주시간 입력받고 저장
        printf("연주할 시간(0~4000)을 입력해주세요!\n");
        int time;
        scanf("%d", &time);
        
        // 입력받은 음을 구조체에서 정의된 음표와 비교해서 txt파일에 기록
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
    
    // 입력이 끝나면 파일 닫기
     fclose(pFile);
    
// 파일을 읽기 형식으로 다시 열고 파일 끝까지 음과 재생 시간을 읽음
    pFile = fopen("include.txt", "r");
    int i;
    for (i = 0; fscanf(pFile, "%s %d", notes[i].name, &notes[i].time) != EOF; i++) {
        
    }
    line = i; 
    fclose(pFile);

    printf("노래를 재생하겠습니다\n");
    Sleep(100);
    
    //파일에서 읽은 음을 구조체에 정의된 음과 비교하여 주파수 형태로 변환
    for (i = 0; i < line; i++) {
        int j;
        for (j = 0; j < 7; j++) {
            // Beep 함수를 통해 음을 재생 시간동안 연주
            if (strcmp(notes[i].name, notes[j].name) == 0) {
                Beep((DWORD)notes[j].Hz, (DWORD)notes[i].time);
                break;
            }
        }
        
        // 음간 딜레이
        Sleep(100); 
    }

    return 0;
}
