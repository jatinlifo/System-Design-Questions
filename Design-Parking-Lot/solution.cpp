#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;


class Vechials {
public:

    virtual bool isAvailable() = 0;
    virtual void parkVechial(int numberPlate, string driverName) = 0;
    virtual bool hashVechial(int numberPlate) = 0;
    virtual bool correctAmount(int userAmount) = 0;
    virtual int calculateAmount(int userAmont) = 0;
    virtual void exitVechial(int numberPlate) = 0;

    ~Vechials() {}

};

class TwoVechilarVechial : public Vechials {
private:

    int capacity;
    unordered_map<int, string> parking;
    int fees;


public:

    TwoVechilarVechial(int capacity, int fees) {
        this->capacity = capacity;
        this->fees = fees;
    }

    bool isAvailable() override {

        return parking.size() < capacity;
    }

    void parkVechial(int numberPlate, string driverName) override {

        parking[numberPlate] = driverName;
    }

    bool hashVechial(int numberPlate) override {

        return parking.count(numberPlate);
    }

    bool correctAmount(int userAmount) override {

        return userAmount >= fees;
    }

    int calculateAmount(int userAmount) override {

        return userAmount - fees;
    }

    void exitVechial(int numberPlate) override {

        parking.erase(numberPlate);
    }

};

class FourVechilarVechial : public Vechials {

private:

    int capacity;
    int fees;
    unordered_map<int, string> parking;
    
    public:
    
    
    FourVechilarVechial (int capacity, int fees) {

        this->capacity = capacity;
        this->fees = fees;
    }

     bool isAvailable() override {

        return parking.size() < capacity;
    }

    void parkVechial(int numberPlate, string driverName) override {

        parking[numberPlate] = driverName;
    }

    bool hashVechial(int numberPlate) override {

        return parking.count(numberPlate);
    }

    bool correctAmount(int userAmount) override {

        return userAmount >= fees;
    }

    int calculateAmount(int userAmount) override {

        return userAmount - fees;
    }

    void exitVechial(int numberPlate) override {

        parking.erase(numberPlate);
    }

    
};


int main () {

    TwoVechilarVechial twoVechilarVechail(3, 30);

    vector<pair<int, string>> vechails = {
    {12, "Ramesh"},
    {13, "Rahul"},
    {14, "Amit"},
    {15, "Tarun"},
    {16, "Bablu"}
};

    for (int i = 0; i < vechails.size(); ++i) {

        int numberPlate = vechails[i].first;
        string driverName =  vechails[i].second;

        if (twoVechilarVechail.isAvailable()) {
            twoVechilarVechail.parkVechial(numberPlate, driverName);
            cout << i+1 << ": " << "Parking successfully" << "----" << "Number plate : " << numberPlate << "   driverName : " << driverName;
            cout << endl;
        } else {
            cout << i+1 << ": " << "Parking Failed not empty slot" << "----" << "Number plate : " << numberPlate << "   driverName : " << driverName;
            cout << endl;
        }
    }

    // if now exist
    if (twoVechilarVechail.hashVechial(12) && twoVechilarVechail.correctAmount(40)) {

        int returnMoney = twoVechilarVechail.calculateAmount(40);

        cout << "User Return Money" << ": " << returnMoney << endl;
        twoVechilarVechail.exitVechial(12);
        cout << "Exit the user" << endl;
    } else {

        cout << "Please enter correct numberplate and correct amount";
    }

      // if now exist
    if (twoVechilarVechail.hashVechial(13) && twoVechilarVechail.correctAmount(10)) {

        int returnMoney = twoVechilarVechail.calculateAmount(10);

        cout << "User Return Money...." << " : " << returnMoney << endl;
        twoVechilarVechail.exitVechial(12);
        cout << "Exit the user " << endl;
    } else {

        cout << "Please enter correct numberplate and correct amount" << endl;
    }

    FourVechilarVechial fourVechilarVechial(3, 50);

    for (int i = 0; i < vechails.size(); ++i) {

        int numberPlate = vechails[i].first;
        string driverName =  vechails[i].second;

         if (fourVechilarVechial.isAvailable()) {
            fourVechilarVechial.parkVechial(numberPlate, driverName);
            cout << i+1 << ": " << "Parking successfully" << "----" << "Number plate : " << numberPlate << " driverName : " << driverName;
            cout << endl;
        } else {
            cout << i+1 << ": " << "Parking Failed not empty slot" << "----" << "Number plate : " << numberPlate << "   driverName : " << driverName;
            cout << endl;
        }
    }

      // if now exist
    if (fourVechilarVechial.hashVechial(12) && fourVechilarVechial.correctAmount(40)) {

        int returnMoney = fourVechilarVechial.calculateAmount(40);

        cout << "User Return Money" << ": " << returnMoney << endl;
        fourVechilarVechial.exitVechial(12);
        cout << "Exit the user" << endl;
    } else {

        cout << "Please enter correct numberplate and correct amount";
        cout << endl;
    }
    return 0;
}