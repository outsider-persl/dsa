#include <algorithm>
#include <iostream>

int* copy(int* source, int start, int end) {
    int* target = new int[end - start];
    int index = 0;
    for (int i = start; i < end; i++) {
        target[index++] = source[i];
    }
    return target;
}
void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}
int main(int argc, char const* argv[]) {
    int source[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(source) / sizeof(source[0]);
    print_array(source, size);

    int* target = copy(source, 2, 6);
    print_array(target, 4);
    return 0;
}
