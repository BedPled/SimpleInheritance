//
// Created by BedTed on 3/23/2021.
//

#ifndef SIMPLE_INHERITANCE_HUMAN_H
#define SIMPLE_INHERITANCE_HUMAN_H
using namespace std;

class Human {
private:
    string state_secret_;

protected:
    int money_;
public:
    string name_;

    const string &getName() const {
        return name_;
    }

    void setName(const string &name) {
        name_ = name;
    }

    const string &getNativeLanguage() const {
        return native_language_;
    }

    void setNativeLanguage(const string &nativeLanguage) {
        native_language_ = nativeLanguage;
    }

    const string &getCountry() const {
        return country_;
    }

    void setCountry(const string &country) {
        country_ = country;
    }

    string native_language_;
    string country_;

    Human () {
        name_ = "";
        native_language_ = "";
        country_ = "";
        state_secret_ = "";
        money_ = 0;
    }

    Human (string name_, string native_language_, string country_) {
        this->name_ = name_;
        this->native_language_ = country_;
        this->country_ = country_;
        state_secret_ = "";
        money_ = 0;
    }

    void say () {
        cout << "Hello, I`m " << name_ << endl;
    }

    string getStateScret () {
        return state_secret_;
    }

    void setStateScret (string state_secret_) {
        this->state_secret_ = state_secret_;
    }

    static void Country (Human *a) {
        cout << endl << a->country_ << endl;
    }

};


class Italian : public Human {
public:
    Italian (string name_, string native_language_, string country_) {
        this->name_ = name_;
        this->native_language_ = country_;
        this->country_ = country_;
        money_ = 100;
    }

    Italian() {}

    void say() {
        cout << "Ciao, I`m " << name_ << " from " << country_ << " where to speak " << native_language_ << endl;
        // можем обращаться к полям родительского класса
    }
    void printMoney () {
        cout << endl << money_ << endl;
    }


};


class Worker {
public:
    unsigned int salary_;

    Worker (unsigned int salary) {
        if (salary >= 0) {
            salary_ = salary;
        } else {
            salary_ = 0;
        }
    }

    Worker() {
        salary_ = 0;
    }

    unsigned int getSalary() const {
        return salary_;
    }

    void setSalary(unsigned int salary) {
        if (salary >= 0) {
            salary_ = salary;
        } else {
            salary_ = 0;
        }
    }

    void job () {
        cout << "Подметаю улицы" << endl;
    }
};

class Programmer : public Worker {
public:
    string programming_language_;

    Programmer(unsigned int salary) : Worker(salary) {
        programming_language_ = "Какой-то";
    }

    Programmer() {
        programming_language_ = "";
        salary_ = 0;
    }

    const string &getProgrammingLanguage() const {
        return programming_language_;
    }

    void setProgrammingLanguage(const string &programmingLanguage) {
        programming_language_ = programmingLanguage;
    }

    void job () {
        cout << "Пишу программы" << endl;
    }

};

class WebProgrammer : public Programmer {
public:

    WebProgrammer(unsigned int salary) : Programmer(salary) {
        programming_language_ = "Какой-то";
    }

    WebProgrammer() {
        programming_language_ = "";
        salary_ = 0;
    }

    void MakeGOOGLE () {
        cout << "Сделай мне гугл за " << salary_ << " деревянных, на языке " << programming_language_ << endl;
    }
};

class BackendProgrammer : public WebProgrammer {
public:
    bool something1;

    BackendProgrammer(unsigned int salary) : WebProgrammer(salary) {
        programming_language_ = "PHP";
        something1 = true;
    }

    BackendProgrammer() {
        programming_language_ = "";
        salary_ = 0;
        something1 = true;
    }

    void job () {
        cout << "Работаю с серверами" << endl;
    }
};

class FrontendProgrammer : public WebProgrammer {
public:
    bool something2;
    FrontendProgrammer(unsigned int salary) : WebProgrammer(salary) {
        programming_language_ = "JavaScript";
        something2 = false;
    }

    FrontendProgrammer() {
        programming_language_ = "";
        salary_ = 0;
        something2 = false;
    }

    void job () {
        cout << "Делаю красиво" << endl;
    }
};

class FullStackProgrammer : public BackendProgrammer, public FrontendProgrammer {
public:

    // при генерации конструктора хочет получать две зарплаты :-) (много хочет)

    FullStackProgrammer(){  // занаследовало поля созданые в родителях, но не наследует поля других предков
        something1 = true;
        something2 = false;
    }

    void job () {
        cout << "Страдаю" << endl;
    }
};


#endif //SIMPLE_INHERITANCE_HUMAN_H
