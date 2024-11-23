#include <stdio.h>
#include <stdlib.h>  // 用于 malloc 和 free 函数

int* copy(int* source, int start, int end) {
    int* target = (int*)malloc((end - start) * sizeof(int));  // 动态分配目标数组
    if (target == NULL) {
        printf("Memory allocation failed!\n");
        return NULL;  // 内存分配失败时返回 NULL
    }

    int index = 0;
    for (int i = start; i < end; i++) {
        target[index++] = source[i];  // 复制元素˜
    }
    return target;  // 返回新数组
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);  // 打印数组元素
    }
    printf("\n");
}

int main(int argc, char const* argv[]) {
    int source[] = {1, 2, 3, 4, 5, 6, 7};           // 初始化源数组
    int size = sizeof(source) / sizeof(source[0]);  // 计算数组大小
    print_array(source, size);                      // 打印源数组

    int* target = copy(source, 2, 6);  // 复制区间 [2, 6)
    if (target != NULL) {
        print_array(target, 4);  // 打印目标数组
        free(target);            // 释放动态分配的内存
    }

    printf("--------------\n");

    int* origin = (int*)malloc(7 * sizeof(int));
    for (int i = 0; i < 7; i++) {
        origin[i] = i;
    }
    int length = 3;
    print_array(origin, 7);

    int* last = &origin[2];
    print_array(last, length);

    origin = NULL;
    printf("origin address: %p\n", &origin);
    // printf("origin value: %d\n", *origin);
    // print_array(origin, 7);
    if (origin == NULL) {
        printf("NUll Pointer\n");
    }
    print_array(last, length);
    // 如果 `source` 是动态分配的内存（如 `malloc`），你应该使用 `free(source)` 来释放内存

    return 0;
}
