#include <iostream>
#include "menu.hpp"
#include "rwfunc.hpp"
#include "windows.h"

using namespace std;

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    VrentalStruct Vrental[100];
    int NC=0;
    bool Open=0;

    Menu(Vrental,NC,Open);
    return 0;
}
