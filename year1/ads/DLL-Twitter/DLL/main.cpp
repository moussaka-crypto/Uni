#include <iostream>
//#define CATCH_CONFIG_RUNNER
#include "List.h"
//#include "catch.hpp"
using namespace std;

int main(void)
{
    //int  result = Catch::Session().run();
    int  i;
    List MyList;

    for (i = 0; i < 10; i++)
    {
        MyList.insertFront(i + 1);
        MyList.insertBack(i + 100);
        //cout << MyList;
    }

    cout << MyList;

    //Destruktor testen
    MyList.~List();
    

    cout << "100: " << (MyList.search(100) ? "gefunden" : "nicht gefunden")
        << endl;
    cout << "99: " << (MyList.search(99) ? "gefunden" : "nicht gefunden")
        << endl
        << endl;

    while (MyList.getBack(i))
        cout << i << " ";
    cout << endl << endl;

    List  MyList1, MyList2, MyList3;
    List* MyList_dyn = new List();

    for (i = 0; i < 10; i++)
    {
        MyList1.insertFront(i + 1);
        MyList2.insertBack(i + 100);
    }

    MyList1.format("MyList1\n<<", ", ", ">>\n\n");
    cout << MyList1;

    MyList_dyn->format("MyList_dyn\n<<", ", ", ">>\n\n");
    MyList_dyn->insertFront(-111);
    cout << *MyList_dyn;

    MyList2.format("MyList2\n<<", ", ", ">>\n\n");
    cout << MyList2;

    MyList3 = MyList1 + (*MyList_dyn) + MyList2;

    delete MyList_dyn;

    cout << "Groesse von MyList3: " << MyList3.size() << endl << endl;

    MyList3.format("MyList3\n<<", ", ", ">>\n\n");
    cout << MyList3 << endl;

    MyList3.swap(8, 103);
    MyList3.swap(100, -111);

    cout << MyList3;

    if (MyList3.test())
        cout << "MyList3: Zeiger OK\n\n";
    else
        cout << "MyList3: Zeiger ******Error\n\n";

    system("PAUSE");
    return 0;
}
