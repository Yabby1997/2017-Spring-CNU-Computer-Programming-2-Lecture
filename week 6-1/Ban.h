//
//  Ban.h
//  week 6
//
//  Created by stu2017s14 on 2017. 4. 12..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#ifndef Ban_h
#define Ban_h

#include "GradeCounter.h"
#include "Common.h"

typedef struct _Ban Ban;

Ban* Ban_new(); //새로운 Ban객체를 생성하는 함수
Ban* Ban_newWithCapacity(int givenCapacity);
void Ban_delete(Ban* _this);    //만들어진 Ban객체 _this를 소멸시키는 함수

int Ban_maxSize(Ban* _this);    //최대사이즈 반환
int Ban_size(Ban* _this);   //사이즈 반환
int Ban_elementAt(Ban* _this, int anOrder); //위치에있는 요소 반환

int Ban_minScore(Ban* _this);   //최저점 반환
int Ban_maxScore(Ban* _this);   //최고점 반환
float Ban_averageScore(Ban* _this); //평균점수 반환

Boolean Ban_isEmpty(Ban* _this);    //Ban객체 _this가 비었는지 확인하는 함수
Boolean Ban_isFull(Ban* _this); //Ban객체 _this가 가득차있는지 확인하는 함수

Boolean Ban_scoreIsValid(int score);    //입력된 score가 유효한지를 확인하는 함수
char Ban_scoreToGrade(int aScore);  //점수를 학점으로바꿔 반환

Boolean Ban_add(Ban* _this, int aScore);    //Ban객체 _this에 학생을 추가하는 함수

void Ban_sortStudentsByScore(Ban* _this);   //Ban객체 _this의 학생을 점수순으로 정렬하는 함수

void Ban_quickSortRecursively(Ban* _this, int left, int right); //재귀함수로 정렬

float Ban_averageScore(Ban* _this);  //평균점수 반환
int Ban_numberOfStudentsAboveAverage(Ban* _this);   //평균이상학생

GradeCounter* Ban_countGrades(Ban* _this);

int Ban_partition(Ban* _this, int left, int right);

int Ban_maxScoreRecursively(Ban* _this, int left, int right);   //최고점 재귀함수로 찾기
int Ban_minScoreRecursively(Ban* _this, int left, int right);   //최저점 재귀함수로 찾기
int Ban_sumOfScoresRecursively(Ban* _this, int left, int right);    //재귀함수로 점수 합하기
#endif /* Ban_h */
