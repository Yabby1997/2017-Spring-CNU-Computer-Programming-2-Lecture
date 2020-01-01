//
//  main.c
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include "AppController.h"  //main에서는 AppController를 이용

int main(void){
    AppController* appController = AppController_new(); //AppController객체 생성
    AppController_run(appController);   //AppController 실행
    AppController_delete(appController);    //AppController 제거
    return 0;
}
