// By Rafael Baculima (Sigladon)

#include <stdio.h>
#include <stdlib.h>

// Estructura del Nodo
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Estructura para la lista anidada
typedef struct LinkedList {
    Node *head;
} LinkedList;

// Prototipos de las funciones:
void verifyInput(int *value);
void addNode(LinkedList *list, int value);
void showList(LinkedList *list);
void deleteNode(LinkedList *list, int value);
void freeSpace(LinkedList *list);
void cleanScreen();
void clearInputBuffer();
void sortAscending(LinkedList *list);
void sortDescending(LinkedList *list);

int main(void) {
    LinkedList list = {NULL};
    int option, value;

    do {
        puts("Seleccione una opcion:");
        puts("1. Mostrar lista");
        puts("2. Agregar nodo");
        puts("3. Eliminar nodo");
        puts("4. Ordenar lista ascendente");
		puts("5. Ordenar lista descendente");
		puts("6. Salir");
        puts("");
		printf("Opcion: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                showList(&list);
                cleanScreen();
                break;
            case 2:
                verifyInput(&value);
                addNode(&list, value);
                printf("Se ha agregado el nodo con valor %d.\n", value);
                cleanScreen();
                break;
            case 3:
                showList(&list);
                printf("Ingrese el valor a eliminar: ");
                scanf("%d", &value);
                deleteNode(&list, value);
                cleanScreen();
                break;
            case 4:
			    sortAscending(&list);
			    printf("Lista ordenada de forma ascendente.\n");
			    cleanScreen();
			    break;
			case 5:
			    sortDescending(&list);
			    printf("Lista ordenada de forma descendente.\n");
			    cleanScreen();
			    break;
			case 6:
                freeSpace(&list);
                puts("Memoria liberada. Saliendo del programa.");
                cleanScreen();
                break;
            default:
                puts("Opcion invalida. Por favor, ingrese una opcion valida.");
                cleanScreen();
        }

    } while (option != 6);

    return 0;
}

// Función para verificar que se ingrese un número entero:
void verifyInput(int *value) {
    int validInput = 0;
    while (!validInput) {
        printf("Ingrese el numero: ");
        if (scanf("%d", value) != 1) {
            clearInputBuffer();
            puts("Entrada no valida. Debe ingresar un numero entero.");
        } else {
            validInput = 1;
        }
    }
}		

// Función para añadir nodos
void addNode(LinkedList *list, int value) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node *temp = list->head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Función para mostrar los valores contenidos en cada nodo de la lista
void showList(LinkedList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Función para eliminar un nodo con un valor específico
void deleteNode(LinkedList *list, int value) {
    Node *temp = list->head;
    Node *previous = NULL;
    while (temp != NULL) {
        if (temp->value == value) {
            if (previous == NULL) {
                list->head = temp->next;
            } else {
                previous->next = temp->next;
            }
            free(temp);
            return;
        }
        previous = temp;
        temp = temp->next;
    }
    puts("El value no se encontro en la lista");
}

// Función para liberar el espacio usado por la lista
void freeSpace(LinkedList *list) {
    Node *temp = list->head;
    while (temp != NULL) {
        Node *aux = temp;
        temp = temp->next;
        free(aux);
    }
    list->head = NULL;
}

// Función para que se limpie la terminal luego de que cada opción se ejecute correctamente
void cleanScreen() {
    getchar();
    puts("");
    puts("Pulse ENTER para continuar");
    getchar();
    system("cls");
}

// Función para eliminar los saltos de linea del input
void clearInputBuffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

// Función para ordenar la lista de forma ascendente
void sortAscending(LinkedList *list) {
    int swapped;
    Node *ptr = NULL;
    Node *temp;
    
    // Verifica que la lista tenga más de un elemento. De no ser así no hay que ordenar.
    if (list->head == NULL || list->head->next == NULL)
        return;

    do {
        swapped = 0;
        temp = list->head;

        while (temp->next != ptr) {
            if (temp->value > temp->next->value) {
                // Intercambia las referencias next de los nodos
                Node *tempNext = temp->next; // Nodo temporal que va a ser el siguiente al temporal
                temp->next = tempNext->next; // Se intercambian las direcciones entre nodos
                tempNext->next = temp;
                
                // Comprueba si el nodo actual es el primero
                if (temp == list->head) {
                    list->head = tempNext; // Si lo es, el head va a apuntar a este nodo
                } else {
                    Node *prev = list->head; // Si no lo es, verifica su lugar en la lista
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = tempNext;
                }

                swapped = 1;
            }
            temp = temp->next; // El nodo actual pasa a ser el último
        }
        ptr = temp; // Se actualiza el ptr para que apunte al último elemento ordenado
    } while (swapped); // Realiza el bucle hasta que no se haga ningún cambio en la lista
}

// Función para ordenar de forma descendente
void sortDescending(LinkedList *list) {
    int swapped;
    Node *ptr = NULL;
    Node *temp;

    if (list->head == NULL || list->head->next == NULL)
        return;

    do {
        swapped = 0;
        temp = list->head;

        while (temp->next != ptr) {
            if (temp->value < temp->next->value) {
                // Intercambia las referencias next de los nodos
                Node *tempNext = temp->next;
                temp->next = tempNext->next;
                tempNext->next = temp;

                if (temp == list->head) {
                    list->head = tempNext;
                } else {
                    Node *prev = list->head;
                    while (prev->next != temp) {
                        prev = prev->next;
                    }
                    prev->next = tempNext;
                }

                swapped = 1;
            }
            temp = temp->next;
        }
        ptr = temp;
    } while (swapped);
}

