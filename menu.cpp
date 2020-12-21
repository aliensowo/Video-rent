#include "menu.hpp"
#include "rwfunc.hpp"

using namespace std;

void Menu(VrentalStruct*Vrental,int &NC,bool &Open){
    int n=0;
    while(1){
        system("cls");
        cout<<"1. Открыть файл"<<endl;
        cout<<"2. Сохранить файл"<<endl;
        cout<<"3. Создать элемент"<<endl;
        cout<<"4. Удалить элемент"<<endl;
        cout<<"5. Вывести на экран"<<endl;
        cout<<"6. О программе"<<endl;
        cout<<"7. Выход"<<endl;
        cout<<"\nВыберите пункт меню: ";
        cin>>n;
        switch(n){
            case 1: Read(Vrental,NC,Open); break;
            case 2: Write(Vrental,NC,Open); break;
            case 3: Add(Vrental,NC,Open); break;
            case 4: Delete(Vrental,NC,Open); break;
            case 5: Display(Vrental,NC,Open); break;
            case 6: About(); break;
            case 7: exit(0); break;
            default: cout<<"\n Данный пункт меню отсутствует\n "<<endl; break;
        }
        system("pause");
    }
}

void Display(VrentalStruct*Vrental,int &NC,bool &Open){
    if(!Open){
        cerr << "Error: Файл еще не был открыт!" << endl;
        return;
    }
    system("cls");
    for(int i=0;i<NC;i++){
        cout<<Vrental[i].ID<<"\t"<<Vrental[i].FilmNumber<<"\t"<<Vrental[i].FilmName<<"\t"<<Vrental[i].FilmYear<<"\t"<<Vrental[i].Type<<"\t"<<Vrental[i].Availability<<"\t"<<Vrental[i].Price<<"\t"<<endl;
    }
}

void About(){
    system("cls");
    cout<<" Данную программу выполнил студент ИЭУИС 2-4\n Калинкин Никита\n\n"<<endl;
}
