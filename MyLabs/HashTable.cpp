#include <iostream>
#include <string>

using namespace std;

const int MAX_NUM = 1500;
const int M = 6;

struct Node{
    string data; //данные в формате "ББЦЦЦБ"
    struct Node *next; //указатель на следующий элемент
};

struct List{
    struct Node *head; //указатель на первый узел списка
    struct Node *tail; //указатель на последний узел списка
};

struct List hashTable[MAX_NUM];

void init();
void display();
void insert(string value);
void remote(string value);
void search(string value);
int hashFunck(string value);
int find(struct Node *list, string value);
int menu();

int main(){
    init();
    int choice;
    string data[MAX_NUM];
    string delEl;
    string findEl;
    string addEl;
    char key[M];
    int i;
    for (i = 0; i < MAX_NUM; i++) {
        for (int j = 0; j < M; ++j) {
            key[j] = j == 1 || j == 2 || j == 3 ? '0' + rand() % ('9' - '0') : 'A' + rand() % ('A' - 'Z');
            data[i] += key[j];
        }
    }
    for (i=0; i<MAX_NUM; i++){
        insert(data[i]);
    }
    do {
        choice = menu();
        switch (choice) {
            case 1:
                display();
                break;
            case 2:
                cout<<"Какой эдемент хоитите добавить?"<<endl;
                cout<<">>> ";
                cin>>addEl;
                insert(addEl);
                break;
            case 3:
                cout<<"Что хотите удалить?"<<endl;
                cout<<">>> ";
                cin>>delEl;
                remote(delEl);
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
}

// Функция удаления элемента из таблицы
void remote(string value){
    int hashKey = hashFunck(value);
    struct Node *list = (struct Node*)hashTable[hashKey].head;
    if (list == NULL){
        cout<<"Таких данных нет"<<endl;
        return;
    }else{
        int find_index = find(list, value);
        if(find_index == -1){
            cout<<"Таких данных нет"<<endl;
            return;
        }else{
            struct Node *temp = list;
            if(temp->data == value){
                hashTable[hashKey].head = temp->next;
                cout<<"Данные удалены"<<endl;
                return;
            }
            while(temp->next->data != value){
                temp=temp->next;
            }
            if(hashTable[hashKey].tail == temp->next){
                temp->next = NULL;
                hashTable[hashKey].tail = temp;
            }else{
                temp->next=temp->next->next;
            }
            cout<<"Данные удалены"<<endl;
        }
    }
}

// Вывод хэш таблицы
void display(){
    int i;
    for (i = 0; i < MAX_NUM; i++){
        struct Node *temp = hashTable[i].head;
        if (temp == NULL){
            cout<<"Цепочка №["<<i<<"] не имеет элементов"<<endl;
        }
        else{
            cout<<"Цепочка №["<<i<<"] содержит элементы"<<endl;
            while (temp != NULL) {
                cout<<"Данные: "<<temp->data<<endl;
                temp = temp->next;
            }
            cout<<endl;
        }
    }
}

// Инициализация массива односвязнаых списков
void init(){
    int i;
    for (i=0;i<MAX_NUM;i++){
        hashTable[i].head = NULL;
        hashTable[i].tail = NULL;
    }
}

// Поиск на присутствие
int find(struct Node *list, string value){
    int retval = 0;
    struct Node *temp = list;
    while (temp != NULL){
        if (temp->data == value){
            return retval;
        }
        temp = temp->next;
        retval++;
    }
    return -1;
}

// Функция добавления элемента в таблицу
void insert(string value){
    int hashKey = hashFunck(value);
    struct Node *list = (struct Node*) hashTable[hashKey].head;
    struct Node *item = (struct Node*) malloc(sizeof(struct Node));
    item->data = value;
    item->next = NULL;
    if(list == NULL){
        hashTable[hashKey].head = item;
        hashTable[hashKey].tail = item;
    }else{
        hashTable[hashKey].tail->next = item;
        hashTable[hashKey].tail = item;
    }
}

// Хэширующая функция, основанная на умножение и деление рядом стоящих элементов
int hashFunck(string value){
    int mult = 0;
    int division = 0;
    for (int i = 1; i < 6; i++){
        char x = value.at(i-1);
        char y = value.at(i);
        mult += int(x) * int(y);
        division += int(x)/int{y};
    }
    int hashKey = (mult+division) % MAX_NUM;
    return  hashKey;
}

// Функция меню, предназначенная для выбора действия
int menu()
{
    int choice;
    cout<<" "<<endl;
    cout<<"МЕНЮ ВЫБОРА\n";
    cout<<"1. Увидеть таблицу\n";
    cout<<"2. Добавление нового элемента в таблицу\n";
    cout<<"3. Удаление элемента\n";
    cout<<"4. Поиск элемента\n";
    cout<<"5. Выход"<<endl;
    cout<<">>> ";
    cin>> choice;
    return choice;
}

//Функция поиска элемента в хеш-таблицы
void search (string value){
    bool flag =0;
    int hashKey = hashFunck(value);
    struct Node *temp = hashTable[hashKey].head;
    while (temp!=NULL){
        if (temp->data == value){
            cout<<"Номер в таблице: "<<hashKey<<"\n"<<"Данные: "<< temp->data<<endl;
            flag = 1;
            break;
        }
        temp = temp->next; // переход к следующему элементу
    }
    if(flag == 0){
        cout<<"Данного элемента нет в таблице"<<endl;
    }
}
