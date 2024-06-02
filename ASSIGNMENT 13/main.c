  /*
    program for adding, sorting, and
    deleting species informations
    a great exercise for linked lists
    written by: zeynepsturan
  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
  char class[30];
  char order[30];
  char family[30];
  char genus[30];
  char species[30];
  struct node *next;
}node;

/*sorting functions*/
void
  sort_by_class(node **root),
  sort_by_order(node **root),
  sort_by_family(node **root),
  sort_by_genus(node **root),
  sort_by_species(node **root)
;

/*other necessary functions*/
void
  add_data(node **root),
  print_list(node **root),
  free_list(node **root),
  correct_info(node **root),
  delete_species(node **root)
;

int print_menu(node **root);

int main(){

  node *root = malloc(sizeof(node));
  strcpy(root->class,"empty");
  root->next = NULL;
  
  print_menu(&root);
  free_list(&root);
  
  return 0;
}

void delete_species(node **root){
  node *current;
  node *previous = NULL;
  node* deleted = NULL;
  current = *root;
  
  char species_name[30];
  int flag = 0;
  
  printf("Please enter the species name to delete: ");
  scanf(" %[^\n]s", species_name);
  
  /*searching through the list*/
  while(current != NULL){
  
      if(strcmp(current->species, species_name) == 0){ /*if the species is found*/
        flag = 1;
        deleted = current;
        if(previous == NULL){ /*if root is being deleted*/
          *root = current->next;
        }
        
        else{
          previous->next = current->next;
        }
        free(deleted);
      }
      previous = current;
      current = current->next;
  }
  
  if(flag){
    printf("%s is deleted\n",species_name);
  }
  
  else{
    printf("%s does not exist in the list\n",species_name);
  }
}

void correct_info(node **root){
  node *current;
  current = *root;
  
  char criteria[10];
  char species_name[30];
  int flag = 0;
  
  printf("Please enter the species name to change info: ");
  scanf(" %[^\n]s", species_name);
  
  /*searching through the list*/
  while(current != NULL){
  
      if(strcmp(current->species, species_name) == 0){ /*if the species is found*/
        flag = 1;
        
        printf("Enter the criteria you want to change(class, order, family, genus, species): ");
        scanf("%s", criteria);
        
        if(strcmp(criteria, "class") == 0){
        
          printf("Enter the new class: ");
          scanf(" %[^\n]s",current->class);
        }
      
        else if(strcmp(criteria, "order") == 0){
        
          printf("Enter the new order: ");
          scanf(" %[^\n]s",current->order);
        }
        
        else if(strcmp(criteria, "family") == 0){
        
          printf("Enter the new family: ");
          scanf(" %[^\n]s",current->family);
        }

        else if(strcmp(criteria, "genus") == 0){
          printf("Enter the new genus: ");
          scanf(" %[^\n]s",current->genus);
        }
      
        else if(strcmp(criteria, "species") == 0){
        
          printf("Enter the new species: ");
          scanf(" %[^\n]s",current->species);
        }
      
        else{
        
          flag = 0;
          printf("There is no such a criteria.\n");
          return;
        }
        
      }
      
      if(flag){
      
        printf("\nCorrected information:\n");
        printf("Class: %s\n", current->class);
        printf("Order: %s\n", current->order);
        printf("Family: %s\n", current->family);
        printf("Genus: %s\n", current->genus);
        printf("Species: %s\n\n", current->species);
        return;
      }
      current = current->next;
    }
    
    if(!flag){
      printf("The species you entered does not exist in the list.\n");
    }
}

void add_data(node **root){ /*adds new data to end of the list*/
  node *current;
  
  if(*root == NULL){ /*if root is null*/
    root = malloc(sizeof(node)); /*creates a node that root points to*/
    current= *root;
    current->next = NULL;
    
  }
  
  else{
    current= *root;
    
    /*going to end of the list*/
    while(current->next != NULL){
      current = current->next;
    }
    
    if(strcmp(current->class,"empty") != 0){ /*if the last element of the item is not empty*/
    
      /*creating a new node*/
      current->next = malloc(sizeof(node));
    
      /*going to the new node*/
      current = current->next;
      current->next = NULL;
    }
    
  }
  
  /*adding information*/
  printf("\nEnter Species information:\n");
  
  printf("Class: ");
  scanf(" %[^\n]s", current->class);
  
  printf("Order: ");
  scanf(" %[^\n]s", current->order);
  
  printf("Family: ");
  scanf(" %[^\n]s", current->family);
  
  printf("Genus: ");
  scanf(" %[^\n]s", current->genus);
  
  printf("Species: ");
  scanf(" %[^\n]s", current->species);
  printf("\n");
}

void free_list(node **root){ /*deallocating the whole list*/
  node *current = *root;
  node *temp;
  
  while(current->next != NULL){ /*freeing each element one by one*/
    temp = current;
    current = current->next;
    temp = NULL;
  }
  *root = NULL;
}

void print_list(node **root){ /*prints the whole list*/

  node *current= *root;
  
  printf("\nListed Species:\n");
  while(current != NULL){
    /*printing*/
    printf("Class: %s\n", current->class);
    printf("Order: %s\n", current->order);
    printf("Family: %s\n", current->family);
    printf("Genus: %s\n", current->genus);
    printf("Species: %s\n\n", current->species);
    
    /*going to the next element*/
    current = current->next;
  }
}

