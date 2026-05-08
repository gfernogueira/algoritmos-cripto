#include "algos.h"
#include "DataStructures/list.c"
#include <math.h>

void mdce(int a, int b){
	
}

void fermat(int n){

}

void crivo(int n){
    if (n > 32767) n = 32767;
    if (n < 3)     n = 3;

    List_Int nums = new_List_Int(NULL, (n - 1) / 2);
    for (int i = 3; i < nums.capacity; i+=2){
        nums.push(&nums, i);
    }

    for (int i = 0; i < nums.size; ++i){
        if ((pow(nums.cur_arr[i], 2) > n)) break;

        for (int j = 0; j < nums.size; ++j){
            if (nums.cur_arr[j] % nums.cur_arr[i] == 0){
                nums.cur_arr[j] = -1;
            }
        }
    }

    for (int i = 0; i < nums.size; ++i){
        if (nums.cur_arr[i] != -1) printf("\n%d", nums.cur_arr[i]);
    }
}