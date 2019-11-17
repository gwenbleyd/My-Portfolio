#include <iostream>

using namespace std;

struct node{
	int element;
	node *left;
	node *right;
	int height;
};

typedef struct node *nodeptr;

class bstree{
	public:
		void insert(int,nodeptr &);
		void del(int, nodeptr &);
		int deletemin(nodeptr &);
		void find(int,nodeptr &);
		void preorder(nodeptr);
		int bsheight(nodeptr);
		nodeptr srl(nodeptr &);
		nodeptr drl(nodeptr &);
		nodeptr srr(nodeptr &);
		nodeptr drr(nodeptr &);
		int maxim(int,int);
    void addBT(nodeptr, int*);
    void minus(nodeptr, int);
    void task(nodeptr, nodeptr);
    int getLeafCount(nodeptr);
    float avenger(nodeptr);
};

bstree bst;

void bstree::insert(int x,nodeptr &p)
{
	if (p == NULL)
	{
		p = new node;
		p->element = x;
		p->left = p->right = NULL;
		p->height = 0;
	}
	else
	{
		if (x < p->element)
		{
			insert(x,p->left);
			if ((bsheight(p->left) - bsheight(p->right))==2 || (bsheight(p->left) - bsheight(p->right))==-2)
			{
				if (x < p->left->element)
				{
					p=srl(p);
				}
				else
				{
					p = drl(p);
				}
			}
		}
		else if (x>p->element)
		{
			insert(x,p->right);
			if ((bsheight(p->right) - bsheight(p->left))==2 || (bsheight(p->left) - bsheight(p->right))==-2)
			{
				if (x > p->right->element)
				{
					p=srr(p);
				}
				else
				{
					p = drr(p);
				}
			}
    }
		else
		{
			cout<<"Элемет существует\n"<<endl;
		}
 }
 int m,n,d;
 m=bsheight(p->left);
 n=bsheight(p->right);
 d=maxim(m,n);
 p->height = d + 1;
}

void bstree::find(int x,nodeptr &p)
{
	if (p==NULL)
	{
		cout<<"Простите, но такого элемента нет\n"<<endl;
	}
	else
	{
		if (x < p->element)
		{
			find(x,p->left);
		}
		else
		{
			if (x>p->element)
			{
				find(x,p->right);
			}
			else
			{
				cout<<"Элемент, который вы искали есть в дереве!\n"<<endl;
			}
		}
	}
}

void bstree::del(int x,nodeptr &p)
{
	nodeptr d;
	if (p==NULL)
	{
		cout<<"Простите, но такого элемента нет\n"<<endl;
	}
	else if ( x < p->element)
	{
		del(x,p->left);
	}
	else if (x > p->element)
	{
		del(x,p->right);
	}
	else if ((p->left == NULL) && (p->right == NULL))
	{
		d=p;
		free(d);
		p=NULL;
		cout<<"Элемент удален\n"<<endl;
	}
	else if (p->left == NULL)
	{
		d=p;
		free(d);
		p=p->right;
		cout<<"Элемент удален\n"<<endl;
	}
	else if (p->right == NULL)
	{
		d=p;
		p=p->left;
		free(d);
		cout<<"Элемент удален\n"<<endl;
	}
	else
	{
		p->element = deletemin(p->right);
	}
}

int bstree::deletemin(nodeptr &p)
{
	int c;
	cout<<"Выбрано удаление минимального значения\n"<<endl;
	if (p->left == NULL)
	{
		c=p->element;
		p=p->right;
		return c;
	}
	else
	{
		c=deletemin(p->left);
		return c;
	}
}

void bstree::preorder(nodeptr p)
{
	if (p!=NULL)
	{
		cout<<p->element<<"\t";
		preorder(p->left);
		preorder(p->right);
	}
}

int bstree::bsheight(nodeptr p)
{
	int t;
	if (p == NULL)
	{
		return -1;
	}
	else
	{
		t = p->height;
		return t;
	}
}

