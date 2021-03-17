/*
    Title: item.h
    Author: Nicholas Davis
    Date: 11/24/20
    Purpose: Holds structures for geekstore
*/
#ifndef ITEM_H
#define ITEM_H


#include <string>
#include <iostream>

using namespace std;


struct Money
{
    float rawMatPrice;
    float salePrice;
    float profit;

    //Constructor
    Money(){}
    Money(float rPrice, float sPrice, float p)
    {
        rawMatPrice = rPrice;
        salePrice = sPrice;
        profit = p;
    }
};

struct Item
{
    string name;
    string description;
    Money cost;
    int numStores;
    string* stores;
    string creationDate;

    Item(){}
    Item(string n, string d, Money m, int s, string* strs, string create)
    {
        name = n;
        description = d;
        cost = m;
        numStores = s;
        stores = strs;
        creationDate = create;
    }

};

#endif