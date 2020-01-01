//
//  Ban.c
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include "Ban.h"

#define DEFAULT_CAPACITY 100

struct _Ban{    //Ban 구조체, 객체처럼 이용
    int _maxSize;
    int _size;
    int _elements[DEFAULT_CAPACITY];    //100만큼의 배열을가짐
};

Ban* Ban_new(){ //Ban생성
    Ban* _this = NewObject(Ban);    //동적할당
    _this->_maxSize = DEFAULT_CAPACITY; //맥스사이즈를 100
    _this->_size = 0;   //현제사이즈는 0
    return _this;
}

Ban* Ban_newWithCapacity(int givenCapacity){    //Ban 생성
    Ban* _this = NewObject(Ban);    //동적할당
    _this->_maxSize = givenCapacity;    //맥스사이즈를 파라메터값으로
    _this->_size = 0;   //현제사이즈는 0
    return _this;
}

void Ban_delete(Ban* _this){    //객체의 소멸
    free(_this);
}

Boolean Ban_isEmpty(Ban* _this){    //Ban이 비었는지 확인
    return(_this->_size == 0);
}

Boolean Ban_isFull(Ban* _this){ //Ban이 꽉 찼는지 확인
    return(_this->_size == _this->_maxSize);
}

Boolean Ban_scoreIsValid(int aScore){   //클래스메소드    점수가 올바른지 확인
    return(aScore >= 0 && aScore <= 100);
}

char Ban_scoreToGrade(int aScore){      //클래스메소드    점수를 학점으로 변환
    if(aScore >= 90){
        return 'A';
    }
    
    else if(aScore >= 80){
        return 'B';
    }
    
    else if(aScore >= 70){
        return 'C';
    }
    
    else if(aScore >= 60){
        return 'D';
    }
    
    else{
        return 'F';
    }
}

int Ban_maxSize(Ban* _this){    //맥스사이즈 반환
    return(_this->_maxSize);
}

int Ban_size(Ban* _this){   //사이즈 반환
    return(_this->_size);
}

void Ban_sortStudnetsByScore(Ban* _this){   //학생을 점수순으로 정렬
    int size = _this->_size;
    
    if(size >= 2){
        int minPosition = 0;
        for(int i = 1; i < size; i++){
            if(_this->_elements[i] < _this->_elements[minPosition]){
                minPosition = i;
            }
        }
        SWAP(int, _this->_elements[minPosition], _this->_elements[size-1]);
        Ban_quickSortRecursively(_this, 0, size-2);
    }
}

void Ban_quickSortRecursively(Ban* _this, int left, int right){ //재귀함수로 정렬
    if(left < right){
        int mid = Ban_partition(_this, left, right);
        Ban_quickSortRecursively(_this, left, mid-1);
        Ban_quickSortRecursively(_this, mid+1, right);
    }
}

int Ban_partition(Ban* _this, int left, int right){
    int pivot = left;
    int pivotScore = _this->_elements[pivot];
    
    right++;
    
    do{
        do{ left++; } while(_this->_elements[left] > pivotScore);
        do{ right--; } while(_this->_elements[right] < pivotScore);
        
        if(left < right){
            SWAP(int, _this->_elements[left], _this->_elements[right]);
        }
    }
    while(left < right);
    SWAP(int, _this->_elements[pivot], _this->_elements[right]);
    return right;
}

float Ban_averageScore(Ban* _this){ //평균점수 반환
    float sumOfScores = (float)Ban_sumOfScoresRecursively(_this, 0, _this->_size-1);
    float average = sumOfScores/(float)_this->_size;
    return average;
}

int Ban_maxScore(Ban* _this){   //재귀함수를 이용해 최고점 반환
    return Ban_maxScoreRecursively(_this, 0, _this->_size-1);
}

int Ban_minScore(Ban* _this){   //재귀함수를 이용해 최저점 반환
    return Ban_minScoreRecursively(_this, 0, _this->_size-1);
}

int Ban_sumOfScoresRecursively(Ban* _this, int left, int right){    //재귀함수를 이용해 점수들의 합을 반환
    if(left > right){
        return 0;
    }
    else{
        return (_this->_elements[left] + Ban_sumOfScoresRecursively(_this, left+1, right));
    }
}

int Ban_maxScoreRecursively(Ban* _this, int left, int right){   //최고점을 재귀함수로 찾음
    int maxOfLeftPart;
    int maxOfRightPart;
    int mid;
    
    if(left == right){
        return _this->_elements[left];
    }
    else{
        mid = (left + right) / 2;
        maxOfLeftPart = Ban_maxScoreRecursively(_this, left, mid);
        maxOfRightPart = Ban_maxScoreRecursively(_this, mid+1, right);
        
        if(maxOfLeftPart >= maxOfRightPart){
            return maxOfLeftPart;
        }
        else{
            return maxOfRightPart;
        }
    }
}

int Ban_minScoreRecursively(Ban* _this, int left, int right){   //최저점을 재귀함수로 찾음
    int minOfLeftPart;
    int minOfRightPart;
    int mid;
    
    if(left == right){
        return _this->_elements[left];
    }
    else{
        mid = (left + right) / 2;
        minOfLeftPart = Ban_minScoreRecursively(_this, left, mid);
        minOfRightPart = Ban_minScoreRecursively(_this, mid+1, right);
        
        if(minOfLeftPart <= minOfRightPart){
            return minOfLeftPart;
        }
        else{
            return minOfRightPart;
        }
    }
}

Boolean Ban_add(Ban* _this, int aScore){    //점수를 추가
    if(Ban_isFull(_this)){
        return FALSE;
    }
    else{
        _this->_elements[_this->_size] = aScore;
        _this->_size++;
        return TRUE;
    }
}

void Ban_sortStudentsByScore(Ban* _this){   //점수순으로 학생정렬
    int size = _this->_size;
    
    if(size>=2){
        int minPosition = 0;
        for(int i = 1; i<size; i++){
            if(_this->_elements[i] < _this->_elements[minPosition]){
                minPosition = i;
            }
        }
        SWAP(int,_this->_elements[minPosition],_this->_elements[size-1]);
        
        Ban_quickSortRecursively(_this,0,size-2);
    }
}

int Ban_elementAt(Ban* _this, int anOrder){ //위치에있는 요소 반환
    if(anOrder >= _this->_size){
        return -1;
    }
    else{
        return (_this->_elements[anOrder]);
    }
}

int Ban_numberOfStudentsAboveAverage(Ban* _this){   //평균 이상 학생 출력
    float average = Ban_averageScore(_this);
    int numberOfStudentsAboveAverage = 0;
    
    for(int i = 0; i < _this->_size; i++){
        if((float)_this->_elements[i] >= average){
            numberOfStudentsAboveAverage++;
        }
    }
    return numberOfStudentsAboveAverage;
}

GradeCounter* Ban_countGrades(Ban* _this){
    char currentGrade;
    GradeCounter* gradeCounter = GradeCounter_new();//gradeCounter객체 생성
    
    for(int i=0; i<_this->_size; i++){//학생 수만큼 반복
        currentGrade = Ban_scoreToGrade(_this->_elements[i]);
        GradeCounter_count(gradeCounter, currentGrade);//학점 별 학생 수를 셈
    }
    return gradeCounter;//학점별 학생 수 리턴
}
