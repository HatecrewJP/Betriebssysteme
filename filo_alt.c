#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>



// TODO: structs, global variables, etc.

struct listElement {
	int element_value;
	struct listElement *next_element_ptr;
};


static struct listElement *listHead;
static struct listElement listEnd;

static bool already_in_list(int value) {
struct listElement current_element = listEnd;

	//if the next element of current_element is NULL, the end of the list is reached
	while(current_element.next_element_ptr != NULL) {
		if(current_element.element_value == value) {
			return true;
		}
		current_element = *current_element.next_element_ptr;
	}
	if(current_element.element_value == value) return true;
	return false;
}


static int insertElement(signed int value) {
	if(value < 0) return -1;
	if(already_in_list(value)) {
		return -1;
	}
	//next Element is non existent.Therefore next_elementptr is NULL
	struct listElement new_element;
	new_element.element_value = value;
	new_element.next_element_ptr = NULL;


	struct listElement *new_head_ptr;

	new_head_ptr = malloc(ELEMENT_SIZE);
	if(new_head_ptr == NULL) {
		return -1;
	}

	listHead->next_element_ptr = new_head_ptr;
	listHead = new_head_ptr;

	*listHead = new_element;

	return  listHead->element_value;
}

static int removeElement(void) {

	struct listElement *current_element_ptr;
	struct listElement *following_element_ptr;

	current_element_ptr = &listEnd;
	following_element_ptr = current_element_ptr->next_element_ptr;
	if(following_element_ptr == NULL) {
		return -1;
	}

	//if next_element_ptr of following_element is NULL, then following_lement is the last Element
	while (following_element_ptr->next_element_ptr != NULL) {
		current_element_ptr = following_element_ptr;
		following_element_ptr = following_element_ptr->next_element_ptr;
	}
	//error check
	if(current_element_ptr == NULL) return -2;

	struct listElement *removing_element_ptr = following_element_ptr;
	listHead = current_element_ptr;
	int value_of_removed_element = removing_element_ptr->element_value;
	free(removing_element_ptr);
	listHead->next_element_ptr = NULL;

	return value_of_removed_element;
}

static void deleteList(void) {
	while(listHead != &listEnd) {
		removeElement();
	}
}


int main (int argc, char* argv[]) {
	
	//value contains -1 to signal the End of the List
	listEnd.element_value = -1;
	//next Element is NULL since its the start of the List at the moment of initialization
	listEnd.next_element_ptr = NULL;

	listHead = &listEnd;

	printf("insert 47: %d\n", insertElement(47));
	printf("insert 11: %d\n", insertElement(11));
	printf("insert 23: %d\n", insertElement(23));
	printf("insert 11: %d\n", insertElement(11));

	printf("remove: %d\n", removeElement());
	printf("remove: %d\n", removeElement());




	deleteList();
	exit(EXIT_SUCCESS);
}
