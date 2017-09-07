#ifndef LOGIC_H
#define LOGIC_H


#include <iostream>
#include "string"

using namespace std;

enum Status
{
    Notchoose,
    Chosed,
    Onqueue,
    Cooking,
    Finshed
};

class User{
public:
    User(){};
    User(string na,string num,string pw,int x=0):name(na),number(num),pwd(pw),cost(x){};
    void addCost(int x);
    void reduceCost(int x);
    friend class SuperUser;
    int showCost();
    string showName();
    friend class UQueue;
    string checknumber();
    string checkpwd();
private:
    string name;
    string number;
    string pwd;
    int cost;
};

class Dish
{
public:
    Dish(int p=0,string Name = "tudousi",Status ss = Notchoose);
    void changeStatus(Status s);
    string showStatus() const;
    string showName() const;
    int Evaluation(int sc); //评价菜品并返回评价完后平均分
    int showPrice();
private:
    Status sta;
    string DishName;
    int score;
    int price;
};

template <class T>
class linkedlist;
template <class T>
class node
{
private:
    node<T>* next;//指向后继指针的结点
public:
    T data;//数据域
    node(T d,node* next=0);//构造函数
    void insertAfter(node *p);//在本结点之后插入一个同类的结点P
    node<T>* deleteAfter();//删除本结点的后继结点，并返回其地址
    node<T>* nextNode();//获取后继结点的地址
    const node<T>* nextNode()const;//获取后继结点的地址
    friend class linkedlist<T>;//因操作需要将linkedlist<T>作为node的友元（新添）
};

template <class T>
class linkedlist
{
public:
    linkedlist();
    ~linkedlist();
    linkedlist(linkedlist<T> &L);
    linkedlist<T> &operator=(linkedlist<T> &L);
    int getSize()const;//返回链表中的元素个数
    bool isEmpty()const;//链表是否为空
    void reset(int pos=0);//初始化游标的位置（第一位数的位置设为0)
    void next();//使游标移动到下一个结点
    bool endOfList()const;//游标是否到了链尾
    int currentPosition(void);//返回游标当前的位置
    void insertFront(T item);//在表头插入结点
    void insertRear(T item);//在表尾添加结点
    //void insertAt(Dish item);//在当前结点之前插入结点
    //void insertAfter(Dish item);//在当前结点之后插入结点
    Dish deleteFront();//删除头结点
    void deleteCurrent();//删除当前结点
    const Dish&data()const;//返回对当前结点成员数据的常引用
    //清空链表：释放所有结点的内存空间。被析构函数和“operator ="调用
    void clear();
    void determine();
    int searchDish(string DishName);
    T* deletedata(string DishName);
    void Show();
    T ShowSingle(); //从头开始显示data，每显示一个后再把当前指针向后移动一位
private:
    node<T>* front,*rear;
    node<T>* prevPtr,*currPtr;
    int size;
    int position;
    //node* newNode(Dish d,node* ptrNext = NULL);
};
//node* newNode(Dish d,node* ptrNext){
//      node* temPtr = new node(d,ptrNext);
//      return temPtr;
//}
template <class T>
linkedlist<T>::linkedlist()//构造函数
{
    size=0;
    T d;
    front=rear=new node<T>(d);
    currPtr=prevPtr=front;
}

template <class T>
linkedlist<T>::~linkedlist()//析构函数
{
    clear();
    delete front;
}

class DQueue{
public:
    void insert(Dish item);
    Dish remove();
    void clear();
    void deletedata(string name);
    const Dish &peek() const ;
    bool isEmpty() const ;
    int searchDish(string name);
    void showAllDish();
    Dish showSingle();
    void reset(int n=0);
    void determine();
    int size();
private:
    linkedlist<Dish> qu;
};

class UQueue{
public:
    void insert(User item);
    Dish remove();
    void clear();
    void deletedata(string name);
    const Dish &peek() const ;
    bool isEmpty() const ;
    int searchUser(string name);
    void showAllUser();
    void reset(int n=0);
    User showSingle();
    int size();
private:
    linkedlist<User> u;
};


enum TableStatus{Empty,Full};
class Table: public DQueue{
public:
    Table(int number = 0,TableStatus r=Empty):t(r),Number(number),u(NULL){};
    void StartWorking(User* uu);
    void init(int n);
    void addDish(Dish item);
    void deleteDish(Dish item);
    void rateing();
    TableStatus showStatus();
private:
    User *u;
    TableStatus t;
    int Number;
};



class SuperUser{
public:
    UQueue u;
    DQueue menu;
private:
};


extern SuperUser ww;
extern User CurrentUser;
#endif // LOGIC_H
