#include "application.h"
#include "iostream"

using namespace std;

Application::Application(){};


void Application::showMenu(char choice = 'a') {
    switch (choice) {
        case 'a':
            cout << "b. LinkedList\n"
                    "c. Array\n"
                    "d. SortStation with Stack\n";
            break;

        case 'b':
            cout << "1. Create List\n"
                    "2. Append new element\n"
                    "3. Insert new element\n"
                    "4. remove element\n"
                    "5. pop element\n"
                    "6. swap elements\n"
                    "7. get index\n";
            break;
        case 'c':
            //Array
            break;

        case 'd':
            cout << "1. infix -> Prefix/Postfix\n"
                    "2. check expressions for mistakes\n"
                    "3. Evaluate expression\n";
            break;


        default:
            cout << "invalid input";
            break;
    }

}



int Application::ListWork() {

    cout << "1. Create List\n"
            "2. Append new element\n"
            "3. Insert new element\n"
            "4. remove element\n"
            "5. pop element\n"
            "6. swap elements\n"
            "7. get index\n";

    int choice, elemAmount, elem, index, index2;
    LinkedList<int> *list;
    while ( true ){
        showMenu('b');
        cout << "your choice: "; cin >> choice;
        switch (choice) {

            case 1:
                list = new LinkedList<int>();
                break;

            case 2:
                cout << "new elements amount: "; cin >> elemAmount;
                if ( elemAmount < 0 ){
                    elemAmount = 1;
                }
                cout << "enter " << elemAmount << " elements by space: ";
                for ( int i = 0; i < elemAmount; i++ ){
                    cin >> elem;
                    list->append(elem);
                }
                break;

            case 3:
                cout << "Enter insert index and elem by space: "; cin >> index >> elem;
                if ( index < 0 || index >= list->len() ){
                    cout << "index out of range";
                    break;
                }
                list->insert(index, elem);
                break;

            case 4:
                cout << "Enter element to remove: "; cin >> elem;
                list->pop(list->getIndex(elem));
                break;

            case 5:
                cout << "Enter index to pop elem: "; cin >> index;
                list->pop(index);
                break;

            case 6:
                //swap elem;
                cout << "Enter indexes of elems to swap by space: "; cin >> index >> index2;
                list->swap(index, index2);
                break;

            case 7:
                //get index;
                cout << "Enter element to get index: "; cin >> elem;
                cout << list->getIndex(elem);
                break;

            default:
                return 0;
                break;
        }


    }



}


int Application::exec(){
    int choice;
    while ( true ){

        showMenu();
        cout << "your choice: "; cin >> choice;
        showMenu(choice);

        switch (choice) {
            case 'b':
                ListWork();
        }


        return 0;
    }







}