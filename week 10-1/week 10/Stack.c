//
//  Stack.c
//  week 9
//
//  Created by stu2017s14 on 2017. 5. 2..
//  Copyright © 2017년 stu2017s14. All rights reserved.
//

#include "Stack.h"  //stack.h를 include

#define MAX_STACK_SIZE 100  //최대 크기 MAX_STACK_SIZE를 100으로 정의

struct _stack{  //Stack의 자료형
    int _top;   //int 자료형 top
    Element* _elements; //Element
};

Stack* Stack_new(){ //Stack 객체의 생성
    Stack* _this = NewObject(Stack);    //Stack에 메모리 동적 할당
    _this->_elements = NewVector(Element, MAX_STACK_SIZE);  //_this의 _elements의 메모리를 MAX_STACK_SIZE만큼 늘림
    _this->_top = -1;   //_this의 _top을 -1로 설정
    return _this;
}

void Stack_delete(Stack* _this){    //stack객체의 소멸
    free(_this->_elements); //elements에 할당된 메모리 풀어줌(소멸)
    free(_this);    //_this에 할당된 메모리 풀어줌(객체 소멸)
}

Boolean Stack_isEmpty(Stack* _this){    //스택이 비어있는지 확인하는 메소드
    return (Stack_size(_this) == 0);    //_this의 스택 사이즈가 0이면 TRUE 아니면 FALSE반환
}

Boolean Stack_isFull(Stack* _this){ //스택이 꽉 차있는지 확인하는 메소드
    return (Stack_size(_this) == MAX_STACK_SIZE);   //_this의 스택 사이즈가 MAX_STACK_SIZE이면 TRUE 아니면 FALSE반환
}

void Stack_push(Stack* _this, Element anElement){   //push메소드
    if(!Stack_isFull(_this)){   //스택이 꽉 차있지 않다면
        _this->_top ++; //top에 1을 더하고
        _this->_elements[_this->_top] = anElement;  //top번째 elements에 anElement를 넣는다
    }
}

Element Stack_pop(Stack* _this){    //pop메소드
    Element poppedElement;  //Element변수 poppedElement를 선언
    poppedElement = _this->_elements[_this->_top];  //poppedElement에 _this의 _this->_top번째 element를 저장
    _this->_top --; //top에서 1 을 뺌
    return poppedElement;   //poppedElement를 반환
}

Element Stack_topElement(Stack* _this){ //topElement를 반환하는 메소드
    return _this->_elements[_this->_top];   //_this의 _this->_top번째 element를 반환
}

Element Stack_elementAt(Stack* _this, int aPosition){   //aPosition위치의 element를 반환하는 메소드
    return _this->_elements[aPosition]; //_this의 aPosition번째 element를 반환
}

int Stack_size(Stack* _this){   //스택의 사이즈를 반환하는 메소드
    return(_this->_top+1);  //top+1 (사이즈)를 반환
}

void Stack_reset(Stack* _this){ //스택을 초기화하는 메소드
    while(!Stack_isEmpty(_this)){   //스택이 다 비어있지않으면
        Stack_pop(_this);   //팝 반복
    }
}
