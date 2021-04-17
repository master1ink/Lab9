#include "function.h"
#include "iostream"

using namespace std;

int main() {
    int choice;
    int sizeSubject;
    int sizeSubject1;
    int sizeSubject2;
    typeSubject* head = nullptr;
    typeSubject* head1 = nullptr;
    typeSubject* head2 = nullptr;

    do {
        cout << "\nMenu:\n"
        "1.Dynamic memory allocation\n"
        "2.Enter items from the keyboard\n"
        "3.Search an item\n"
        "4.Sorting\n"
        "5.Editing an item\n"
        "6.Swap two elements\n"
        "7.Add a new element to the end\n"
        "8.Remove an item\n"
        "9.Insert an element\n"
        "10.Define the address of the last element\n"
        "11.Define the length of a list\n"
        "12.Split a list in two\n"
        "13.Merge two lists\n"
        "14.Write to file\n"
        "15.Read from file\n"
        "16.Write data from file to list\n"
        "17.Display items\n"
        "18.Free up memory\n"
        "19.End\n"
        "\nType: ";

        cin >> choice;

        switch(choice) {
            case 1:
                head = createMemory(head, &sizeSubject);
                break;
            case 2:
                head = inputKeyboard(head, sizeSubject);
                break;
            case 3:
                searchLocationElement(head, sizeSubject);
                break;
            case 4:
                head = sortArray(head, sizeSubject);
                break;
            case 5:
                head = editElem(head, sizeSubject);
                break;
            case 6:
                head = exchangeElem(head, sizeSubject);
                break;
            case 7:
                head = addElem(head, &sizeSubject);
                break;
            case 8:
                head = deleteTargetElem(head, &sizeSubject);
                break;
            case 9:
                head = addNewElem(head, &sizeSubject);
                break;
            case 10:
                addressLast(head, sizeSubject);
                break;
            case 11:
                cout << "Main list length = " << length(head) << endl;
                cout << "1st list length = " << length(head1) << endl;
                cout << "2nd list length = " << length(head2) << endl;
                break;
            case 12:
                split(head, head1, head2, &sizeSubject, &sizeSubject1, &sizeSubject2);
                break;
            case 13:
                unite(head, head1, head2, &sizeSubject, &sizeSubject1, &sizeSubject2);
                break;
            case 14:
                writeFile(head, sizeSubject);
                break;
            case 15:
                readFile(head, sizeSubject);
                break;
            case 16:
                head = readDateFromFile(head, &sizeSubject);
                break;
            case 17:
                subjectPrintMain(head, head1, head2, sizeSubject, sizeSubject1, sizeSubject2);
                break;
            case 18:
                freeMemory(head, head1, head2);
                break;
            case 19:
                if (head != nullptr || head1 != nullptr)
                    freeMemory(head, head1, head2);
                cout << "\nMemory freed\n";
                break;
            default:
                cout << "\nError. You didn't enter a number from the menu.\n";
                break;
        }
    }
    while (choice != 19);
    return 0;
    }