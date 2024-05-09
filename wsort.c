#include <ctype.h>
#include <stdbool.h>
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

        int len =  strlen(input_line);
        for (int i = len; i < MAX_LENGTH + 1; i++) {
            input_line[i] = '\0';
        }

        bool is_lowercase_letter = input_line[MAX_LENGTH] >= 97 && input_line[MAX_LENGTH] <= 122;
        bool is_uppercase_letter = input_line[MAX_LENGTH] >= 65 && input_line[MAX_LENGTH] <= 90;
        if(is_lowercase_letter||is_uppercase_letter) {
            char *error = "Error: Word too long: ";
            strcat(error,input_line);
            fputs(error,stderr);
        }

        reached_file_end = feof(input_stream);
        words_read++;
        char_array = realloc(char_array,words_read * 100 + 1);
        for (int i = 0; i< 100; i++) {
            char_array[(words_read)*100] = '\0';
        }
        for (int i = 0; i < MAX_LENGTH;i++) {
            if(input_line[i] == '\n') {
                char_array[(words_read - 1) *100 + i] = '\0';
            }
            else {
                char_array[(words_read - 1) *100 + i] = input_line[i];
            }
        }
        free(input_line);
    }
    return char_array;
}

static void char_array_to_output(char* char_array, FILE *out_stream) {
    char out_string[words_read * 100];
    for(int i = 0; i < (words_read * 100);i++) {
        out_string[i] = '\0';
    }
    int symbols_in_output = 0;

    for (int i_th_word = 0; i_th_word < words_read; i_th_word++) {
        int symbol_in_word = 0;
        char current_symbol = char_array[i_th_word * 100 + symbol_in_word];

        while (current_symbol != '\0' && symbol_in_word < 100){

            symbols_in_output++;
            out_string[symbols_in_output-1] = current_symbol;
            symbol_in_word++;
            current_symbol = char_array[i_th_word * 100 + symbol_in_word];

        }
        strcat(out_string, "\n");
        symbols_in_output++;
    }
    fputs(out_string,out_stream);
}
static void destruct_char_array(char* ptr) {
    free(ptr);
}
static int compare(const void* input1, const void* input2) {
    int index = 0;
    char *inputA = (char*) input1;
    char *inputB = (char*) input2;

    char a = inputA[index];
    char b = inputB[index];
    while (a==b) {
        index++;
        a = inputA[index];
        b = inputB[index];
    }
    //same letter cases
    //a is lowercase, b uppercase
    if((a-b) == 32) return -1;
    //same case
    if((a-b) == 0) return 0;
    //a uppercase, b lowercase
    if((a-b) == -32) return 1;

    //different letter
    a = tolower(a);
    b = tolower(b);
    return a-b;
}

void wsort(void) {
    FILE *in_stream = fopen("/home/studi/Desktop/Betriebssysteme/wsort_list/wlist1","r");
    FILE *out_stream = fopen("/home/studi/Desktop/Betriebssysteme/wsort_list/wlist-3","w");
    char* pointer_array_ptr = create_array(in_stream);

    qsort(pointer_array_ptr,words_read,100,compare);

    char_array_to_output(pointer_array_ptr,out_stream);
    destruct_char_array(pointer_array_ptr);
}


int main (int argc, char* argv[]) {
      wsort();
}
