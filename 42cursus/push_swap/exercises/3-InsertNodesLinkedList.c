#include <stdlib.h>
#include <stdio.h>		//Agregar printf

typedef struct s_linkedList {
	//int index;
	int value;
	struct s_linkedList *next;
}	t_linkedList;

t_linkedList *create_node (int value) {
	
	t_linkedList *new_node;
	
	new_node = malloc (sizeof(t_linkedList));

	if (!new_node)
		return (NULL);
	new_node->value = value;
	//new_node->index = -1;
	new_node->next = NULL;

	return (new_node);
}

void print_list (t_linkedList *head){
	t_linkedList *current;

	current = head;
	printf ("Lista: ");
	while (current){
		//printf("[index: %d, value: %d] -> ", current->index, current->value);
		printf("[ %d ] -> ", current->value);
		current = current->next;
	}
	printf("NULL\n");
}

void push_front (t_linkedList **head, int value){
	t_linkedList *new_node;
	new_node = create_node(value);
	if (!new_node)
		return;
	new_node->next = *head;
	*head = new_node;
}

void push_back(t_linkedList **head, int value){

	t_linkedList *new_node;
	t_linkedList *current;
	new_node = create_node(value);
	if (!new_node)
		return;
	if (!*head){
		*head = new_node;
		return;
	}
	current = *head;
	while (current->next){
		current = current->next;
	}
	current->next = new_node;
}

void insert_at(t_linkedList **head, int position, int value) {
	t_linkedList *new_node;
	t_linkedList *prev;
	int i;

	if (position == 0) {
		push_front(head, value);
		return;
	}
	new_node = create_node(value);
	if (!new_node)
		return;
	if (!*head) {
		*head = new_node;
		return;
	}
	/*Hasta aqui hice*/
	prev = *head;
	i = 0;
	while (i < position - 1 && prev->next) {
		prev = prev->next;
		i++;
	}
	new_node->next = prev->next;
	prev->next = new_node;
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

	i = 4;
	while (i < 20){
		new_node = create_node(i);
		if (!head){
			head = new_node;
			current = new_node;
		} else {
			current->next = new_node;
			current = new_node;
		}
		i+=2;		
	}
	print_list(head);
	
	push_front(&head, 1);
	print_list(head);
	
	push_back(&head, 50);
	print_list(head);

	// Pruebas de insert_at:	
	insert_at(&head, 0, 0);    // Insertar 0 en posición 0
	printf("Después de insertar 0 en posición 0:\n");
	print_list(head);

	insert_at(&head, 3, 5);     // Insertar 5 en posición 3
	printf("Después de insertar 5 en posición 3:\n");
	print_list(head);

	insert_at(&head, 12, 55);   // Insertar 55 en posición 12 (al final)
	printf("Después de insertar 55 en posición 12:\n");
	print_list(head);
	
	free_list(head);

	return (0);
}
