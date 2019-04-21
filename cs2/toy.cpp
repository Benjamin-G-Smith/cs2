// implementation of the toy class

#include "toy.h"

Toy::Toy()
{
  id = "";
  name = "";
  stock = 0;
  cost = 0.0;
}
Toy::Toy(const Toy& T)
{
  id = T.id;
  name = T.name;
  cost = T.cost;
  stock = T.stock;
}
Toy& Toy::operator=(const Toy& rhs)
{
    id = rhs.id;
    name = rhs.name;
    cost = rhs.cost;
    stock = rhs.stock;
  return *this;
}
void Toy::increaseStock(int v)
{
  stock += v;
}
bool Toy::sellOne()
{
  if(stock==0){
    return false;
  }
  stock--;
  return true;
}
void Toy::setCost(double value)
{
  cost = value;
}
void Toy::setID(string data)
{
  id = data;
}
void Toy::setName(string n)
{
  name = n;
}
int Toy::getSock()
{
  return stock;
}
double Toy::getCost()
{
  return cost;
}
string Toy::getID()
{
  return id;
}
string Toy::getName()
{
  return name;
}
