//
//  GradeCounter.c
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 15..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include "GradeCounter.h"

struct _GradeCounter{   //GradeCounter의 구조체. 객체처럼 이용
    int _numberOfA;
    int _numberOfB;
    int _numberOfC;
    int _numberOfD;
    int _numberOfF;
};

GradeCounter* GradeCounter_new(){   //생성
    GradeCounter* _this = NewObject(GradeCounter);
    
    _this->_numberOfA = 0;
    _this->_numberOfB = 0;
    _this->_numberOfC = 0;
    _this->_numberOfD = 0;
    _this->_numberOfF = 0;
    
    return _this;
}

void GradeCounter_delete(GradeCounter* _this){  //소멸
    free(_this);
}

void GradeCounter_count(GradeCounter* _this, char aGrade){  //학점 수 세는메소드
    switch(aGrade){
        case 'A':
            _this->_numberOfA++;
            break;
        case 'B':
            _this->_numberOfB++;
            break;
        case 'C':
            _this->_numberOfC++;
            break;
        case 'D':
            _this->_numberOfD++;
            break;
        case 'F':
            _this->_numberOfF++;
            break;
    }
}

int GradeCounter_numberOfA(GradeCounter* _this){    //A의 학생 수를 반환
    return _this->_numberOfA;
}

int GradeCounter_numberOfB(GradeCounter* _this){    //B의 학생 수 반환
    return _this->_numberOfB;
}

int GradeCounter_numberOfC(GradeCounter* _this){    //C의 학생 수 반환
    return _this->_numberOfC;
}

int GradeCounter_numberOfD(GradeCounter* _this){    //D의 학생 수 반환
    return _this->_numberOfD;
}

int GradeCounter_numberOfF(GradeCounter* _this){    //F의 학생 수 반환
    return _this->_numberOfF;
}
