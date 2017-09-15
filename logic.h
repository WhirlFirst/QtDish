#ifndef LOGIC_H
#define LOGIC_H


#include <iostream>
#include "string"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QMessageBox>
#include <QDebug>
#include <QTime>
#include <vector>
using namespace std;

static bool createConnection()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("dish.db");
    if (!db.open()) {
        return false;
        qDebug()<<"no";
    }
    QSqlQuery query;
    query.exec("create table dish (name varchar(30) , "
               "int price primary key");
    qDebug()<<"finish";
    return true;
}

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
    int showScore();
private:
    Status sta;
    string DishName;
    int score;
    int price;
};

class Chef{
public:
    void startworking(Dish* p);
    Chef(string n = "chef",string p = "1",int number =0,float score = 0,float time=0);
    void initdata(int number,int score,int time);
    float showscore();
    float showdishnumber();
    float showtime();
    string showname();
    string showpwd();
    void settablenumber(int u);
    Dish* cookingDish;
signals:
    void finishworking();
private:
    float averagetime;
    float averagescore;
    float dishnumber;
    QTime t;
    int dishtablenumber;
    string name;
    string pwd;
};



class DishMessage{
 public:
    int tablenumber;
    string dishname;
    DishMessage(int tab,string dd):tablenumber(tab),dishname(dd){}
    DishMessage(){}
};

class CustomerMessage{
public:
    string tablenumber;
    string things;
    CustomerMessage(string tab,string th):tablenumber(tab),things(th){}
    CustomerMessage(){}
};

class Waiter;

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
node<T>::node(T d,node<T>* next):next(next),data(d)
{
}
template <class T>
node< T >* node<T>::nextNode()
{
    return next;
}
template <class T>
const node<T>* node<T>::nextNode()const
{
    return next;
}
template <class T>
void node<T>::insertAfter(node<T>* p)
{
    p->next=next;
    next=p;
}
template <class T>
node<T>* node<T>::deleteAfter()
{
    node<T>* tempPtr=next;
    if(next==0)return 0;
    next=tempPtr->next;
    return tempPtr;
}

