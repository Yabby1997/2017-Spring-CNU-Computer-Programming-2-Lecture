//
//  AppController.c
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include "AppController.h"

//AppController의 구조체
struct _AppController{
    AppIO* _appIO;
    Ban* _ban;
};

//AppController의 생성과 실행, 제거
AppController* AppController_new(){ //AppController를 생성하는 함수
    AppController* _this = NewObject(AppController);    //AppController인 _this를 위해 동적 메모리를 할당
    _this->_appIO = AppIO_new();    //AppController의 구조체에 들어가는 AppIO인 _appIO는 새로운 AppIO객체를 생성하는 함수 호출
    _this->_ban = Ban_newWithCapacity(MAX_NUMBER_OF_STUDENTS);  //AppController구조체에 들어가는 Ban인 _ban은 새로운 Ban객체를 생성하는 함수 호출
    return _this;   //생성된 AppController객체, _this를 반환
}

void AppController_delete(AppController* _this){    //AppController를 소멸시키는 함수
    AppIO_delete(_this->_appIO);    //_this와 함께 생성된 AppIO객체 _appIO를 제거하는 함수 호출
    Ban_delete(_this->_ban);    //_this와 함께 생성된 Ban객체 _ban을 제거하는 함수 호출
    free(_this);    //_this를 위해 할당된 동적 메모리를해방
}

void AppController_run(AppController* _this){
    
    AppIO_out_msg_startScoreProcessing(_this->_appIO);  //성적 처리가 시작되었음을 알린다.
    
    Boolean inputAndStoreWasSuccesful;  //Boolean 변수 inputAndStoreWasSuccesful을 선언
    inputAndStoreWasSuccesful = AppController_inputAndStoreStudents(_this); //inputAndStoreWasSuccesful에는 AppController_inputAndStoreStudents의 반환되는 값(입력과 저장에 성공했는지)이 저장된다
    
    if(inputAndStoreWasSuccesful){  //입력과 그 값의 저장에 성공했다면
        if(Ban_isEmpty(_this->_ban)){   //만약 반이 비어있다면
            AppIO_out_msg_noStudentFromInput(_this->_appIO);    //입력으로부터 얻어낸 학생이 없다는 메시지를 출력한다
        }
        else{   //그게 아니라면
            AppController_showStatistics(_this);    //통계를 보이고
            Ban_sortStudentsByScore(_this->_ban);   //학생들을 점수순으로 정렬하고
            AppController_showStudentsSortedByScore(_this); //점수에의해 정렬된 학생들을 보인다
        }
    }
    else{   //입력이나 그 값의 저장에 실패했다면
        AppIO_out_msg_errorInInputStudentInfo(_this->_appIO);   //에러 메시지를 출력한다
    }
    AppIO_out_msg_endScoreProcessing(_this->_appIO);    //성적 처리가 종료되었음을 알린다
}

//AppController의 함수를 구현하는 부분
Boolean AppController_inputAndStoreStudents(AppController* _this){
    int score;
    Boolean storingAStudentWasSuccesful = TRUE;
    
    while(storingAStudentWasSuccesful && AppIO_in_doesContinueToInputNextStudent(_this->_appIO)){   //둘다 참일때
        score = AppIO_in_score(_this->_appIO);  //AppIO_in_score를 통해 입력받은 정수를 score변수에 담는다
        if(Ban_scoreIsValid(score)){    //Ban_scoreIsValid를 통해 score가 유효함을 확인한다면
            storingAStudentWasSuccesful = Ban_add(_this->_ban, score); //Ban_add를 통해 학생을 추가하고? Boolean을 반환 이때 반환되는거로 반복이 되냐 멈추냐가 결정
        }
        else{
            AppIO_out_msg_invalidScore(_this->_appIO, score);   //score가 유효하지 않다면
        }
    }
    return storingAStudentWasSuccesful; //Boolean자료형의 storingAStudentWasSuccesful을 반환한다
}

void AppController_showStatistics(AppController* _this){    //통계를 보이는 함수
    AppIO_out_averageScore(_this->_appIO, Ban_averageScore(_this->_ban));
    AppIO_out_numberOfStudentsAboveAverage(_this->_appIO, Ban_numberOfStudentsAboveAverage(_this->_ban));
    AppIO_out_maxScore(_this->_appIO, Ban_maxScore(_this->_ban));   //최고점 출력
    AppIO_out_minScore(_this->_appIO, Ban_minScore(_this->_ban));   //최저점 출력
    
    GradeCounter* gradeCounter = Ban_countGrades(_this->_ban);
    AppIO_out_gradeCountFor(_this->_appIO, 'A', GradeCounter_numberOfA(gradeCounter));  //A인 학생수 출력
    AppIO_out_gradeCountFor(_this->_appIO, 'B', GradeCounter_numberOfB(gradeCounter));  //B인 학생수 출력
    AppIO_out_gradeCountFor(_this->_appIO, 'C', GradeCounter_numberOfC(gradeCounter));  //C인 학생수 출력
    AppIO_out_gradeCountFor(_this->_appIO, 'D', GradeCounter_numberOfD(gradeCounter));  //D인 학생수 출력
    AppIO_out_gradeCountFor(_this->_appIO, 'F', GradeCounter_numberOfF(gradeCounter));  //F인 학생수 출력
    GradeCounter_delete(gradeCounter);
}

void AppController_showStudentsSortedByScore(AppController* _this){ //점수순으로 출력
    AppIO_out_titleForSortedStudentList(_this->_appIO); //메시지 출력
    int score;
    char grade;
    
    for(int order = 0; order < Ban_size(_this->_ban); order++){ //반복
        score = Ban_elementAt(_this->_ban, order);
        grade = Ban_scoreToGrade(score);    //점수를 학점으로 변환
        AppIO_out_studentInfo(_this->_appIO, score, grade); //정보 출력
    }
}
