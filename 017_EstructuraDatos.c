// By Rafael Baculima (sigladon)
// Lista Simple con Inserción
// Referencia: https://www.hackerearth.com/practice/data-structures/linked-list/singly-linked-list/tutorial/

#include <stdio.h>
#include <stdlib.h>

// Creando una estructura de datos para el tipo nodo
typedef struct nodes {
  int nodeValue;
  struct nodes *next;
} *NODE; // Se define la estructura como puntero


NODE createNode(void);
NODE insertNode(NODE *head, int value);
void printList(NODE head);


int main(void) {
	
	NODE head = NULL;
	
	insertNode(&head, 2);
	insertNode(&head, 5);
	insertNode(&head, 8);
	insertNode(&head, 3);
	insertNode(&head, 11);
	insertNode(&head, 7);
	
	printList(head);
	
	free(head);
	
	return 0;

}

// Función para crear un nodo
NODE createNode(void) {
	
	NODE newNode = malloc(sizeof(NODE)); // Dar espacio en memoria HEAP 
	newNode->next = NULL; // Asignar valor NULL al puntero que apunta al siguiente nodo
	
	return newNode;
}

// Función para insertar nodo
NODE insertNode(NODE *head, int value) {
	
	NODE tmp = createNode(), curr; // Crear dos nodos. Uno en el que se almacenará el nuevo nodo, y otro que se usara para iterar en los nodos
	tmp->nodeValue = value;
	
	if (*head == NULL) {
		*head = tmp;
	} else {
		curr = *head;
		while (curr->next != NULL) {
			curr = curr->next;
		}
		curr->next = tmp;
	}
	
	return *head;
}

// Función para imprimir la lista
void printList(NODE head) {
	
	NODE tmp = head;
	
	printf("%s -> ", "HEAD");
	while (tmp != NULL) { // Se recorre la lista hasta que un nodo sea NULL
		printf("%d -> ", tmp->nodeValue);
		tmp = tmp->next;
	}
	puts("NULL");
}