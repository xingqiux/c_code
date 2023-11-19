#include <stdio.h>

static void test_printf(){
    printf("你好,测试\n");
}

void test(){
    for (int i = 0; i < 5; i++){
        test_printf();
    }
}
