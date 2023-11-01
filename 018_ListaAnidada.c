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

// Función para ordenar la lista
void sortAscending(LinkedList *list) {
    int swapped;
    Node *ptr = NULL;
    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        Node *temp = list->head;

        while (temp->next != ptr) {
            if (temp->value > temp->next->value) {
                int tempValue = temp->value;
                temp->value = temp->next->value;
                temp->next->value = tempValue;
                swapped = 1;
            }
            temp = temp->next;
        }
        ptr = temp;
    } while (swapped);
}

void sortDescending(LinkedList *list) {
    int swapped;
    Node *ptr = NULL;
    if (list->head == NULL)
        return;

    do {
        swapped = 0;
        Node *temp = list->head;

        while (temp->next != ptr) {
            if (temp->value < temp->next->value) {
                int tempValue = temp->value;
                temp->value = temp->next->value;
                temp->next->value = tempValue;
                swapped = 1;
            }
            temp = temp->next;
        }
        ptr = temp;
    } while (swapped);
}
