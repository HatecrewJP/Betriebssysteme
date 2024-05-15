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
      //FILE * in_stream = fopen("/home/studi/Desktop/Betriebssysteme/wsort_list/wlist-2","r");

      //Windows
      //FILE * in_stream = fopen("C:\\Users\\JP\\CLionProjects\\Betriebssysteme\\wsort\\wlist-1","r");

      //stdin
      FILE *in_stream =stdin;

      //initial capacity is 1
      size_t capacity = 1;
      size_t word_count = 0;

      char* *dynamic_word_array = malloc(capacity * 8);
      if(dynamic_word_array==NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
      }
      char line[MAX_LENGTH+2];
      while(fgets(line, sizeof(line), in_stream)) {
            if(line[0] == '\n')continue;
            size_t word_length = strlen(line);


            //remove word wrap
            if(line[word_length - 1] == '\n')
                  line[word_length - 1] = '\0';
            word_length = strlen(line);
            if(word_length > MAX_LENGTH) {
                  perror("Word too long");
                  if(line[word_length - 1 ] != '\n') {
                        int tmp = fgetc(in_stream);
                        while (tmp != (int)'\n')
                              tmp = fgetc(in_stream);
                  }
                  continue;
            }

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
            dynamic_word_array[word_count-1] = malloc(word_length + 1);
            if(dynamic_word_array[word_count - 1]== NULL) {
                  perror("malloc");
                  exit(EXIT_FAILURE);
            }
            strcpy(dynamic_word_array[word_count-1],line);
      }

      if(ferror(in_stream)) {
            perror("Reading Error");
            exit(EXIT_FAILURE);
      }
      if(!feof(in_stream)) {
            perror("Unknown Error: No reading error, but EOF not reached");
            exit(EXIT_FAILURE);
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
