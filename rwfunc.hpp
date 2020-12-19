#pragma once
#include <iostream>

using namespace std;

struct VrentalStruct{
    int ID;
    int FilmNumber;
    string FilmName;
    int FilmYear;
    string Type;
    bool Availability;
    float Price;
};

void Read(VrentalStruct*,int&,bool&);

void Write(VrentalStruct*,int&,bool&);

void Add(VrentalStruct*,int&,bool&);

void Delete(VrentalStruct*,int&,bool&);

void SToD(string,VrentalStruct&);
