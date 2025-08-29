#include <stdlib.h>
#include <stdio.h>		//Agregar printf

typedef struct s_linkedList {
	int index;
	int value;
	struct s_linkedList *next;
}	t_linkedList;

t_linkedList *create_node (int value) {
	
	t_linkedList *new_node;
	
	new_node = malloc (sizeof(t_linkedList));

	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = -1;
	new_node->next = NULL;

	return (new_node);
}

void print_list (t_linkedList *head){
	t_linkedList *current;

	current = head;
	printf ("Lista: ");
	while (current){
		printf("[index: %d, value: %d] -> ", current->index, current->value);
		current = current->next;
	}
	printf("NULL\n");
}

void free_list(t_linkedList *head){
	t_linkedList *temp;
	while (head){
		temp = head->next;
		free(head);
		head = temp;
	}
}

int main (){
	
	t_linkedList *head;
	t_linkedList *current;
	t_linkedList *new_node;
	int i;

	head = NULL;
	current = NULL;

	i = 0;
	while (i < 10){
		new_node = create_node(i);
		if (!head){
			head = new_node;
			current = new_node;
		} else {
			current->next = new_node;
			current = new_node;
		}
		i++;		
	}
	print_list(head);
	free_list(head);

	return (0);
}
