#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 100


int compare(const void *a, const void *b) {
      return strcmp(*(char**) a, *(char**) b);
}

void wsort(void) {
      //choose input
      //Unix
      //FILE * in_stream = fopen("/home/studi/Desktop/Betriebssysteme/wsort_list/wlist0","r");

      //Windows
      FILE * in_stream = fopen("C:\\Users\\JP\\CLionProjects\\Betriebssysteme\\wsort\\wlist0","r");

      //stdin
      //FILE +in_stream =stdin;

      //initial capacity is 1
      size_t capacity = 1;
      size_t word_count = 0;

      char* *dynamic_word_array = malloc(capacity * 8);
      if(dynamic_word_array==NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
      }

      char line[MAX_LENGTH+2];
      int file_end = 0;
      while(1) {
            fgets(line, MAX_LENGTH + 2, in_stream);
            file_end = feof(in_stream);
            if(ferror(in_stream)) {
                  perror("Reading error");
                  exit( EXIT_FAILURE);
            }
            if(line[0] == '\n')continue;
            if(strlen(line) > MAX_LENGTH) {
                  perror("word too long");
                  continue;
            }

            //remove word wrap
            if(line[strlen(line) - 1 ] == '\n') line[strlen(line) - 1 ] = '\0';

            //resize the array if nescessary
            if(word_count >= capacity) {
                  capacity = capacity * 2 ;
                  dynamic_word_array= realloc(dynamic_word_array,(capacity * 8));
                  if(dynamic_word_array == NULL) {
                        perror("realloc");
                        exit(EXIT_FAILURE);
                  }
            }
            word_count++;
            dynamic_word_array[word_count-1] = malloc(strlen(line) + 1);
            if(dynamic_word_array[word_count - 1]== NULL) {
                  perror("malloc");
                  exit(EXIT_FAILURE);
            }
            strcpy(dynamic_word_array[word_count-1],line);

            if(file_end) break;

      }
      //sort array
      qsort(dynamic_word_array,word_count,sizeof(char*),compare);

      //output of the array
      for(int i = 0; i< word_count; i++) {
            fprintf(stdout,"%s\n",dynamic_word_array[i]);
            if(ferror(stdout)) {
                  perror("Output error");
                  exit(EXIT_FAILURE);
            }
            if(fflush(stdout)){
                  perror("flush error");
                  exit(EXIT_FAILURE);
            }
      }

      for(int i = 0; i < word_count; i++) {
            free(dynamic_word_array[i]);
      }
      free(dynamic_word_array);
}
int main (int argc, char* argv[]) {
      wsort();
}
