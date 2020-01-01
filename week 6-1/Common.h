//
//  Common.h
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef Common_h
#define Common_h

#include <stdlib.h>

#define NewObject(TYPE) (TYPE*)malloc(sizeof(TYPE)) //동적할당을 위한 매크로
#define NewVector(TYPE,SIZE) (TYPE*)malloc(sizeof(TYPE)*SIZE)
#define SWAP(TYPE, X, Y) {TYPE temp = X; X=Y; Y=temp;}  //temp를 만들어 바꾸는 매크로

typedef enum {FALSE, TRUE}  Boolean;    //다른 클래스들에서 사용할 자료형인 Boolean을 만들어준다.

#endif /* Common_h */
