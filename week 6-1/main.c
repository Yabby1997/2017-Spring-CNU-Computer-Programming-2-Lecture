//
//  main.c
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include "AppController.h"

int main(int argc, const char * argv[]){
    AppController* appController = AppController_new(); //main의 역할을 하는 부분을 AppController로 옮겼기에 그를 통해 프로그램 실행
    AppController_run(appController);   //생성, 실행, 소멸
    AppController_delete(appController);
    
    return 0;
}
