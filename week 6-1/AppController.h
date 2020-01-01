//
//  AppController.h
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

#include "Common.h"
#include "AppIO.h"
#include "Ban.h"

typedef struct _AppController AppController;

#define MAX_NUMBER_OF_STUDENTS 100  //최대 학생수 매크로 설정

AppController* AppController_new(); //새로운 AppController객체를 생성하는 함수
void AppController_delete(AppController* _this);    //만들어진 AppController객체 _this를 소멸시키는 함수
void AppController_run(AppController* _this);   //만들어진 AppController객체 _this를 실행시키는 함수. 실질적 main

Boolean AppController_inputAndStoreStudents(AppController* _this);  //학생정보가 잘 입력되어 저장되었는가
void AppController_showStatistics(AppController* _this);    //통계출력
void AppController_showStudentsSortedByScore(AppController* _this); //점수순으로 정렬해 출력
#endif /* AppController_h */
