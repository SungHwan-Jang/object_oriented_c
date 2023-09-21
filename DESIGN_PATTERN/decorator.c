//
// Created by redmk on 2023-09-21.
//
#include "compile_option.h"
#include <stdio.h>
#include <stdlib.h>

// 커피 객체의 인터페이스
typedef struct {
    void (*brew)(void);
} Coffee;

// 원래 커피 구현
typedef struct {
    Coffee base; // 커피 객체의 기본 인터페이스를 가지고 있어야 합니다.
} SimpleCoffee;

void brewSimpleCoffee(void) {
    printf("단순한 커피를 내립니다.\n");
}

void makeSimpleCoffee(SimpleCoffee* coffee) {
    coffee->base.brew = brewSimpleCoffee;
}

// 커피 토핑 데코레이터
typedef struct {
    Coffee base; // 커피 객체의 기본 인터페이스를 가지고 있어야 합니다.
    Coffee* wrappedCoffee; // 데코레이터가 래핑하는 커피 객체
    void (*brew)(void); // 데코레이터가 추가하는 기능
} CoffeeDecorator;

void brewWithTopping(void) {
    printf("토핑을 추가한 커피를 내립니다.\n");
}

void makeCoffeeWithTopping(CoffeeDecorator* coffee, Coffee* wrappedCoffee) {
    coffee->base.brew = brewWithTopping;
    coffee->wrappedCoffee = wrappedCoffee;
}

#if DECORATOR_EXAMPLE

int main() {
    SimpleCoffee simpleCoffee;
    makeSimpleCoffee(&simpleCoffee);
    
    CoffeeDecorator coffeeWithTopping;
    makeCoffeeWithTopping(&coffeeWithTopping, (Coffee*)&simpleCoffee);
    
    // 기본 커피 내리기
    simpleCoffee.base.brew();
    
    // 토핑 추가한 커피 내리기
    coffeeWithTopping.base.brew();
    
    return 0;
}
#endif