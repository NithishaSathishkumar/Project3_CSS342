/* Nithisha Sathishkumar
* Novemeber 13, 2023
* Project 1
* Professor.Dimpsey
*/
#include <iostream>
#include "list342.h"
#include "child.h"
using namespace std;
int main(){
    //Test the Read txt
    List342<Child> child_list;
    string fileName = "in_text.txt";
    if(child_list.BuildList(fileName)){
        cout << "BuildList successful!" << endl;

        // Display the contents of the list after building
        cout << "List Contents:" << endl;
        cout << child_list << endl;
    } else {
        cout << "BuildList failed!" << endl;
    }

    cout << endl;

    Child c1("Angie", "Ham", 7), c2("Pradnya", "Dhala", 8), c3("Bill", "Vollmann", 13), c4("Cesar", "Ruiz", 6);
    Child c5("Piqi", "Tangi", 7), c6("Russell", "Wilson", 13), c7("Hank", "Aaron", 3), c8("Madison", "Fife", 7);
    Child c9("Miles", "Davis", 65), c10("John", "Zorn", 4), c11;

    List342<Child> class1, class2, soccer, chess;
    int a = 1, b = -1, c = 13;

    class1.Insert(&c1);
    class1.Insert(&c2);
    class1.Insert(&c3);
    class1.Insert(&c4);
    class1.Insert(&c5);
    class1.Insert(&c6);
    class1.Insert(&c5);

    cout << "class1: " << class1 << endl;

    if (! class1.Insert(&c1)){
        cout << "ERROR::: Duplicate" << endl;
    }

    class2.Insert(&c4);
    class2.Insert(&c5);
    class2.Insert(&c6);
    class2.Insert(&c7);
    class2.Insert(&c10);

    cout << "Class2: " << class2 << endl;

    class1.Merge(class2);
    class2.Merge(class1);
    class1.Merge(class2);
    class1.Merge(class1);

    cout << "class1 and 2 Merged: " << class1 << endl;

    class1.Remove(c4, c11);
    class1.Remove(c5, c11);
    class1.Remove(c11, c11);

    if (class1.Remove(c1, c11)){
        cout << "Removed from class1, student " << c11 << endl;
    }

    cout << "class1: " << class1 << endl;

    soccer.Insert(&c6);
    soccer.Insert(&c4);
    soccer.Insert(&c9);

    cout << "soccer: " << soccer << endl;
    
    soccer += class1;
    
    cout << "soccer += class1 : " << soccer << endl;
   
    List342<Child> football = soccer;
    if (football == soccer){
        cout << "football: " << football << endl;
    }
    
    if (football.Peek(c6, c11)){
        cout << c11 << " is on the football team" << endl;
    }
    soccer.DeleteList();
    List342<int> numbers;
    numbers.Insert(&a);
    numbers.Insert(&b);
    numbers.Insert(&c);
    cout << "These are the numbers: " << numbers << endl;
    numbers.DeleteList();


    
    return 0;
    
}

/*
OUTPUT:
class1: PradnyaDhala8 AngieHam7 CesarRuiz6 PiqiTangi7 BillVollmann13 RussellWilson13
ERROR::: Duplicate
Class2: HankAaron3 CesarRuiz6 PiqiTangi7 RussellWilson13 JohnZorn4
class1 and 2 Merged: HankAaron3 PradnyaDhala8 AngieHam7 CesarRuiz6 PiqiTangi7 BillVollmann13 RussellWilson13 JohnZorn4
Removed from class1, student AngieHam7
class1: HankAaron3 PradnyaDhala8 BillVollmann13 RussellWilson13 JohnZorn4
soccer: MilesDavis65 CesarRuiz6 RussellWilson13
soccer += class1 : HankAaron3 MilesDavis65 PradnyaDhala8 CesarRuiz6 BillVollmann13 RussellWilson13 JohnZorn4
football: HankAaron3 MilesDavis65 PradnyaDhala8 CesarRuiz6 BillVollmann13 RussellWilson13 JohnZorn4
RussellWilson13 is on the football team
These are the numbers: -1113
*/