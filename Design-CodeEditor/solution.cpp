#include <iostream>
#include <string>


using namespace std;


class User {

    string name;
    string email;
    string password;

    User(string name, string email, string password) {

        this->name = name;
        this->email = email;
        this->password = password;
    }
};


class RunCode {
public:

    virtual string run(string code) = 0;

    ~RunCode() {}
};

class RunCodeServiceOne : public RunCode {
public:

    string run(string code) override {

        if (code.empty()) {
            return "Code can not be empty";
        }

        return "Run Successfully";
    }
};

class RunCodeServiceTwo : public RunCode {
public:

    string run(string code) override {

        if (code.empty()) {
            return "Code can not be empty";
        }

        return "Run Successfully";
    }
};

class SaveDataBase {
public:

    virtual string saveCode(string code) = 0;

    ~SaveDataBase() {}

};

class SaveSQL : public SaveDataBase {
public:

    string saveCode(string code) override {}
};

int main () {

    return 0;
}