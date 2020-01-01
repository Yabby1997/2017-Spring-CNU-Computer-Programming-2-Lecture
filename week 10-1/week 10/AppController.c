//
//  AppController.c
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#define MAX_NUMBER_OF_TOKENS 200

#include "AppController.h"
#include "Common.h"
#include "AppIO.h"
#include "Postfix.h"

struct _AppController{  //AppController 구조체
    AppIO* _appIO;  //AppIO객체를 갖는다
    char _expression[MAX_NUMBER_OF_TOKENS]; //문자열
    Postfix* _postfix;  //후위식 객체를 갖는다
};

AppController* AppController_new(){ //AppController 객체 생성
    AppController* _this = NewObject(AppController);    //AppController메모리 동적할당
    _this->_appIO = AppIO_new();    //_appIO에 AppIO객체 생성
    _this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);    //_postfix에 Postfix객체 생성
    return _this;
}

void AppController_delete(AppController* _this){    //AppController객체 소멸
    AppIO_delete(_this->_appIO);    //_appIO제거
    Postfix_delete(_this->_postfix);    //_postfix제거
    free(_this);    //할당된 동적 메모리 풀어줌
}

void AppController_run(AppController* _this){   //AppController실행
    Boolean expressionIsAvailable, noErrorIsInEvaluation;   //식이 무결한지, 계산에 오류가없는지를 확인할 불리언변수
    
    AppIO_out_startingMessage(_this->_appIO);   //시작메시지 출력
    _this->_postfix = Postfix_new(MAX_NUMBER_OF_TOKENS);    //새 후위식 객체 생성
    expressionIsAvailable = AppIO_in_postfixExpression(_this->_appIO, _this->_expression);  //식을입력받아 무결한지 검사
    
    while(expressionIsAvailable){   //무결하다면 반복시작
        Postfix_setExpression(_this->_postfix, _this->_expression); //후위식의 식을 설정하고
        noErrorIsInEvaluation = Postfix_evaluate(_this->_postfix);  //계산을통해 오류가 없는지를 확인
        
        if(!noErrorIsInEvaluation){ //오류가 있다면
            AppIO_out_errorInExpression(_this->_appIO); //오류가있음을 출력
        }
        else{   //오류가 없다면
            AppIO_out_evaluatedValue(_this->_appIO, Postfix_evaluatedValue(_this->_postfix));   //계산된 값을 출력
        }
        expressionIsAvailable = AppIO_in_postfixExpression(_this->_appIO, _this->_expression);  //다시 식을입력받아 무결한지 검사하며 반복
    }
    Postfix_delete(_this->_postfix);    //후위식 객체를 삭제
    AppIO_out_endingMessage(_this->_appIO); //종결메시지 출력
}
