#include <iostream>

void sort(int *vec, int len) {
    for(int i = 0; i < len-1; i++) {
        int i_min = i;
        for(int j = i + 1; j < len; j++) {
            if(vec[i_min] > vec[j]) {
                int tmp = vec[i_min];
                vec[i_min] = vec[j];
                vec[j] = tmp;
            }
        }
    }
}

void in_out_vector(int len) {
    int vec[len];
    std::cout << "length = " << len << "\n";
    for(int i = 0; i < len; i++) {
        vec[i] = len - i;
    }
    sort(vec, len);
    for(int i = 0; i < len; i++) {
        printf("%d  ", vec[i]);
    }
    printf("\n");
}

 int main() {
    int len;
    std::cout << "input length: ";
    std::cin >> len;
    in_out_vector(len);
    return 0;
}

