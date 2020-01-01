//
//  Postfix.h
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef Postfix_h
#define Postfix_h

#include "Common.h"

typedef struct _Postfix Postfix;    //후위식 구조체

Postfix* Postfix_new(int givenMaxNumberOfTokens);   //후위식 객체 생성
void Postfix_delete();  //후위식 객체 소멸

void Postfix_setExpression(Postfix* _this, char* anExpression); //후위식 식 설정
Boolean Postfix_evaluate(Postfix* _this);   //후위식 계산
int Postfix_evaluatedValue(Postfix* _this); //후위식 계산값

#endif /* Postfix_h */
