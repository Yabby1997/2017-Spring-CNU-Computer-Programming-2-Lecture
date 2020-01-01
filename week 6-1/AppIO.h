//
//  AppIO.h
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include <stdio.h>
#include "Common.h"

typedef struct _AppIO AppIO;

AppIO* AppIO_new(); //새로운 AppIO객체를 생성하는 함수
void AppIO_delete(AppIO* _this);    //만들어진 AppIO객체 _this를 소멸시키는 함수

void AppIO_out_msg_startScoreProcessing(AppIO* _this);  //점수가공이 시작되었음을 알리는 함수
void AppIO_out_msg_endScoreProcessing(AppIO* _this);    //점수가공이 종료되었음을 알리는 함수
void AppIO_out_msg_noStudentFromInput(AppIO* _this);    //AppIO객체 _this로의 입력으로부터 학생 정보를 얻어내지 못했음을 알리는 함수
void AppIO_out_msg_errorInInputStudentInfo(AppIO* _this);   //AppIO객체 _this로의 입력으로 얻어낸 학생 정보에 오류가 있음을 알리는 함수
void AppIO_out_msg_invalidScore(AppIO* _this, int score);   //점수가 유효하지 않음을 알리는 함수
void AppIO_out_titleForSortedStudentList(AppIO* _this); //성적순 메시지출력

Boolean AppIO_in_doesContinueToInputNextStudent(AppIO* _this);  //학생정보 입력받을 여부 확인
int AppIO_in_score(AppIO* _this);   //점수를 입력받는 함수

void AppIO_out_averageScore(AppIO* _this, int anAverageScore);  //평균점수 메시지출력
void AppIO_out_numberOfStudentsAboveAverage(AppIO* _this, int aNumber); //평균이상 학생 메시지출력
void AppIO_out_maxScore(AppIO* _this, int aMaxScore);   //최고점 메시지출력
void AppIO_out_minScore(AppIO* _this, int aMinScore);   //최소점 메시지출력
void AppIO_out_gradeCountFor(AppIO* _this, char aGrade, int aCount);    //해당 학점의 학생이 몇명인지 메시지출력
void AppIO_out_studentInfo(AppIO* _this, int aScore, char aGrade);  //학생정보 메시지출력
char getcharDirectlyFromKeyboard(); //키보드로부터 곧바로 입력을 받는 메소드

#endif /* AppIO_h */