template <class T>
class linkedlist
{
public:
    linkedlist();
    ~linkedlist();
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
    T deleteFront();//删除头结点
    void deleteCurrent();//删除当前结点
    const Dish&data()const;//返回对当前结点成员数据的常引用
    //清空链表：释放所有结点的内存空间。被析构函数和“operator ="调用
    void clear();
    void determine();
    int searchDish(string DishName);
    T* deletedata(string DishName);
    void Show();
    T* ShowSingle(); //从头开始显示data，每显示一个后再把当前指针向后移动一位
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


template <class T>
int linkedlist<T>::currentPosition(void)//返回游标当前的位置
{
    node<T>* tempPtr=front->nextNode();
    position=0;
    while(tempPtr!=currPtr)
    {
        tempPtr=tempPtr->nextNode();
        position++;
    }
    return position;
}
template <class T>
int linkedlist<T>::getSize()const//返回链表中的元素个数
{
    return size;
}
template <class T>
const Dish& linkedlist<T>::data()const//返回对当前结点成员数据的常引用
{
    return currPtr->data;
}
template <class T>
void linkedlist<T>::next()//使游标移动到下一个结点
{
    prevPtr=currPtr;
    currPtr=currPtr->nextNode();
}
template <class T>
bool linkedlist<T>::endOfList()const//游标是否到了链尾
{
    if(currPtr==NULL)return true;
    else return false;
}
template <class T>
bool linkedlist<T>::isEmpty()const//链表是否为空
{
    if(front==rear)return true;
    else return false;
}
template <class T>
void linkedlist<T>::reset(int pos)//初始化游标的位置（第一位数的位置设为0)
{
    prevPtr=front;
    currPtr=front->nextNode();
    position=pos;
    for(int i=0;i<position;i++)
    {
        prevPtr=currPtr;
        currPtr=currPtr->nextNode();
    }
}
template <class T>
void linkedlist<T>::insertFront(T item)//在表头插入结点
{
    prevPtr=currPtr;
    currPtr=new node<T>(item,front->nextNode());
    front->next=currPtr;
    if(rear==front)
    {
        rear=currPtr;
    }
    size++;
}
template <class T>
void linkedlist<T>::insertRear(T item)//在表尾添加结点
{
    prevPtr=currPtr;
    currPtr=new node<T>(item,rear->nextNode());
    rear->next=currPtr;
    rear=currPtr;
    size++;
}
template <class T>
T linkedlist<T>::deleteFront()//删除头结点
{
    currPtr=front->nextNode();
    delete front;
    front=currPtr;
    size--;
    return front->data;
}
template <class T>
void linkedlist<T>::deleteCurrent()//删除当前结点
{
    prevPtr->deleteAfter();
    delete currPtr;
    currPtr=prevPtr;
    size--;
}
template <class T>
void linkedlist<T>::clear()//清空链表：释放所有结点的内存空间。被析构函数和“operator ="调用
{
    node<T>* tempPtr=front->nextNode();
    while(tempPtr!=NULL)
    {
        node<T>* tempQ=tempPtr;
        tempPtr=tempPtr->nextNode();
        delete tempQ;
        size--;
    }
    rear=front;
    currPtr=prevPtr=front;
}
template <class T>
int linkedlist<T>::searchDish(string name){
    int k=0;
    prevPtr=front;
    currPtr=front->nextNode();
    for(int i=0;i<size;i++)
    {
        if(currPtr->data.showName() == name) k++;
        prevPtr=currPtr;
        currPtr=currPtr->nextNode();
    }
    return k;
}
template <class T>
T* linkedlist<T>::deletedata(string DishName){
    prevPtr=front;
    currPtr=front->nextNode();
    for(int i=0;i<size;i++)
    {
        if(currPtr->data.showName() == DishName) {
            node<T>* tempPtr=currPtr;
            prevPtr->deleteAfter();
            delete currPtr;
            currPtr=prevPtr;
            size--;
            return &(tempPtr->data);
        }
        prevPtr=currPtr;
        currPtr=currPtr->nextNode();
    }
}

template <class T>
void linkedlist<T>::Show() {
    prevPtr=front;
    currPtr=front->nextNode();
    for (int i = 0; i < size; ++i) {
        cout<<currPtr->data.showName()<<endl;
        prevPtr=currPtr;
        currPtr=currPtr->nextNode();
    }
}

template <class T>
void linkedlist<T>::determine(){
    prevPtr = front;
    currPtr = front->nextNode();
    for (int i = 0; i < size; ++i) {
        currPtr->data.changeStatus(Onqueue);
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
    }
}


template <class T>
T* linkedlist<T>::ShowSingle() {
    prevPtr = currPtr;
    currPtr = currPtr->nextNode();
    return &(prevPtr->data);
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
    Dish* showSingle();
    void reset(int n=0);
    void determine();
    int size();
    void deletecurrent();
    int currentposition();
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
    void deletecurrent();
    int currentposition();
    User* showSingle();
    int size();
private:
    linkedlist<User> u;
};


class Waiter{
public:
    Waiter(string n = "waiter",string p ="1",float s=0,int ac=0):score(s),name(n),pwd(p),acount(ac){}
    void rating(int sc);
    string showName();
    string showPwd();
    float showscore();
    float showtime();
    linkedlist<DishMessage> dm;
    linkedlist<CustomerMessage> cm;
    int acount;
private:
    float score;
    string name;
    string pwd;
};


class Manager{
public:
    Manager(){}
    linkedlist<Chef> cheflist;
};

enum TableStatus{Empty,Full};



class Table: public DQueue{
public:
    Table(int number = 0,TableStatus r=Empty):t(r),Number(number),u(NULL),surveice(0){}
    void StartWorking(User* uu);
    void init(int n);
    void addDish(Dish item);
    void deleteDish(Dish item);
    void rateing();
    void setwaiter(Waiter* f);
    string showNumber();
    string showStatus();
    Waiter* surveice;
private:
    User *u;
    TableStatus t;
    int Number;
};


//class CQueue {
//public:
//    void insert();
//private:
//    linkedlist<Chef> s;
//};

class SuperUser{
public:
    UQueue u;
    DQueue menu;
   //linkedlist<Chef> chef;
private:
};




extern SuperUser ww;
extern User* CurrentUser;
extern Table t[30];
extern Table* CurrentTable;
extern Chef* CurrentChef;
extern Waiter* CurrentWaiter;
extern Manager* CurrentManager;
#endif // LOGIC_H
