//
//  Postfix.c
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include "Postfix.h"
#include "Common.h"
#include "Stack.h"

struct _Postfix{    //후위식 구조체
    int _maxNumberOfTokens; //크기제한
    char* _expression;  //입력받은 후위식
    int _evaluatedValue;    //계산값
    Stack* _operandStack;   //스택객체
};

Postfix* Postfix_new(int givenNumbers){ //후위식 객체 생성
    Postfix* _this = NewObject(Postfix);    //메모리 동적할당을 이용해 객체생성
    _this->_maxNumberOfTokens = givenNumbers;   //주어진 수로 크기제한
    _this->_expression = NewVector(char, givenNumbers); //후위식의 크기를 제한
    _this->_operandStack = Stack_new(givenNumbers); //스택의 크기 제한
    return _this;
}

void Postfix_delete(Postfix* _this){    //후위식 객체 소멸
    Stack_delete(_this->_operandStack); //스택 객체 소멸
    free(_this->_expression);   //문자열에 할당된 메모리 풀어줌
    free(_this);    //후위식에 할당된 메모리 풀어줌
}

void Postfix_setExpression(Postfix* _this, char* anExpression){ //후위식 식을 설정
    strcpy(_this->_expression, anExpression);
}

int Postfix_evaluatedValue(Postfix* _this){ //계산된값을 반환
    return _this->_evaluatedValue;
}

void Postfix_showTokenAndStack(Postfix* _this, char currentToken){  //토큰과 스택 출력
    int stackElement;
    
    printf("%c : Stack <Bottom> ", currentToken);
    for(int i = 0; i < Stack_size(_this->_operandStack); i++){  //for문을통해 스택의 i 번째 요소를 반복출력
        stackElement = Stack_elementAt(_this->_operandStack, i);
        printf("%d ", stackElement);
    }
    printf("<Top>\n");
}

Boolean Postfix_evaluate(Postfix* _this){   //후위식 계산
    int operand, operand1, operand2, calculated;    //토큰과 항들을 저장할 변수
    char currentToken;
    int i = 0;
    
    Stack_reset(_this->_operandStack);  //스택을 초기화해줌
    
    while(_this->_expression[i] != '\0'){   //i번째 요소가 NULL이 아니라면 반복
        currentToken = _this->_expression[i];   //i번째 요소를 현제 토큰으로 저장
        if(currentToken >= '0' && currentToken <= '9'){ //currentToken이 정수의 범위에 있는 문자일때
            operand = (currentToken - '0');   //수치문자인 currentToken을 정수로 변환하여 operand에 저장
            Stack_push(_this->_operandStack, operand);  //정소인 currentToken을 스택에 push
        }
        else{   //currentToken이 정수의 범위에 있지 않은 문자일떄
            if(currentToken == '+'){    //+이면
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 + operand2;
                Stack_push(_this->_operandStack, calculated);   //앞 뒤 두항을 더해 스택에 푸시
            }
            else if(currentToken == '-'){   //-이면
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 - operand2;
                Stack_push(_this->_operandStack, calculated);   //앞 뒤 두 항을 빼 스택에 푸시
            }
            else if(currentToken == '*'){   //*이면
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 * operand2;
                Stack_push(_this->_operandStack, calculated);   //앞 뒤 두 항을 곱해 스택에 푸시
            }
            else if(currentToken == '/'){   // /이면
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = (operand1 / operand2);
                Stack_push(_this->_operandStack, calculated);   //앞 뒤 두 항을 나눠 스택에 푸시
            }
            else if(currentToken == '%'){   //%이면
                operand2 = Stack_pop(_this->_operandStack);
                operand1 = Stack_pop(_this->_operandStack);
                calculated = operand1 % operand2;
                Stack_push(_this->_operandStack, calculated);   //앞 뒤 두 항을 나머지 연산
            }
        }
        Postfix_showTokenAndStack(_this, currentToken); //토큰과 스택을 보이고
        i++;    //i를 1씩 늘림
    }
    _this->_evaluatedValue = Stack_pop(_this->_operandStack);   //계산된결과를 넣어줌
    return TRUE;
}
