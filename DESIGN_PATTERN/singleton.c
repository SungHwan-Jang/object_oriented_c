#include "compile_option.h"
#include <stdio.h>

// 싱글톤 인스턴스를 저장할 구조체
typedef struct {
    // 여기에 싱글톤 데이터를 저장할 변수들을 추가할 수 있습니다.
    int data;
} singleton_t;

// 싱글톤 인스턴스를 담을 전역 변수
static singleton_t instance;

// 싱글톤 인스턴스를 얻는 함수
singleton_t* get_singleton_instance(void) {
    return &instance;
}

#if SINGLETON_EXAMPLE
int main(void) {
    // 싱글톤 인스턴스 얻기
    singleton_t* singleton = get_singleton_instance();
    
    // 데이터 설정
    singleton->data = 42;
    
    // 데이터 출력
    (void) printf("Singleton 데이터: %d\n", singleton->data);
    
    return 0;
}
#endif