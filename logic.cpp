#include "logic.h"

void User::addCost(int x) {
    cost = cost+x;
}
void User::reduceCost(int x) {
    cost = cost-x;
}
int User::showCost() {
    return cost;
}
string User::showName(){
    return name;
}

string User::checknumber(){
    return number;
}

string User::checkpwd(){
    return pwd;
}

int Dish::showPrice() {
    return price;
}
Dish::Dish(int p,string Name,Status ss):sta(ss),DishName(Name),score(0),price(p){
}
void Dish::changeStatus(Status s){
    sta = s;
}
string Dish::showName() const{
    return DishName;
}
string Dish::showStatus() const{
    switch (sta)
    {
        case 0:
            return "Notchoose";
            break;
        case 1:
            return "Chosed";
            break;
        case 2:
            return "Onqueue";
            break;
        case 3:
            return "Cooking";
            break;
        case 4:
            return "Finshed";
            break;
        default:
            return "error";
            break;
    }
}
int Dish::Evaluation(int sc){
    if(score==0) score= sc;
    else score = (score+ sc)/2;
    return score;
}


template <class T>
node<T>::node(T d,node<T>* next):next(next),data(d)
{
}
template <class T>
node<T>* node<T>::nextNode()
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
Dish linkedlist<T>::deleteFront()//删除头结点
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
    node<T>* tempPtr=currPtr;
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
T linkedlist<T>::ShowSingle() {
    prevPtr = currPtr;
    currPtr = currPtr->nextNode();
    return prevPtr->data;
}

void Table::addDish(Dish item) {
    item.changeStatus(Chosed);
    insert(item);
    u->addCost(item.showPrice());
}
void Table::StartWorking(User* uu){
    u = uu;
    t = Full;
}
void Table::init(int n){
    Number = n;
}
void Table::deleteDish(Dish item) {
    deletedata(item.showName());
    u->reduceCost(item.showPrice());
}
void Table::rateing() {
    showAllDish();
}

string Table::showNumber(){
    return to_string(Number);
}

TableStatus Table::showStatus() {
    return t ;
}

void UQueue::insert(User item){
    u.insertRear(item);
}
void UQueue::clear(){
    u.clear();
}
void UQueue::deletedata(string name){
    u.deletedata(name);
}
void UQueue::showAllUser(){
    u.Show();
}
void UQueue::reset(int n) {
    u.reset(n);
}

User UQueue::showSingle() {
    return u.ShowSingle();
}


bool UQueue::isEmpty() const {
    return u.isEmpty();
}

int UQueue::size(){
    return u.getSize();
}

void DQueue::insert(Dish item) {
    qu.insertRear(item);
    //item.changeStatus(Onqueue);
    qu.reset();
}
int DQueue::searchDish(string name){
    return qu.searchDish(name);
}
void DQueue::deletedata(string name){
    Dish* de = qu.deletedata(name);
    de->changeStatus(Notchoose);
}
void DQueue::clear() {
    qu.clear();
}
void DQueue::showAllDish() {
    qu.Show();
}

void DQueue::determine() {
    qu.determine();
}

void DQueue::reset(int n) {
    qu.reset(n);
}

Dish DQueue::showSingle() {
    return qu.ShowSingle();
}

int DQueue::size() {
    return qu.getSize();
}
SuperUser ww;
User CurrentUser;
Table t[50];
