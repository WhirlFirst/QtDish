#include "logic.h"
#include "QTime"
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

int Dish::showScore(){
    return score;
}

Chef::Chef(string n, string p, int number, float score, float time){
    name =n;
    pwd = p;
    averagetime = time;
    averagescore = score;
    dishnumber = number;
    t.start();
}

void Chef::initdata(int number, int score, int time){
    averagetime = time;
    averagescore = score;
    dishnumber = number;
    t.start();
}

float Chef::showdishnumber(){

    return dishnumber;
}

float Chef::showscore(){
    return averagescore;
}

float Chef::showtime(){
    return averagetime;
}

void Chef::startworking(Dish* p){
    cookingDish =p;
    dishnumber++;
    averagescore = (averagescore+cookingDish->showScore())/2;
    cookingDish->changeStatus(Cooking);
    t.restart();
}

void Chef::finishworking(){
   float s = t.elapsed()/1000;
   if(averagetime =0) averagetime =s;
   else averagetime = (s+averagetime)/2;
   cookingDish->changeStatus(Finshed);
}

string Chef::showname(){
    return name;
}

string Chef::showpwd(){
    return pwd;
}

void Chef::settablenumber(int u){
    dishtablenumber = u;
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

string Table::showStatus() {
    switch (t) {
    case Empty:
        return "Empty";
        break;
    default:
        return "Full";
        break;
    }
}

void Table::setwaiter(Waiter* p){
    surveice = p;
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

User* UQueue::showSingle() {
    return u.ShowSingle();
}


bool UQueue::isEmpty() const {
    return u.isEmpty();
}

int UQueue::size(){
    return u.getSize();
}

void UQueue::deletecurrent(){
    u.deleteCurrent();
}

int UQueue::currentposition(){
    return u.currentPosition();
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

Dish* DQueue::showSingle() {
    return qu.ShowSingle();
}

int DQueue::size() {
    return qu.getSize();
}

void DQueue::deletecurrent(){
    qu.deleteCurrent();
}

int DQueue::currentposition(){
    return qu.currentPosition();
}


void Waiter::rating(int sc){
    if(score ==0) score =sc;
    else score = (sc+score)/2;
}


Chef* CurrentChef;
SuperUser ww;
User* CurrentUser;
Table t[30];
Table* CurrentTable = 0;
Waiter* CurrentWaiter;
