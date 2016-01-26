#include <assert.h>
#include <stdlib.h>

#include "list.h"

// Takes a valid, sorted list starting at `head` and adds the element
// `new_element` to the list. The list is sorted based on the value of the
// `index` member in ascending order. Returns a pointer to the head of the list
// after the insertion of the new element.
list_t* insert_sorted(list_t* head, list_t* new_element) {
	assert(head != NULL);
	assert(new_element != NULL);

	int found = 0;

	list_t* current = head;

	if (new_element->index <= head->index){
		found = 1;
		new_element->next = head;
		head = new_element;
	}
	
	while (!found && current->next){
		if (new_element->index <= current->next->index){
			found = 1;
			new_element->next = current->next;
			current->next = new_element;
		}
		else{
			current = current->next;
		}
	}

	if (current->next == NULL){
		current->next = new_element;
		new_element->next = NULL;
	}

	return head;
}

static list_t* helper(list_t* head, list_t* previous){
	list_t* temp_node;
	if (head->next==NULL){
		head->next = previous;
		return head;
	}
	else{
		temp_node = head->next;
		head->next = previous;
		return helper(temp_node, head);
	}
}

// Reverses the order of the list starting at `head` and returns a pointer to
// the resulting list. You do not need to preserve the original list.
list_t* reverse(list_t* head) {
	assert(head != NULL);

	list_t* temp_node;
	temp_node = head->next;

	head->next = NULL;

	head = helper(temp_node, head);


	return head;
}

