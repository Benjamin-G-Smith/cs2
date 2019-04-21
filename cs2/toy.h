// The toy class to be implemented

#include<iostream>

using namespace std;


class Toy{
  public:
    Toy();
    Toy(const Toy& T);
    Toy& operator=(const Toy& rhs);
    void increaseStock(int value);
    bool sellOne();
    void setCost(double value);
    void setID(string ID);
    void setName(string name);
    int getSock();
    double getCost();
    string getID();
    string getName();
  private:
    string id;
    string name;
    double cost;
    int stock;
};
