//
//  AppIO.c
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include "AppIO.h"
#include <unistd.h>
#include <termios.h>

struct _AppIO{  //AppIO의 구조체, 객체처럼 사용
    
};

AppIO* AppIO_new(){ //AppIO생성자
    AppIO* _this = NewObject(AppIO);
    return _this;
}

void AppIO_delete(AppIO* _this){    //AppIO소멸
    free(_this);
}

Boolean AppIO_in_doesContinueToInputNextStudent(AppIO* _this){  //학생 정보를 입력받을것인지 여부확인
    printf("? 성적을 입력하려면 'Y'를, 입력을 종료하려면 다른 아무키나 치시오:");
    char answer = getcharDirectlyFromKeyboard();
    return (answer == 'y' || answer == 'Y');
}

int AppIO_in_score(AppIO* _this){   //점수를 입력받음
    int score;
    printf("\n점수를 입력하시오:");
    scanf("%d", &score);
    return score;
}

void AppIO_out_msg_startScoreProcessing(AppIO* _this){  //성적처리 시작 메시지출력
    printf("<<< 성적 처리를 시작합니다 >>>\n");
}

void AppIO_out_msg_endScoreProcessing(AppIO* _this){    //프로그램 종료 메시지출력
    printf(">>> 프로그램을 종료합니다 <<<\n");
}

void AppIO_out_msg_noStudentFromInput(AppIO* _this){    //입력정보가 없을때 메시지출력
    printf("\n입력을 종료합니다.\n");
}

void AppIO_out_msg_errorInInputStudentInfo(AppIO* _this){   //입력받은 점수정보에 없을때 메시지출력
    printf("\n[오류] 학생 정보가 전혀 입력되지 않았습니다.\n");
}

void AppIO_out_msg_invalidScore(AppIO* _this, int aScore){  //무효한 점수가 입력되었을때 메시지출력
    printf("[오류] 0보다 작거나 100보다 커서, 정상적인 점수가 아닙니다.\n");
}

void AppIO_out_averageScore(AppIO* _this, int anAverageScore){  //평균점수 메시지출력
    printf("\n\n평균점수는 %d 입니다\n", anAverageScore);
}

void AppIO_out_numberOfStudentsAboveAverage(AppIO* _this, int aNumber){ //평균이상 학생 메시지출력
    printf("평균 이상인 학생은 모두 %d명 입니다.\n",aNumber);
}

void AppIO_out_maxScore(AppIO* _this, int aMaxScore){   //최대점수 메시지출력
    printf("최고점은 %d 점 입니다.\n",aMaxScore);
}

void AppIO_out_minScore(AppIO* _this, int aMinScore){   //최소점수 메시지출력
    printf("최저점은 %d 점 입니다.\n\n",aMinScore);
}

void AppIO_out_gradeCountFor(AppIO* _this, char aGrade, int aCount){    //해당학점 학생이 몇명인지 메시지출력
    printf("%c 학점은 %d명 입니다.\n",aGrade,aCount);
}

void AppIO_out_titleForSortedStudentList(AppIO* _this){ //성적순 목록 메시지출력
    printf("\n학생들의 성적순 목록입니다.\n");
}

void AppIO_out_studentInfo(AppIO* _this, int aScore, char aGrade){  //학생 정보 메시지출력
    printf("점수 : %d  ",aScore);
    printf("학점 : %c\n",aGrade);
}

char getcharDirectlyFromKeyboard(void){ //키보드로부터 입력받기위한 메소드
    struct termios oldAttr;
    struct termios newAttr;
    
    char charFromKeyboard;
    fpurge(stdin);
    tcgetattr(STDIN_FILENO, &oldAttr);
    newAttr = oldAttr;
    newAttr.c_lflag &= ~(ICANON | ECHO); tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);
    charFromKeyboard = getchar();
    return charFromKeyboard;
}
