//
//  AppIO.c
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include <stdio.h>  //출력헤더
#include "AppIO.h"
#include "Common.h"

struct _AppIO{  //AppIO구조체
    
};

AppIO* AppIO_new(){ //AppIO객체 생성
    AppIO* _this = NewObject(AppIO);    //메모리 동적할당을 통해 객체 생성
    return _this;
}

void AppIO_delete(AppIO* _this){    //AppIO객체 소멸
    free(_this);    //동적할당된 메모리를 풀어줌
}

Boolean AppIO_in_postfixExpression(AppIO* _this, char* expression){ //후위식 입력
    printf(">Postfix 수식을 입력하시오 ");  //입력메시지 출력
    scanf("%s", expression);    //입력되는 문자열받음
    return (expression[0] != '$');  //$가들어오면 FAlSE 아니면 TRUE반환
}

void AppIO_out_startingMessage(AppIO* _this){   //시작메시지출력
    printf("<Postfix 수식을 계산합니다>\n\n");
}

void AppIO_out_endingMessage(AppIO* _this){ //종결메시지출력
    printf("<계산을 종료합니다>\n");
}

void AppIO_out_errorInExpression(AppIO* _this){ //식에 오류가있음을 출력
    printf(">수식에 오류가 있습니다.\n");
}

void AppIO_out_evaluatedValue(AppIO* _this, int evaluatedValue){    //계산된 값을 출력
    printf("계산값 : %d\n\n", evaluatedValue);
}
