	#include "stdlib.h"
	#include "stdio.h"
	#include "string.h"
	const int list_default_capacity = 16;

	typedef struct d_string{ 
		void* this;
		size_t size;
		size_t capacity;
		char* cur_arr;
		 void (*push)(struct d_string*, char);
		 char (*pop)(struct d_string*);
		 int (*str)(struct d_string*);
		 char* (*get)(struct d_string*);
		 d_string* (*concat)(struct d_string*);
	 } d_string;
		 void push_string(struct d_string* this, char val) { if(this->size == this->capacity -1){ printf("Resizing dinamic array! current capacity was: %d\n", this->capacity);
			 this->capacity *= 2;
			 this->cur_arr = realloc(this->cur_arr, this->capacity * sizeof(char));
		 } this->cur_arr[this->size++] = val;
		 printf("pushed " "\"%c\"" "!\n", val);
	 } 
	 
	 
	 char pop_string(d_string* this) { return (this->size > 0) ? this->cur_arr[--(this->size)] : 0;} 
	
	 int str_string(d_string* this) { size_t s = this->size;
			 if (s < 1) { return 0;
		} char* _vals = this->cur_arr;
		 printf("[ ");
		 for(int i = 0;
			 i < s;
			 i++ ){ printf( "\"%c\"" ", ", _vals[i]);
		 } printf("\b\b ] size: %d, capacity: %d \n", s, this->capacity);
	 };
	
	char* get_string(d_string* this) {
		size_t size = this->size;
		char* ret = malloc(size*sizeof(char)+1);
		memcpy(ret, this->cur_arr, size*sizeof(char));
		ret[size-1] = '\0';
		return ret;
	}

	char* concat_d_string(d_string* this, d_string* other){}

	 d_string new_string(char* arr, size_t s) { size_t init_capacity;
			 size_t init_size = s;
			 char* init_arr;
			 if (arr != ((void *)0)){ init_capacity = s*2;
			 init_arr = malloc(s * sizeof(char));
			 memcpy(init_arr, arr, s * sizeof(char));
		 } else { init_capacity = (s > list_default_capacity) ? s : list_default_capacity;
			 init_arr = (char*) calloc(init_capacity, sizeof(char));
		 } d_string* list = (d_string*) malloc(sizeof(d_string));
		 *list = (d_string){ &list, init_size, init_capacity, init_arr, &push_string, &pop_string, &str_string, &get_string };
		 return *list;
	 };

// int main(){
// 	d_string s = new_string(NULL, 0);
// 	s.push(&s, '1');
// 	s.push(&s, '1');
// 	s.push(&s, '1');
// 	s.push(&s, '0');
// 	printf("string: %s", s.get(&s));
// }
