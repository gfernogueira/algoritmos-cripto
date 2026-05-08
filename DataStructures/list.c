#include "stdlib.h"
#include "stdio.h"
#include "string.h"
const int list_default_capacity = 16;

#define declare_typed_list(Name, Name_Mod, Type, Format)\
typedef struct Name##Name_Mod{ \
    void* this;\
		size_t size;\
		size_t capacity;\
		Type* cur_arr;\
		void (*push)(struct Name##Name_Mod*, Type); \
		Type (*pop)(struct Name##Name_Mod*); \
		void (*str)(struct Name##Name_Mod*); \
\
    } Name##Name_Mod; \
void push_##Name##Name_Mod(struct Name##Name_Mod* this, Type val) {\
		if(this->size == this->capacity -1){\
			printf("Resizing dinamic array! current capacity was: %d\n", this->capacity);\
			this->capacity *= 2;\
			this->cur_arr = realloc(this->cur_arr, this->capacity * sizeof(Type));	\
		} \
		this->cur_arr[this->size++] = val;\
	 printf("pushed " Format "!\n", val); \
	} \
Type pop_##Name##Name_Mod(Name##Name_Mod* this) { return (this->size > 0) ? this->cur_arr[--(this->size)] : 0; \
	\
	\
} \
int str_##Name##Name_Mod(Name##Name_Mod* this) {\
			\
			size_t s = this->size;\
			if (s < 1) { return 0;}\
			Type* _vals = this->cur_arr; \
			printf("[ ");\
			for(int i = 0; i < s; i++ ){\
	 			printf( Format ", ", _vals[i]);\
			}\
			printf("\b\b ] size: %d, capacity: %d \n", s, this->capacity);\
	 }; \
\
Name##Name_Mod new_##Name##Name_Mod(Type* arr, size_t s) { \
		size_t init_capacity;\
		size_t init_size = s;\
		Type* init_arr;\
		if (arr != NULL){\
			init_capacity = s*2;\
			/* reallocs arr to the heap*/ \
			init_arr = malloc(s * sizeof(Type));\
			memcpy(init_arr, arr, s * sizeof(Type));\
			\
		} else {\
			init_capacity = (s > list_default_capacity) ? s : list_default_capacity;\
			init_arr = (Type*) calloc(init_capacity, sizeof(Type));\
		}\
    Name##Name_Mod* list = (Name##Name_Mod*) malloc(sizeof(Name##Name_Mod));\
		\
		\
    *list = (Name##Name_Mod){\
											/*this*/&list,\
											/*size*/init_size,\
											/*capacity*/init_capacity,\
											/*current_array*/init_arr,\
											/*Methods:*/\
											 &push_##Name##Name_Mod,\
											 &pop_##Name##Name_Mod,\
											 &str_##Name##Name_Mod\
										\
											}; \
		return *list; \
	};




	declare_typed_list(List, _Float, float, "%.2f")
	// declare_typed_list(string,, char, "\"%c\"" )
	declare_typed_list(List, CharArr, char*, "\"%s\"")
	// declare_typed_list(List, char*, "%c")

int main(){
	List_Float a = new_List_Float(NULL, 0); 
	// string b = new_string((char[]){'a','b','c'}, 3);
	ListCharArr c = new_ListCharArr((char*)(&(char*[]){"asd", "asd", "asd"}), 3);
	c.push(&c, "assdsd");
	c.str(&c);
	a.push(&a, 0.5);
	a.push(&a, 1);
	a.push(&a, 0.5);
	a.push(&a, 1);
	a.push(&a, 0.5);
	a.push(&a, 1);
	a.str(&a);
	// b.push(&b, 'h');
	// b.push(&b, 'e');
	// b.push(&b, 'l');
	// b.push(&b, 'l');
	// b.push(&b, 'o');
	// b.push(&b, '!');
	// b.str(&b);

}
