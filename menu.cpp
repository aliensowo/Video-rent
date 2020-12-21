#include "menu.hpp"
#include "rwfunc.hpp"

using namespace std;

void Menu(VrentalStruct*Vrental,int &NC,bool &Open){
    int n=0;
    while(1){
        system("cls");
        cout<<"1. ������� ����"<<endl;
        cout<<"2. ��������� ����"<<endl;
        cout<<"3. ������� �������"<<endl;
        cout<<"4. ������� �������"<<endl;
        cout<<"5. ������� �� �����"<<endl;
        cout<<"6. � ���������"<<endl;
        cout<<"7. �����"<<endl;
        cout<<"\n�������� ����� ����: ";
        cin>>n;
        switch(n){
            case 1: Read(Vrental,NC,Open); break;
            case 2: Write(Vrental,NC,Open); break;
            case 3: Add(Vrental,NC,Open); break;
            case 4: Delete(Vrental,NC,Open); break;
            case 5: Display(Vrental,NC,Open); break;
            case 6: About(); break;
            case 7: exit(0); break;
            default: cout<<"\n ������ ����� ���� �����������\n "<<endl; break;
        }
        system("pause");
    }
}

void Display(VrentalStruct*Vrental,int &NC,bool &Open){
    if(!Open){
        cerr << "Error: ���� ��� �� ��� ������!" << endl;
        return;
    }
    system("cls");
    for(int i=0;i<NC;i++){
        cout<<Vrental[i].ID<<"\t"<<Vrental[i].FilmNumber<<"\t"<<Vrental[i].FilmName<<"\t"<<Vrental[i].FilmYear<<"\t"<<Vrental[i].Type<<"\t"<<Vrental[i].Availability<<"\t"<<Vrental[i].Price<<"\t"<<endl;
    }
}

void About(){
    system("cls");
    cout<<" ������ ��������� �������� ������� ����� 2-4\n �������� ������\n\n"<<endl;
}
