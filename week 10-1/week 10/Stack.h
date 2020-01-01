//
//  Stack.h
//  week 9
//
//  Created by stu2017s14 on 2017. 5. 2..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef Stack_h
#define Stack_h

#include "Common.h" //Common.h를 include

typedef struct _stack Stack;    //Stack 자료형
typedef char Element;   //char를 Element로 선언

Stack* Stack_new(); //Stack객체 생성
void Stack_delete(Stack* _this);    //Stack객체 소멸

Boolean Stack_isFull(Stack* _this); //스택이 꽉 차있는지 판별
Boolean Stack_isEmpty(Stack* _this);    //스택이 비어있는지 판별

int Stack_size(Stack* _this);   //스택의 사이즈 반환
void Stack_push(Stack* _this, Element anElement);   //push
Element Stack_pop(Stack* _this);    //pop
Element Stack_elementAt(Stack* _this, int aPosition);   //aPosition번째 요소 반환
Element Stack_topElement(Stack* _this); //맨 위의 요소 반환

void Stack_reset(Stack* _this); //스택을 초기

#endif /* Stack_h */
