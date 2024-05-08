#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


//
// Created by JP on 04.05.2024.
//
//making words-read global helps freeing the allocated memory
static int words_read = 0;


static char* create_array(FILE * input_stream) {
    const int MAX_LENGTH = 100;
    //select input stream
    int reached_file_end=0;
    char *char_array = malloc(1);
    //read the words
    while(!reached_file_end) {
        char* input_line = malloc(MAX_LENGTH + 1);
        fgets(input_line,MAX_LENGTH + 1 ,input_stream);
        reached_file_end = feof(input_stream);
        words_read++;
         char_array = realloc(char_array,words_read * 100 + 1);
        for (int i = 0; i < MAX_LENGTH;i++) {
            char_array[(words_read - 1) *100 + i] = input_line[i];
        }
        char_array[words_read * 100] = '\n';
        free(input_line);
    }
    return char_array;
}
static void char_array_to_output(char* char_array, FILE *out_stream) {
    char out_string[words_read * 100] ;

    for (int i_th_word = 0; i_th_word < words_read; i_th_word++) {
        char current_symbol = char_array[i_th_word * 100];
        int symbol_in_word = 0;
        while (current_symbol != '\n' && symbol_in_word < 100){
            current_symbol = char_array[i_th_word * 100 + symbol_in_word];
            out_string[symbol_in_word + i_th_word * 100] = current_symbol;
            symbol_in_word++;
        }
        strcat(out_string, "\n");
    }
    fputs(out_string,out_stream);
}
static void destruct_char_array(char* ptr) {
    free(ptr);
}
static int compare(const void* arg1, const void* arg2) {
    return strcmp(arg1,arg2);
}

void wsort(void) {
    FILE *in_stream = fopen("/home/studi/Desktop/Betriebssysteme/wsort_list/wlist-2","r");
    FILE *out_stream = fopen("/home/studi/Desktop/Betriebssysteme/wsort_list/wlist-3","w");
    char* pointer_array_ptr = create_array(in_stream);

    qsort(pointer_array_ptr,words_read,100,compare);

    char_array_to_output(pointer_array_ptr,out_stream);
    destruct_char_array(pointer_array_ptr);
}


int main (int argc, char* argv[]) {
      wsort();
}