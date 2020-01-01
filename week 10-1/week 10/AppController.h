//
//  AppController.h
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef AppController_h
#define AppController_h

typedef struct _AppController AppController;    //AppController구조체

AppController* AppController_new(); //AppController객체 생성
void AppController_delete(AppController* _this);    //AppController객체 소멸
void AppController_run();   //AppController객체 실행

#endif /* AppController_h */
