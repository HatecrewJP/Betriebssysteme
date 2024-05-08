#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct listElement {
  int element_value;
  struct listElement *next_element_ptr;
};

static struct listElement *listHead = NULL; // only global variable

static bool already_in_list(int value) {
  struct listElement *current_element = listHead;

  // traverse until next_element_ptr is NULL (end of list)
  while (current_element != NULL) {
    if (current_element->element_value == value) {
      return true;
    }
    current_element = current_element->next_element_ptr;
  }
  return false;
}

int insertElement(signed int value) {
  if (value < 0) return -1;
  if (already_in_list(value)) {
    return -1;
  }
  static const int ELEMENT_SIZE = sizeof(struct listElement);
  // allocate memory for new element
  struct listElement *new_element = malloc(ELEMENT_SIZE);
  if (new_element == NULL) {
    return -1;
  }

  new_element->element_value = value;

  // new element points to current head
  new_element->next_element_ptr = listHead;

  // update list head with new element
  listHead = new_element;

  return listHead->element_value;
}

int removeElement(void) {

  if (listHead == NULL) {
    return -1;
  }

  // remove and return the current head
  int value_of_removed_element = listHead->element_value;
  struct listElement *temp = listHead;
  listHead = listHead->next_element_ptr;
  free(temp);

  return value_of_removed_element;
}

static void deleteList(void) {
  while (listHead != NULL) {
    removeElement();
  }
}



int main (int argc, char* argv[]) {




	printf("insert 47: %d\n", insertElement(47));
	printf("insert 11: %d\n", insertElement(11));
	printf("insert 23: %d\n", insertElement(23));
	printf("insert 11: %d\n", insertElement(11));
	printf("insert -1: %d\n", insertElement(-1));

	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());



	deleteList();
	exit(EXIT_SUCCESS);
}
