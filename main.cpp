#include <iostream>
#include "Human.h"
using namespace std;


int main() {
    Human *a = new Human("Max", "English", "USA");
    Human b("Gleb","Russian","Russia");
    Italian c("Adriano","Italian","Italy");
    Italian *d = new Italian("Max", "English", "Italy");

    b.say(); // родительский класс вызывает свой метод say,
    c.say(); // а дочерний свой
    c.Human::say(); // но мы можем его хорошо попросить :-)

    Human::Country(a);
    Human::Country(d); // ожидался родитель, а передали ребёнка


    cout << endl << b.getName() << endl;
    cout << c.getName() << endl; // можем вызывать родительский геттер


    c.printMoney(); // money_ это protected поле класса Human, но этот класс не обладает методом printMoney


    b.setStateScret("admin 123345");
    // StateScret это protected поле Human и мы не можем обратиться к нему в классе Italian
    cout << endl  << b.getStateScret() << endl;

    cout << b.country_ << "   " << c.country_ << endl ;
    // можем оращаться к public полю через родительский и дочерний класс

    //_________________________________________________________________________________________________________________

    Worker q(1);
    Programmer w(2);
    WebProgrammer e(3);
    BackendProgrammer r(4);
    FrontendProgrammer t(5);
    FullStackProgrammer y;

    cout << endl << "Я Worker: " << endl;
    q.job();

    cout << endl << "Я Programmer: " << endl;
    w.job();
    w.Worker::job();

    cout << endl << "Я WebProgrammer: " << endl;
    e.Worker::job();
    e.Programmer::job();
    e.MakeGOOGLE();

    cout << endl << "Я BackendProgrammer: " << endl;
    r.Worker::job();
    r.Programmer::job();
    r.MakeGOOGLE();
    r.job();

    cout << endl << "Я FrontendProgrammer: " << endl;
    t.Worker::job();
    t.Programmer::job();
    t.MakeGOOGLE();
    t.job();


    cout << endl << "Я FullStackProgrammer: " << endl;
    y.BackendProgrammer::job();
    y.FrontendProgrammer::job();
    y.job();
    cout << "Подметать улицы, писать программы и делать гугл не хочу";
    return 0;
}
