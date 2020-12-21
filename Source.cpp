#include <iostream>
#include <Windows.h>
#include <time.h>
using namespace std;
typedef int info;
struct Spysok
{
    Spysok* Link,
        * Link1,
        * Link2;
    info inf;
};
void Creat(Spysok*& first, Spysok*& last, info inf);
void COUT(Spysok*& L);
int Process(Spysok*& L);
int main(void)
{
    srand((unsigned)time(NULL));

    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Spysok* first = NULL;
    Spysok* last = NULL;

    int x = 0;
    for (int i = 0; i < 10; i++)
    {
        x = rand() % 6;
        Creat(first, last, x);
    }

    Spysok* L = first;
    Spysok* L1 = first;
    Spysok* L2 = first;
    cout << "L:" << endl;
    COUT(L);
    cout<<"кількість додатних елементів списку: "<<Process(L)<<endl;
    return 0;
}
void Creat(Spysok*& first, Spysok*& last, info inf)
{
    Spysok* tmp = new Spysok;

    tmp->inf = inf;
    tmp->Link1 = NULL;
    tmp->Link2 = NULL;
    if (first == NULL)
        first = tmp;
    else
    {
        last->Link1 = tmp;
        tmp->Link2 = last;
    }
    last = tmp;
}
void COUT(Spysok*& L)
{

    info inf;
    while (L != NULL)
    {
        inf = L->inf;
        cout << inf << "   ";
        L = L->Link1;
    }
    cout << endl;
}
int Process(Spysok*& L)
{
    info inf;
    int k=0;
    while (L != NULL)
    {
        if (L->inf > 0)
            k++;
        L = L->Link1;
    }
    return k;
}