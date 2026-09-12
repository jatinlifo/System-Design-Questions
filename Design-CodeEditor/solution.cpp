#include <iostream>
#include <string>
#include <unordered_map>


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

    virtual string saveCode(int userId, string code) = 0;
    virtual string getCode(int userId) = 0;

    ~SaveDataBase() {}

};

class SaveSQL : public SaveDataBase {
private:

    unordered_map<int, string> database;
public:

    string saveCode(int userId, string code) override {

        if (code.empty()) {
            return "Code can't be empty";
        }

        database[userId] = code;

        return "Code save successfully";
    }

    string getCode(int userId) override {

        if (!database.count(userId)) {
            return "We can't find any code for this id";
        }

        return database[userId];
    }
};

class SaveMongoDB : public SaveDataBase {
private:

    unordered_map<int, string> database;

public:

    string saveCode(int userId, string code) override {

        if (code.empty()) {
            return "Code can't be empty";
        }

        database[userId] = code;

        return "Code save successfully";

    }

    string getCode(int userId) override {

        if (!database.count(userId)) {
            return "We can't find any code for this ID";
        }

        return database[userId];
    }
};

int main () {

    // new we try to manaully in future we will think to implement in real world that time we
    // use User class and create real user

    RunCodeServiceOne runCodeServiceOne;
    SaveSQL saveSQL;
    string code = R"(let arr[4] = {1, 2, 3, 4} 
                    for (let i = 0; i < 4; i++) 
                    console.log(arr[i]))";

   
   cout << "Start...................................................................................." << endl;
   cout << "Output: " <<  runCodeServiceOne.run(code) << endl;
   cout << "Save Code: " << saveSQL.saveCode(1, code) << endl;
   cout << "Get Code: " << saveSQL.getCode(1) << endl;


   cout << "Second Service: " << "=====================================================================" << endl;


   RunCodeServiceTwo runCodeServiceTwo;
   SaveMongoDB saveMongoDB;
   string code2 = R"(console.log("Hello world"))";

   cout << "Output: " << runCodeServiceTwo.run(code) << endl;
   cout << "Save Code: " << saveMongoDB.saveCode(1, code2) << endl;
   cout << "Get Code: " << saveMongoDB.getCode(1) << endl;

   cout << "End......................................................................................" << endl;


    return 0;
}