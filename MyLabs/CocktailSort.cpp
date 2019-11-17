#include <iostream>

using namespace std;

struct Node{
  int data;
  struct Node *next;
  struct Node *prev;
};

struct sortList{
  size_t size;
  struct Node *head;
  struct Node *tail;
};

struct sortList list;

int menu();
void search(int value);
void creatList();
void insert(int value);
void display();
void swap(int *a, int *b);
void shakerSort();
//void remove(int value);
int cnt(int *arr, int s);

int main(void){
    int i,n,g,choice,findEl;
    creatList();
    cout<<"Введите размер массива"<<endl;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>g;
        arr[i] = g;
    }
    for(i=0;i<n;i++){
        insert(arr[i]);
    }
    shakerSort();
    do {
        choice = menu();
        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                shakerSort();
                break;
            case 3:
                int c;
                c = cnt(arr, n);
                cout<<"Колличество различных элементов: "<<c<<endl;
                break;
            case 4:
                cout<<"Что хотите найти?"<<endl;
                cout<<">>> ";
                cin>>findEl;
                search(findEl);
                break;
            case 5:
                cout << "Выход из программы..." << endl;
                exit(EXIT_SUCCESS);
                break;
            default:
                cout<<"Ошибка!"<<endl;
                exit(EXIT_FAILURE);
        }
    } while (choice !=5);
    return 0;
}

void display(){
    struct Node *ptr = list.head;
    cout<<"Данные:"<<endl;
    while (ptr != NULL) {
      cout<<ptr->data<<" --> ";
      ptr = ptr->next;
    }
    if (ptr == NULL){
      cout<<"NULL";
    }
}

void shakerSort(){
  bool swapped = true;
  struct Node *first = list.head;
  struct Node *i;
  struct Node *last = list.tail;
  struct Node *j;
  while(swapped){
    swapped = false;
    for (i = first; i->next != NULL; i=i->next){
      if ((i->data) > (i->next->data)) {
          swap(i->data, i->next->data);
          swapped = true;
      }
    }
    if(!swapped){
      break;
    }
    last = last->prev;
    for(j = last; j->prev != NULL; j=j->prev){
      if ((j->prev->data) > (j->data)) {
          swap(j->prev->data, j->data);
          swapped = true;
      }
    }
    first = first->next;
  }
}
void insert(int value){
    struct Node *start = (struct Node*) list.head;
    struct Node *item = (struct Node*) malloc(sizeof(struct Node));
    item->data = value;
    if(start == NULL){
        list.tail = item;
    }else{
        list.head->prev = item;
    }
    item->next = list.head;
    list.head = item;
}

void remove(int value){
    struct Node *start = list.head;
    if(start == NULL){
        cout<<"Список пуст"<<endl;
        return;
    }else{
        struct Node* temp = start;
        if(temp->data = value){
            list.head = temp->next;
            cout<<"Данные удалены"<<endl;
            return;
        }
        while(temp->next->data != value){
            temp = temp->next;
        }
        if(list.tail == temp->next){
            temp->next = NULL;
            list.tail = temp;
        }else{
            temp->next=temp->next->next;
        }
    }
}

void swap(int *a, int *b){
  int temp;
  temp = *a;
  *a = *b;
  *b = temp;
}

void creatList(){
  list.size = 0;
  list.head=NULL;
  list.tail=NULL;
}

int menu(){
    int choice;
    cout<<" "<<endl;
    cout<<"МЕНЮ ВЫБОРА\n";
    cout<<"1. Увидеть таблицу\n";
    cout<<"2. Сортировка\n";
    cout<<"3. Найти колличество различных элементов массива    \n";
    cout<<"4. Поиск элемента\n";
    cout<<"5. Выход"<<endl;
    cout<<">>> ";
    cin>> choice;
    return choice;
}

void search (int value){
    bool flag =0;
    struct Node *temp = list.head;
    while (temp!=NULL){
        if (temp->data == value){
            cout<<"Данные: "<< temp->data<<endl;
            flag = 1;
            break;
        }
        temp = temp->next; // переход к следующему элементу
    }
    if(flag == 0){
        cout<<"Данного элемента нет в таблице"<<endl;
    }
}

int cnt(int *arr, int s){
    int i,j,c =0;
    for(i=0;i<s;i++){
        for(j=i+1;j<s;j++){
            if(arr[i] == arr[j] && i != j) {
                break;
            }
        }
        if(j == s){
            c++;
        }
    }
    return c;
};
