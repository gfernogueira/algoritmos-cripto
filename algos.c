#include "algos.h"
#include "DataStructures/list.c"
#include <math.h>

void mdce(int a, int b){
	
}

void fermat(int n){
    if (n < 2) {
        printf("\nnão é primo");
        return;
    }
    
    int x = (int)ceil(sqrt(n));
    int y;
    int z;
    
    while (1){
        z = x * x - n;
        y = (int)sqrt(z);
        if (y * y == z) break;
        ++x;
    }
    
    if (x - y == 1){
        printf("\nprimo");
    }
    else{
        printf("\nfator1: %d\nfator2: %d", x - y, x + y);
    }
}

void crivo(int n){
    if (n > 32767) n = 32767;
    if (n < 3)     n = 3;

    List_Int nums = new_List_Int(NULL, 0);
    for (int i = 3; i < n + 1; i+=2){
        nums.push(&nums, i);
    }

    for (int i = 0; i < nums.size; ++i){
        int p = nums.cur_arr[i];

        if (p == -1) continue;
        if (p * p > n) break;

        for (int j = i + 1; j < nums.size; ++j){
            if (nums.cur_arr[j] % p == 0){
                nums.cur_arr[j] = -1;
            }
        }
    }

    printf("\n2");
    for (int i = 0; i < nums.size; ++i){
        if (nums.cur_arr[i] != -1) printf("\n%d", nums.cur_arr[i]);
    }
}