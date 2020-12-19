#include "rwfunc.hpp"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Read(VrentalStruct* Vrental,int &NC,bool &Open){
    fstream in("Vrental.db", ios_base::in);
    if(!in.is_open()) {
        cerr << "Error: ‘айл не открыт!" << endl;
        return;
    }
    if(Open){
        cerr << "Error: ‘айл уже был открыт!" << endl;
        in.close();
        return;
    }

    string str;
    NC=0;
    while(!in.eof()){
        getline(in, str);
        if(str.empty())continue;
        VrentalStruct New;
        SToD(str,New);
        Vrental[NC]=New;
        NC++;
    }
Open=true;
    in.close();
    system("cls");
    cout<<"\n‘айл успешно открыт!\n"<< endl;
}

void Write(VrentalStruct*Vrental,int &NC,bool & Open){
    fstream out("Vrental.db",ios_base::out);
    if(!out.is_open()) {
        cerr << "Error: ‘айл не открыт!" << endl;
        return;
    }
    if(!Open){
        cerr << "Error: ‘айл еще не был открыт!" << endl;
        return;
    }
    for(int i=0;i<NC;i++){
        out<<Vrental[i].ID<<";"<<Vrental[i].FilmNumber<<";"<<Vrental[i].FilmName<<";"<<Vrental[i].FilmYear<<";"<<Vrental[i].Type<<";"<<Vrental[i].Availability<<";"<<Vrental[i].Price<<";"<<endl;
    }
    out.close();
    system("cls");
    cout<<"\n‘айл успешно записан!\n"<< endl;
}

void Add(VrentalStruct*Vrental,int& NC,bool& Open){
    if(!Open){
        cerr << "Error: ‘айл еще не был открыт!" << endl;
        return;
    }
    system("cls");
    VrentalStruct New;
    cout<<"\nƒобавление элемента\n¬ведите:"<<endl;
    cout<<"\tID: ";cin>>New.ID;
    cout<<"\tFilmNumber: ";cin>>New.FilmNumber;
    cout<<"\tFilmName: ";_flushall(); getline(cin,New.FilmName);
    cout<<"\tFilmYear: ";cin>>New.FilmYear;
    cout<<"\tType: ";_flushall(); getline(cin,New.Type);
    cout<<"\tAvailability: ";cin>>New.Availability;
    cout<<"\tPrice: ";cin>>New.Price;
    Vrental[NC]=New;
    NC++;
    cout<<"\n Ёлемент добавлен.\n"<<endl;
}

void Delete(VrentalStruct*Vrental,int& NC,bool& Open){
    if(!Open){
        cerr << "Error:  ‘айл еще не был открыт!" << endl;
        return;
    }
    system("cls");

    int DelNom=-1;
    cout<<"\n”далелние элемента\n¬ведите Id удал€емого елемента:";
    cin>>DelNom;
    for(int i=0;i<NC;i++){
        if(Vrental[i].ID==DelNom){
            DelNom=i;
            break;
        }
    }
    if(DelNom!=-1){
        for(int i=DelNom;i<NC-1;i++){
            Vrental[i]=Vrental[i+1];
        }
        NC--;
        cout<<"\nЁлемент удален.\n"<<endl;
    }else{
        cout<<"\nЁлемент с заданным ID не найден.\n"<<endl;
    }
}

void SToD(string str,VrentalStruct&New){
    int indexN,indexL=0;
    string t1,t2,t3,t4,t5,t6,t7;
    indexN = str.find(';',indexL);
    for(int i=indexL;i<indexN;i++)t1+=str[i];
    indexL=indexN+1;
    indexN = str.find(';',indexL);
    for(int i=indexL;i<indexN;i++)t2+=str[i];
    indexL=indexN+1;
    indexN = str.find(';',indexL);
    for(int i=indexL;i<indexN;i++)t3+=str[i];
    indexL=indexN+1;
    indexN = str.find(';',indexL);
    for(int i=indexL;i<indexN;i++)t4+=str[i];
    indexL=indexN+1;
    indexN = str.find(';',indexL);
    for(int i=indexL;i<indexN;i++)t5+=str[i];
    indexL=indexN+1;
    indexN = str.find(';',indexL);
    for(int i=indexL;i<indexN;i++)t6+=str[i];
    indexL=indexN+1;
    indexN = str.find(';',indexL);
    for(int i=indexL;i<indexN;i++)t7+=str[i];
    New.ID = stoi(t1);
    New.FilmNumber = stoi(t2);
    New.FilmName = t3;
    New.FilmYear = stoi(t4);
    New.Type = t5;
    New.Availability = stoi(t6);
    New.Price = stof(t7);
}
