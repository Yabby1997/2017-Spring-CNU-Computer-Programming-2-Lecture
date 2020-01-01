//
//  AppIO.h
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef AppIO_h
#define AppIO_h

#include "Common.h"

typedef struct _AppIO AppIO;    //AppIO구조체

AppIO* AppIO_new(); //AppIO객체 생성
void AppIO_delete();    //AppIO객체 소멸

Boolean AppIO_in_postfixExpression(AppIO* _this, char* expression); //후위식 식 입력받음
void AppIO_out_startingMessage(AppIO* _this);   //시작메시지 출력
void AppIO_out_endingMessage(AppIO* _this); //종결메시지 출력
void AppIO_out_errorInExpression(AppIO* _this); //식에 오류a있음을 출력
void AppIO_out_evaluatedValue(AppIO* _this, int evaluatedValue);    //계산된 결과값 출력

#endif /* AppIO_h */
