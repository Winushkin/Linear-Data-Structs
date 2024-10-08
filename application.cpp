#include "application.h"
#include "iostream"
#include "fstream"

using namespace std;


inline void clearStream() {
    cin.clear();
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    cin.sync();
}


Application::Application(){};


void Application::showMenu(char choice = 'a') {
    switch (choice) {
        case 'a':
            cout << "b. LinkedList\n"
                    "c. Array\n"
                    "d. SortStation with Stack\n";
            break;

        case 'b':
            cout << "\n1. Create List\n"
                    "2. Append new element\n"
                    "3. Insert new element\n"
                    "4. remove element\n"
                    "5. pop element\n"
                    "6. swap elements\n"
                    "7. get index\n"
                    "Another. Exit\n";
            break;

        case 'c':
            cout << "\n1. create array\n"
                    "2. fill array\n"
                    "3. insert elem\n"
                    "4. pop element\n"
                    "5. swap elems\n"
                    "6. get elem\n"
                    "7. print array\n"
                    "Another. Exit\n\n";
            break;

        case 'd':
            //Stack;
            break;

        case 'e':
            //SortStaion
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
    int choice, elemAmount, elem, index, index2;
    LinkedList<int> *list = nullptr;

    while ( true ){
        showMenu('b');
        cout << "your choice: "; cin >> choice;
        switch (choice) {

            case 1:
                delete list;
                list = new LinkedList<int>();
                cout << "List created\n";
                break;

            case 2:
                cout << "new elements amount: "; cin >> elemAmount;
                if ( elemAmount < 0 ){
                    elemAmount = 1;
                }
                cout << "enter " << elemAmount << " element(s) by space: ";
                for ( int i = 0; i < elemAmount; i++ ){
                    cin >> elem;
                    list->append(elem);
                }
                list->print();
                cout << "\n";
                break;

            case 3:
                cout << "Enter insert index and elem by space: "; cin >> index >> elem;
                if ( index < 0 || index > list->len() ){
                    cout << "index out of range\n";
                    break;
                }
                list->insert(index, elem);

                list->print();
                cout << "\n";
                break;

            case 4:
                cout << "Enter element to remove: "; cin >> elem;
                list->pop(list->getIndex(elem));

                list->print();
                cout << "\n";
                break;

            case 5:
                cout << "Enter index to pop elem: "; cin >> index;
                list->pop(index);

                list->print();
                cout << "\n";
                break;

            case 6:
                cout << "Enter indexes of elems to swap by space: "; cin >> index >> index2;
                list->swap(index, index2);

                list->print();
                cout << "\n";
                break;

            case 7:
                cout << "Enter element to get index: "; cin >> elem;
                cout << list->getIndex(elem); cout << "\n";

                list->print();
                cout << "\n";
                break;

            default:
                return 0;
        }
    }
}


int Application::StackWork() {
    return 0;
}


int Application::ArrayWork() {
    int choice, elem, fillingChoice, index, index2, *ptr;
    ifstream fin;
    Array<int> *array = nullptr;
    showMenu('c');

//            "4. pop element\n"
//            "5. swap elems\n"
//            "6. get elem\n"
//            "7. print array\n"
//            "Another. Exit\n\n";
    while (true) {
        cout << "\nyour choice: "; cin >> choice;
        switch (choice) {

            case 1:
                delete array;
                array = new Array<int>();
                cout << "Array created\n" <<
                     "size = " << array->getSize() << "\n" <<
                     "capacity = " << array->getCapacity() << "\n";
                break;

            case 2:
                cout << "\nЗаполнение:\n" <<
                     "1) manual input\n" <<
                     "2) file input\n" <<
                     "3) random filling\n--> ";
                cin >> fillingChoice;

                switch (fillingChoice) {
                    case 1:
                        cout << "Введите элементы через пробел: ";
                        while (cin >> elem) {
                            array->pushBack(elem);
                            if (cin.peek() == '\n') {
                                break;
                            }
                        }
                        clearStream();
                        break;

                    case 2:
                        fin.open("/Users/kirillbelaev/CLionProjects/AaDT_Lab1/filling.txt");
                        if (!fin.is_open()) {
                            cout << "\nfile reading mistake!!!\n";
                            break;
                        }
                        while (!fin.eof()) {
                            fin >> elem;
                            if (fin.fail()) {
                                fin.close();
                                cout << "\nmistake eshkere";
                                break;
                            }
                            array->pushBack(elem);
                            fin.get();
                        }
                        fin.close();
                        break;

                    case 3:
                        int len;
                        cout << "\nВведите длину: ";
                        cin >> len;
                        for (int i = 0; i < len; i++) {
                            array->pushBack(rand() % 100);
                        }
                        break;
                    default:
                        cout << "invalid input";
                        break;
                }
                array->print();
                break;

            case 3:
                cout << "enter index and value to insert: "; cin >> index >> elem;
                array->insert(index, elem);
                array->print();
                break;

            case 4:
                cout << "enter index to pop: "; cin >> index;
                array->pop(index);
                array->print();
                break;

            case 5:
                cout << "enter indexes to swap: "; cin >> index >> index2;
                array->swap(index, index2);
                array->print();
                break;

            case 6:
                cout << "enter index to get elem: "; cin >> index;
                ptr = array->getAt(index);
                if ( ptr ){
                    cout << *ptr;
                }else{
                    cout << "invalid input";
                }
                break;

            case 7:
                array->print();
                break;

            default:
                return 0;
        }
    }

    return 0;
}


int Application::sortStationWork() {
    return 0;
}


int Application::exec(){
    char choice;
    while ( true ){

        showMenu();
        cout << "your choice: "; cin >> choice;

        switch (choice) {
            case 'b':
                ListWork();
                break;

            case 'c':
                ArrayWork();
                break;

            case 'd':
                StackWork();
                break;

            case 'e':
                break;


        }
        return 0;
    }







}