void sort_by_class(node **root){
  node temp; /*temporary node to use swapping*/
  node *current;
  
  int list_size=0;
  int i, j;
  
  /*finding the list size*/
  current = *root;
  
  while(current != NULL){
    list_size++;
    current = current->next;
  }
  
  /*bubble sort*/
  current = *root;
  
  for(i=0; i<list_size-1; i++){
    
    /*going to right element of the item*/
    for(j=0; j<i; j++){
      current = current->next;
    }
    
    /*sorting*/
    while(current->next != NULL){
    
      if(strcmp(current->class, current->next->class) > 0){
        /*swapping*/
        strcpy(temp.class, current->class);
        strcpy(current->class, current->next->class);
        strcpy(current->next->class, temp.class);
      }
      current = current->next;
    }
    current = *root;
    
  }
  return;
}

void sort_by_order(node **root){
  node temp; /*temporary node to use swapping*/
  node *current;
  
  int list_size=0;
  int i, j;
  
  /*finding the list size*/
  current = *root;
  
  while(current != NULL){
    list_size++;
    current = current->next;
  }
  
  /*bubble sort*/
  current = *root;
  
  for(i=0; i<list_size-1; i++){
    
    /*going to right element of the item*/
    for(j=0; j<i; j++){
      current = current->next;
    }
    
    /*sorting*/
    while(current->next != NULL){
    
      if(strcmp(current->order, current->next->order) > 0){
        /*swapping*/
        strcpy(temp.order, current->order);
        strcpy(current->order, current->next->order);
        strcpy(current->order, temp.order);
      }
      current = current->next;
    }
    current = *root;
  }
  return;
}

void sort_by_family(node **root){
  node temp; /*temporary node to use swapping*/
  node *current;
  
  int list_size=0;
  int i, j;
  
  /*finding the list size*/
  current = *root;
  
  while(current != NULL){
    list_size++;
    current = current->next;
  }
  
  /*bubble sort*/
  current = *root;
  
  for(i=0; i<list_size-1; i++){
    
    /*going to right element of the item*/
    for(j=0; j<i; j++){
      current = current->next;
    }
    
    /*sorting*/
    while(current->next != NULL){
    
      if(strcmp(current->family, current->next->family) > 0){
        /*swapping*/
        strcpy(temp.family, current->family);
        strcpy(current->family, current->next->family);
        strcpy(current->next->family, temp.family);
      }
      current = current->next;
    }
    current = *root;
  }
  return;
}

void sort_by_genus(node **root){
  node temp; /*temporary node to use swapping*/
  node *current;
  
  int list_size=0;
  int i, j;
  
  /*finding the list size*/
  current = *root;
  
  while(current != NULL){
    list_size++;
    current = current->next;
  }
  
  /*bubble sort*/
  current = *root;
  
  for(i=0; i<list_size-1; i++){
    
    /*going to right element of the item*/
    for(j=0; j<i; j++){
      current = current->next;
    }
    
    /*sorting*/
    while(current->next != NULL){
    
      if(strcmp(current->genus, current->next->genus) > 0){
        /*swapping*/
        strcpy(temp.genus, current->genus);
        strcpy(current->genus, current->next->genus);
        strcpy(current->next->genus, temp.genus);
      }
      current = current->next;
    }
    current = *root;
  }
  return;
}

void sort_by_species(node **root){
  node temp; /*temporary node to use swapping*/
  node *current;
  
  int list_size=0;
  int i, j;
  
  /*finding the list size*/
  current = *root;
  
  while(current != NULL){
    list_size++;
    current = current->next;
  }
  
  /*bubble sort*/
  current = *root;
  
  for(i=0; i<list_size-1; i++){
    
    /*going to right element of the item*/
    for(j=0; j<i; j++){
      current = current->next;
    }
    
    /*sorting*/
    while(current->next != NULL){
    
      if(strcmp(current->species, current->next->species) > 0){
        /*swapping*/
        strcpy(temp.species, current->species);
        strcpy(current->species, current->next->species);
        strcpy(current->next->species, temp.species);
      }
      current = current->next;
    }
    current = *root;
  }
  return;
}

int print_menu(node **root){ /*recursive*/

  static char choice;
  static char sort_choice[10];
  
  printf("->Enter 1 to add data\n");
  printf("->Enter 2 to sort data\n");
  printf("->Enter 3 to correct data\n");
  printf("->Enter 4 to delete species\n");
  printf("->Enter 0 to exit program\n");
  printf("--Your choice: ");
  scanf(" %c", &choice);
  
  switch(choice){

    case '0':
    return 0;
    break;
    
    case '1':
    add_data(root);
    print_menu(root);
    break;
    
    case '2':
    printf("Enter the list criteria(class, order, family, genus, species): ");
    scanf("%s", sort_choice);
    
    if(strcmp(sort_choice, "class") == 0){
      sort_by_class(root);
      print_list(root);
      print_menu(root);
    }
    
    else if(strcmp(sort_choice, "order") == 0){
      sort_by_order(root);
      print_list(root);
      print_menu(root);
    }
    
    else if(strcmp(sort_choice, "family") == 0){
      sort_by_family(root);
      print_list(root);
      print_menu(root);
    }

    else if(strcmp(sort_choice, "genus") == 0){
      sort_by_genus(root);
      print_list(root);
      print_menu(root);
    }
    
    else if(strcmp(sort_choice, "species") == 0){
      sort_by_species(root);
      print_list(root);
      print_menu(root);
    }
    
    else{
      printf("There is no such a list criteria. Enter your choice again.\n");
      print_menu(root);
    }
    
    break;
    
    case '3':
    correct_info(root);
    print_menu(root);
    break;
    
    case '4':
    delete_species(root);
    print_menu(root);
    break;

    default:
    printf("There is no such an option. Enter your choice again.\n");
    break;
  }
}