nodeptr bstree:: srl(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->left;
	p1->left = p2->right;
	p2->right = p1;
	p1->height = maxim(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = maxim(bsheight(p2->left),p1->height) + 1;
	return p2;
}

nodeptr bstree:: srr(nodeptr &p1)
{
	nodeptr p2;
	p2 = p1->right;
	p1->right = p2->left;
	p2->left = p1;
	p1->height = maxim(bsheight(p1->left),bsheight(p1->right)) + 1;
	p2->height = maxim(p1->height,bsheight(p2->right)) + 1;
	return p2;
}

nodeptr bstree:: drl(nodeptr &p1)
{
	p1->left=srr(p1->left);
	return srl(p1);
}

nodeptr bstree::drr(nodeptr &p1)
{
	p1->right = srl(p1->right);
	return srr(p1);
}

int bstree::getLeafCount(nodeptr root)
{
    if(root == NULL)
        return 0;
    if(root->left == NULL && root->right == NULL)
        return 1;
    else
        return getLeafCount(root->left)+getLeafCount(root->right);
}

void bstree::addBT(nodeptr root, int *sum)
{
    if (!root)
        return;
    if (!root->left && !root->right)
        *sum += root->element;
    addBT(root->left, sum);
    addBT(root->right, sum);
}

float bstree::avenger(nodeptr root){
  int sum = 0;
  addBT(root, &sum);
  int count = getLeafCount(root);
  float avenger = sum/count;
  return avenger;
}

void bstree::minus(nodeptr root, int avenger){
  if (!root)
      return;
  if (!root->left && !root->right){
    int x = root->element - avenger;
    root->element = x;
  }
  minus(root->left, avenger);
  minus(root->right, avenger);
}

void bstree::task(nodeptr root, nodeptr x){
  if (!root)
      return;
  if (root->element % 3 == 0){
      del(root->element, x);
  }
  task(root->left, x);
  task(root->right, x);
}

int bstree::maxim(int value1, int value2)
{
	return ((value1 > value2) ? value1 : value2);
}

int menu(){
    int choice;
    cout<<" "<<endl;
    cout<<"МЕНЮ ВЫБОРА\n";
    cout<<"1. Добавление элемента\n";
    cout<<"2. Поиск элемента\n";
    cout<<"3. Удаление элемента\n";
    cout<<"4. Показ\n";
    cout<<"5. Высота\n";
    cout<<"6. Задание\n";
    cout<<"7. Выход"<<endl;
    cout<<">>> ";
    cin>> choice;
    return choice;
}

int main(){
  nodeptr root;
  int a,choice,findele,delele;
  root = NULL;
  do {
      choice = menu();
      switch (choice) {
          case 1:
              cout<<"Введите элемент: ";
              cin>>a;
              bst.insert(a, root);
              break;
          case 2:
              cout<<"Введите элемент, который хотите найти: ";
              cin>>findele;
              if (root != NULL){
                bst.find(findele, root);
              }
              break;
          case 3:
              cout<<"Введите элемент, который хотите удалить: ";
              cin>>delele;
              bst.del(delele, root);
              cout<<root<<endl;
              cout<<&root<<endl;
              break;
          case 4:
              bst.preorder(root);
              cout<<endl;
              break;
          case 5:
              cout<<"Дерево имеет высоту; "<<bst.bsheight(root)<<endl;
              break;
          case 6:
              float avenger;
              avenger = bst.avenger(root);
              cout<<avenger<<endl;
              bst.task(root, root);
//              bst.minus(root, avenger);
              break;
          case 7:
              cout << "Выход из программы..." << endl;
              exit(EXIT_SUCCESS);
              break;
          default:
              cout<<"Ошибка!"<<endl;
              exit(EXIT_FAILURE);
      }
  } while (choice != 7);
  return 0;
}
