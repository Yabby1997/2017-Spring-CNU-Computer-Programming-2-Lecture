//
//  GradeCounter.h
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 15..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef GradeCounter_h
#define GradeCounter_h

#include "Common.h"

typedef struct _GradeCounter GradeCounter;

GradeCounter* GradeCounter_new(void);   //생성자
void GradeCounter_delete(GradeCounter* _this);  //소멸자
void GradeCounter_count(GradeCounter* _this, char aGrade);  //학점별 학생수 셈

int GradeCounter_numberOfA(GradeCounter* _this);    //A학생수 반환
int GradeCounter_numberOfB(GradeCounter* _this);    //B학생수 반환
int GradeCounter_numberOfC(GradeCounter* _this);    //C학생수 반환
int GradeCounter_numberOfD(GradeCounter* _this);    //D학생수 반환
int GradeCounter_numberOfF(GradeCounter* _this);    //F학생수 반환

#endif /* GradeCounter_h */
