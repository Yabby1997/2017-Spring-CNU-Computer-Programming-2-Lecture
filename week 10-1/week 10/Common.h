
//
//  Common.h
//  week 10
//
//  Created by stu2017s14 on 2017. 5. 16..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <stdlib.h> //메모리 동적할당에 필요

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE)) //메모리 동적할당 전처리
#define NewVector(TYPE, SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)  //할당된 메모리의 크기를 바꿔주도록 전처리

typedef enum{FALSE, TRUE} Boolean;  //불리언 자료형 선언

#endif /* Common_h */
