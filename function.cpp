#include "function.h"
#include <cstdio>
#include "iostream"
#include <cstring>

using namespace std;

typeSubject *node;
bool memoryAllocate = false;
bool arrayExist = false;
bool arrayExist1 = false;
bool arrayExist2 = false;

typeSubject* createMemory(typeSubject *head, int *sizeSubject) {
    if (memoryAllocate)
        cout << "\nThe memory has already been allocated.\n";
    else {
        cout << "\nEnter the number of items: ";
        cin >> *sizeSubject;

        head = new typeSubject;
        head->next = nullptr;
        head->prev = nullptr;

        typeSubject *temp;
        node = head;
        for (int i = 0; i < *sizeSubject - 1; i++) {
            temp = node;
            node->next = new typeSubject;
            node = node->next;
            node->prev = temp;
            node->next = nullptr;
        }
        memoryAllocate = true;
        cout << "\nCompleted successfully!\n";
    }
    return head;
}

typeSubject* inputKeyboard(typeSubject *head, int sizeSubject) {
    if (memoryAllocate && !arrayExist1) {
        cout <<"\nData input:\n";
        node = head;
        for (int i = 0; i < sizeSubject; i++) {
            cout << "Movie title: ";
            cin >> node->title;
            cout << "Movie year: ";
            cin >> node->year;
            cout << "Director of the movie: ";
            cin >> node->author;
            cout << "Genre of the movie: ";
            cin >> node->genre;
            cout << "Duration: ";
            cin >> node->hours;
            node = node->next;
            cout << endl;
        }
        arrayExist = true;
    } else
        cout << "\nError. No memory allocated or merge lists.\n";
    return head;
}

void searchLocationElement(typeSubject* head, int sizeSubject) {
    if (arrayExist) {
        int searchChoice;
        char locationChar[30];
        int locationInt;
        int position;
        do {
            int f = 0;
            cout << "1.Search by title\n"
                    "2.Search by year\n"
                    "3.Search by director\n"
                    "4.Search by genre\n"
                    "5.Search by duration\n"
                    "6.Exit to the main menu\n"
                    "\nEnter: ";
            cin >> searchChoice;
            switch(searchChoice) {
                case 1:
                    cout << "\nTitle: ";
                    cin >> locationChar;
                    node = head;
                    position = 1;
                    do {
                        if (strcmp(node->title, locationChar) == 0) {
                            print(node, position);
                            f = 1;
                        }
                        node = node->next;
                        position++;
                    } while (node != nullptr);
                    if (!f)
                        cout << "\nNo such title was found.\n";
                    break;
                case 2:
                    cout << "\nYear: ";
                    cin >> locationInt;
                    node = head;
                    position = 1;
                    do {
                        if (node->year == locationInt) {
                            print(node, position);
                            f = 1;
                        }
                        node = node->next;
                        position++;
                    } while (node != nullptr);
                    if (!f)
                        cout << "\nNo such year has been found.\n";
                    break;
                case 3:
                    cout << "\nName: ";
                    cin >> locationChar;
                    node = head;
                    position = 1;
                    do {
                        if (strcmp(node->author, locationChar) == 0) {
                            print(node, position);
                            f = 1;
                        }
                        node = node->next;
                        position++;
                    } while (node != nullptr);
                    if (!f)
                        cout << "\nNo such author has been found.\n";
                    break;
                case 4:
                    cout << "\nGenre: ";
                    cin >> locationChar;
                    node = head;
                    position = 1;
                    do {
                        if (strcmp(node->genre, locationChar) == 0) {
                            print(node, position);
                            f = 1;
                        }
                        node = node->next;
                        position++;
                    } while (node != nullptr);
                    if (!f)
                        printf("\nSuch a genre has not been found.\n\n");
                    break;
                case 5:
                    cout << "\nDuration: ";
                    cin >> locationInt;
                    node = head;
                    position = 1;
                    do {
                        if (node->hours == locationInt) {
                            print(node, position);
                            f = 1;
                        }
                        node = node->next;
                        position++;
                    } while (node != nullptr);
                    if (!f)
                        cout << "\nThis duration has not been found.\n";
                    break;
                case 6:
                    break;
                default:
                    cout << "\nInvalid input.\n";
                    break;
            }
        } while (searchChoice != 6);
    } else
        cout << "\nError. The list does not exist.\n";
}

typeSubject* sortArray(typeSubject* head, int sizeSubject) {
    if (sizeSubject > 1 && arrayExist) {
        int sortChoice;
        int sortChoiceTwo;
        start:
        do {
            cout << "\n1.Sorting by title\n"
                    "2.Sorting by years\n"
                    "3.Sorting by director\n"
                    "4.Sorting by genre\n"
                    "5.Sorting by duration\n"
                    "6.Exit to the main menu\n"
                    "\nInput: ";
            cin >> sortChoice;

            if (sortChoice == 6) {
                return head;
            }
            else if ((sortChoice < 1) || (sortChoice > 6))
                cout << "\nInvalid input.\n";
        } while ((sortChoice < 1) || (sortChoice > 6));
        do {
            cout << "\n1.Sort descending\n"
                    "2.Sort Ascending\n"
                    "3.Back\n"
                    "4.Exit to the main menu\n"
                    "\nInput: ";
            cin >> sortChoiceTwo;

            if (sortChoiceTwo == 4)
            {
                return head;
            } else if (sortChoiceTwo == 3)
                goto start;
            else if ((sortChoiceTwo < 1) || (sortChoiceTwo > 4))
                cout << "\nInvalid input.\n";

        } while ((sortChoiceTwo < 1) || (sortChoiceTwo > 4));

        switch(sortChoice)
        {
            case 1:
                if (sortChoiceTwo == 1) {
                    sortDescendingName(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                } else {
                    sortAscendingName(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                }
                break;
            case 2:
                if (sortChoiceTwo == 1) {
                    sortDescendingYear(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                } else {
                    sortAscendingYear(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                }
                break;
            case 3:
                if (sortChoiceTwo == 1) {
                    sortDescendingFaculty(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                } else {
                    sortAscendingFaculty(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                }
                break;
            case 4:
                if (sortChoiceTwo == 1) {
                    sortDescendingCathedra(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                } else {
                    sortAscendingCathedra(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                }
                break;
            case 5:
                if (sortChoiceTwo == 1) {
                    sortDescendingHours(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                } else {
                    sortAscendingHours(head);
                    cout << endl;
                    subjectPrint(head, sizeSubject, 1);
                }
                break;
        }
        goto start;
    } else {
        cout << "\nError.\n"
        "Sorting can be used if there is more than one item.\n";
    }
    return head;
}

typeSubject* editElem(typeSubject* head, int sizeSubject) {
    if (arrayExist) {
        int editChoice;
        int editChoiceTwo;
        start:
        do {
            cout << "\n1.Editing title\n"
                    "2.Editing year\n"
                    "3.Editing director\n"
                    "4.Editing genre\n"
                    "5.Editing duration\n"
                    "6.Exit to the main menu\n"
                    "\nInput: ";
            cin >> editChoice;

            if (editChoice == 6) {
                return head;
            } else if ((editChoice < 1) || (editChoice > 6))
                cout << "\nInvalid input.\n";
        } while ((editChoice < 1) || (editChoice > 6));

        do {

            cout << "\nSelect the item number you want to edit.";
            cout << "Total " << sizeSubject << " item(s)\n";
            for (int i = 0; i < sizeSubject; i++) {
                cout << i << ". Movie nr." << i + 1 << endl;
            }
            cout << sizeSubject << ".Back";
            cout << sizeSubject + 1 << ".Exit to the main menu\n";
            cout << "\nInput: ";
            cin >> editChoiceTwo;

            if (editChoiceTwo == sizeSubject + 1)
            {
                return head;
            } else if (editChoiceTwo == sizeSubject)
                goto start;
            else if ((editChoiceTwo < 0) || (editChoiceTwo > sizeSubject + 1))
                printf("\nInvalid input.\n");
        } while ((editChoiceTwo < 0) || (editChoiceTwo > sizeSubject + 1));

        switch(editChoice)
        {
            case 1:
                node = head;
                for (int i = 0; i < editChoiceTwo; i++)
                    node = node->next;
                cout << "Title: ";
                cin >> node->title;
                break;
            case 2:
                node = head;
                for (int i = 0; i < editChoiceTwo; i++)
                    node = node->next;
                cout << "Year: ";
                cin >> node->year;
                break;
            case 3:
                node = head;
                for (int i = 0; i < editChoiceTwo; i++)
                    node = node->next;
                cout << "Director: ";
                cin >> node->author;
                break;
            case 4:
                node = head;
                for (int i = 0; i < editChoiceTwo; i++)
                    node = node->next;
                cout << "Genre: ";
                cin >> node->genre;
                break;
            case 5:
                node = head;
                for (int i = 0; i < editChoiceTwo; i++)
                    node = node->next;
                cout << "Duration: ";
                cin >> node->hours;
                break;
        }
        goto start;
    } else
        cout << "\nError. The list does not exist.\n";
    return head;
}

typeSubject* exchangeElem(typeSubject *head, int sizeSubject) {
    if (arrayExist) {
        int exchangeChoice;
        int exchangeChoiceTwo;
        typeSubject *firstElem, *secondElem;
        start:
        do {
            cout << "\nSelect the item number you want to exchange.";
            cout << "Total " << sizeSubject << " item(s)\n";
            for (int i = 0; i < sizeSubject; i++) {
                cout << i << ". Movie nr." << i + 1 << endl;
            }
            cout << sizeSubject << ".Exit to the main menu\n";
            cout << "\nInput: ";
            cin >> exchangeChoice;
            if (exchangeChoice == sizeSubject) {
                return head;
            } else if ((exchangeChoice < 0) || (exchangeChoice > sizeSubject))
                printf("\nInvalid input.\n");
        } while ((exchangeChoice < 0) || (exchangeChoice > sizeSubject + 1));
        do {
            cout << "\nSelect the item number you want to exchange.";
            cout << "Total " << sizeSubject << " item(s)\n";
            for (int i = 0; i < sizeSubject; i++) {
                cout << i << ". Movie nr." << i + 1 << endl;
            }
            cout << sizeSubject << ".Exit to the main menu\n";
            cout << "\nInput: ";
            cin >> exchangeChoiceTwo;
            if (exchangeChoiceTwo == sizeSubject + 1) {
                return head;
            }
            else if (exchangeChoiceTwo == sizeSubject)
                goto start;
            else if ((exchangeChoiceTwo < 0) || (exchangeChoiceTwo > sizeSubject + 1))
                cout << "\nInvalid input.\n";
        } while ((exchangeChoiceTwo < 0) || (exchangeChoiceTwo > sizeSubject + 2));
        if (exchangeChoiceTwo == exchangeChoice) {
            cout << "\nError.\n";
            goto start;
        }
        firstElem = head;
        secondElem = head;
        for (int i = 0; i < exchangeChoice; i++)
            firstElem = firstElem->next;
        for (int i = 0; i < exchangeChoiceTwo; i++)
            secondElem = secondElem->next;
        swap(head, firstElem, secondElem);
        cout << "\nThe exchange is complete.\n";
        goto start;
    } else
        cout << "\nError. The list does not exist.\n";
    return head;
}

typeSubject* addElem(typeSubject* head, int* sizeSubject) {
    if (arrayExist) {
        int addChoice;
        start:
        do {
            cout << "\n1.Continue\n"
                    "2.Displaying items on the screen\n"
                    "3.Exit to the main menu\n"
                    "\nInput: ";
            cin >> addChoice;

            if (addChoice == 3) {
                return head;
            } else if ((addChoice < 1) || (addChoice > 3)) {
                cout << "\nInvalid input.\n";
                goto start;
            } else if (addChoice == 2) {
                cout << endl;
                subjectPrint(head, *sizeSubject, 1);
                goto start;
            }
            head = miniAddElem(*sizeSubject, head, sizeSubject);
        } while ((addChoice < 1) || (addChoice > 3));
        cout << "\nThe item was added successfully!\n";
        goto start;
    } else
        cout << "\nError. The list does not exist.\n";
    return head;
}

typeSubject* deleteTargetElem(typeSubject* head, int* sizeSubject) {
    if (arrayExist) {
        int deleteChoice;
        typeSubject* target;
        start:
        if (*sizeSubject == 0) {
            arrayExist = false;
            memoryAllocate = false;
            delete head;
            head = nullptr;
            return head;
        }
        do {
            cout << "\n1.Continue\n"
                    "2.Displaying items on the screen\n"
                    "3.Exit to the main menu\n"
                    "\nInput: ";
            cin >> deleteChoice;

            if (deleteChoice == 3) {
                return head;
            } else if ((deleteChoice < 1) || (deleteChoice > 3)) {
                cout << "\nInvalid input.\n";
                goto start;
            } else if (deleteChoice == 2) {
                cout << endl;
                subjectPrint(head, *sizeSubject, 1);
                goto start;
            }
        } while ((deleteChoice < 1) || (deleteChoice > 3));
        do {
            cout << "\nSelect the item number you want to delete."
                    "Total" << sizeSubject << "item (s):\n";
            for (int i = 0; i < *sizeSubject; i++)
                cout << i << "." << i + 1 << " movie\n";
            cout << sizeSubject << ".Back\n";
            cout << sizeSubject + 1 << ".Exit to the main menu\n"
            "\nInput: ";
            cin >> deleteChoice;
            if ((deleteChoice < 0) || (deleteChoice > *sizeSubject + 1))
                cout << "\nInvalid input.\n";
            else if (deleteChoice == *sizeSubject + 1) {
                return head;
            } else if (deleteChoice == *sizeSubject)
                goto start;
        } while ((deleteChoice < 0) || (deleteChoice > *sizeSubject + 1));
        node = head;
        target = head;
        for (int i = 0; i < deleteChoice; i++)
            target = target->next;
        if (target == head) {
            head = target->next;
            target->next->prev = nullptr;
            goto end;
        }
        while (node->next != target)
            node = node->next;
        if (target == nullptr) {
            node->next = nullptr;
            goto end;
        }
        node->next = target->next;
        target->next->prev = node;
        end:
        delete target;
        --*sizeSubject;
        cout << "\nThe item was deleted successfully!\n";
        goto start;
    } else
        cout << "\nError. The list does not exist.\n";
    return head;
}

typeSubject* addNewElem(typeSubject* head, int* sizeSubject) {
    if (arrayExist) {
        int addNewChoice;
        int addNewChoiceTwo;
        start:
        do {
            cout << "\n1.Before any element\n"
                    "2.After any element\n"
                    "3.To the start\n"
                    "4.In the end\n"
                    "5.Displaying elements on the screen\n"
                    "6.Exit to the main menu\n"
                    "\nInput: ";
            cin >> addNewChoice;
            if (addNewChoice == 6) {
                return head;
            } else if (addNewChoice == 5) {
                cout << endl;
                subjectPrint(head, *sizeSubject, 1);
                goto start;
            } else if ((addNewChoice < 1) || (addNewChoice > 6)) {
                cout << "\nInvalid input.\n";
                goto start;
            }
        } while ((addNewChoice < 1) || (addNewChoice > 6));
        if (addNewChoice == 3) {
            head = miniAddElem(0, head, sizeSubject);
            goto end;
        } else if (addNewChoice == 4) {
            head = miniAddElem(*sizeSubject, head, sizeSubject);
            goto end;
        }
        middle:
        do {
            cout << "\nSelect the item number after which you want to insert a new item."
                    "Total" << sizeSubject << "item (s):\n";
            for (int i = 0; i < *sizeSubject; i++)
                cout << i << "." << i + 1 << " movie\n";
            cout << sizeSubject << ".Back\n"
            << sizeSubject + 1 << ".Exit to the main menu\n"
            "\nInput: ";
            cin >> addNewChoiceTwo;
            if (addNewChoiceTwo == *sizeSubject + 1) {
                return head;
            } else if ((addNewChoiceTwo < 0) || (addNewChoiceTwo > *sizeSubject + 1)) {
                cout << "\nInvalid input.\n";
                goto middle;
            } else if (addNewChoiceTwo == *sizeSubject)
                goto start;
        } while ((addNewChoiceTwo < 0) || (addNewChoiceTwo > *sizeSubject + 1));
        switch(addNewChoice)
        {
            case 1:
                head = miniAddElem(addNewChoiceTwo, head, sizeSubject);
                break;
            case 2:
                head = miniAddElem(addNewChoiceTwo + 1, head, sizeSubject);
                break;
        }
        end:
        cout << "\nThe item was added successfully!\n";
        goto start;
    } else
        cout << "\nError. The list does not exist.\n";
    return head;
}

void addressLast(typeSubject* head, int sizeSubject) {
    if (arrayExist) {
        node = head;
        for (int i = 0; i < sizeSubject - 1; i++)
            node = node->next;
        cout << "Last element addresses =" << node << endl;
    } else
        cout << "\nError. The list does not exist.\n";
}
int length(typeSubject* head) {
    typeSubject* current = head;
    int count = 0;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void split(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2) {
    if (arrayExist) {
        int splitChoice;
        int splitChoiceTwo;
        typeSubject *nextSecList, *node2;
        start:
        do {
            cout << "\n1.Continue\n"
                    "2.Displaying items on the general list screen\n"
                    "3.Displaying items on the screen of the 1st list\n"
                    "4.Displaying items on the screen of the 2nd list\n"
                    "5.Exit to the main menu\n"
                    "\nInput: ";
            cin >> splitChoice;
            if (splitChoice == 5) {
                return;
            } else if (splitChoice == 2 && arrayExist) {
                cout << endl;
                subjectPrint(head, *sizeSubject, 0);
                goto start;
            } else if (splitChoice == 3 && arrayExist1) {
                cout << endl;
                subjectPrint(head1, *sizeSubject1, 0);
                goto start;
            } else if ((splitChoice < 1) || (splitChoice > 5)) {
                cout << "\nInvalid input.\n";
                goto start;
            }
            else if (splitChoice == 4 && arrayExist2) {
                cout << endl;
                subjectPrint(head2, *sizeSubject2, 0);
                goto start;
            } else if (splitChoice == 1)
                goto middle;
            else {
                cout << "\nError. The list does not exist.\n";
                goto start;
            }
        } while ((splitChoice < 1) || (splitChoice > 4));
        middle:
        cout << "\nEnter the number of the element that will be the last in the 1st list: ";
        cin >> splitChoice;
        if (splitChoice != *sizeSubject - 1) {
            node = head;
            head1 = head;
            for (int i = 0; i < splitChoice; i++)
                node = node->next;
            nextSecList = node->next;
            nextSecList->prev = nullptr;
            node->next = nullptr;

            node = head1;
            *sizeSubject1 = 0;
            while (node != nullptr) {
                ++*sizeSubject1;
                node = node->next;
            }
            arrayExist1 = true;
            head2 = nextSecList;
            node2 = head2;
            *sizeSubject2 = 0;
            while (node2 != nullptr) {
                ++*sizeSubject2;
                node2 = node2->next;
            }
            arrayExist2 = true;
            head = nullptr;
            *sizeSubject = 0;
            arrayExist = false;
        } else {
            cout << "\nError. The last element of the list cannot be the last 1st.\n";
            goto middle;
        }
        cout << "\nCompleted!\n";
    } else	{
        cout <<"\nError. The list does not exist.\n";
    }
}

void unite(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2) {
    if (arrayExist1) {
        int uniteChoice;
        typeSubject *node2;
        start:
        do {
            cout << "\n1.Continue\n"
                    "2.Displaying items on the general list screen\n"
                    "3.Displaying items on the screen of the 1st list\n"
                    "4.Displaying items on the screen of the 2nd list\n"
                    "5.Exit to the main menu\n"
                    "\nInput: ";
            cin >> uniteChoice;
            if (uniteChoice == 5) {
                return;
            } else if (uniteChoice == 2 && arrayExist) {
                cout << endl;
                subjectPrint(head, *sizeSubject, 0);
                goto start;
            } else if (uniteChoice == 3 && arrayExist1) {
                cout << endl;
                subjectPrint(head1, *sizeSubject1, 0);
                goto start;
            } else if ((uniteChoice < 1) || (uniteChoice > 5)) {
                cout << "\nInvalid input.\n";
                goto start;
            }
            else if (uniteChoice == 4 && arrayExist2) {
                cout << endl;
                subjectPrint(head2, *sizeSubject2, 0);
                goto start;
            } else if (uniteChoice == 1)
                goto middle;
            else {
                cout << "\nError. The list does not exist.\n";
                goto start;
            }
        } while ((uniteChoice < 1) || (uniteChoice > 4));
        middle:
        head = head1;
        for (int i = 0; i < *sizeSubject1 - 1; i++)
            head1 = head1->next;
        head1->next = head2;
        head2->prev = head1;
        *sizeSubject = *sizeSubject1 + *sizeSubject2;
        *sizeSubject1 = 0;
        *sizeSubject2 = 0;
        head1 = nullptr;
        head2 = nullptr;
        arrayExist = true;
        arrayExist1 = false;
        arrayExist2 = false;
        cout << "\nCompleted!\n";
    } else
        cout <<"\nError. Divide the list.\n";
}

void writeFile(typeSubject* head, int sizeSubject)
{
    if (arrayExist) {
        FILE *fp = fopen("text.txt", "w");
        fprintf(fp, "|------------------------------------------------------");
        fprintf(fp, "-----------------------------------------------|\n");
        fprintf(fp, "|\t\t\t\t       Total number of movies: %-35d", sizeSubject);
        fprintf(fp, "|\n");
        fprintf(fp, "|---------------------------------------------------");
        fprintf(fp, "--------------------------------------------------|\n");
        fprintf(fp, "|    Nr.    | \tTitle      |  Year   |");
        fprintf(fp, "   \tDirector       |          Genre          |  Duration   |\n");
        fprintf(fp, "|------------------------------------------------------");
        fprintf(fp, "-----------------------------------------------|\n");
        int i = 0;
        node = head;
        do {
            fprintf (fp, "| %-5d  ", i);
            fprintf (fp, " | %-17s ", node->title);
            fprintf (fp, "| %-6d ", node->year);
            fprintf (fp, "| %-22s ",  node->author);
            fprintf (fp, "| %-25s ",  node->genre);
            fprintf (fp, "| %-7d |\n", node->hours);
            fprintf(fp, "|------------------------------------------------------");
            fprintf(fp, "-----------------------------------------------|\n");
            i++;
            node = node->next;
        } while (node != nullptr);
        fclose(fp);
        FILE *fp2 = fopen("text.txt", "w");
        node = head;
        fprintf (fp2, "%d\n", sizeSubject);
        do {
            fprintf (fp2, "\n%s\n%d\n%s\n%s\n%d", node->title, node->year,
                     node->author, node->genre, node->hours);
            node = node->next;
        } while (node != nullptr);
        fclose(fp2);
        cout << "\nCompleted!\n";
    } else
        cout << "\nError. The list does not exist.\n";
}

void readFile(typeSubject* head, int sizeSubject) {
    int i;
    FILE *fp = fopen("text.txt", "r");
    char buffer[255];
    if (fp == nullptr) {
        cout << "\nError. The file could not be opened.\n";
        return;
    } else {
        cout << "\nFile content:\n";
        while ((buffer[i] = fgetc(fp)) != EOF) {
            if (buffer[i] == '\n') {
                buffer[i] = '\0';
                cout << buffer << endl;
                i = 0;
            } else i++;
        }
    }
    fclose(fp);
    cout << "\nCompleted!\n";
}

typeSubject* readDateFromFile(typeSubject* head, int* sizeSubject) {
    if (!arrayExist && !arrayExist1) {
        int i;
        FILE *fp = fopen("text.txt", "r");
        if (fp == nullptr) {
            cout << "\nError. The file could not be opened.\n";
            return head;
        } else {
            fscanf(fp, "%d\n", sizeSubject);
            head = new typeSubject;
            head->next = nullptr;
            head->prev = nullptr;
            typeSubject *temp;
            node = head;
            for (int i = 0; i < *sizeSubject - 1; i++) {
                temp = node;
                node->next = new typeSubject;
                node = node->next;
                node->prev = temp;
                node->next = nullptr;
            }
            node = head;
            while (fscanf(fp, "\n%s\n%d\n%s\n%s\n%d", node->title, &node->year,
                          node->author, node->genre, &node->hours) != EOF)
                node = node->next;
            memoryAllocate = true;
            arrayExist = true;
            cout << "\nCompleted!\n";
        }
        fclose(fp);
    } else
        cout << "\nError. The list already exists or you split the list.\n";
    return head;
}

void subjectPrintMain(typeSubject* head, typeSubject* head1, typeSubject* head2, int sizeSubject, int sizeSubject1, int sizeSubject2) {
    int printChoice;
    start:
    cout << "\n1.Displays items on the general list screen.\n"
            "2.Displaying items on the screen of the 1st list.\n"
            "3.Displaying items on the screen of the 2nd list.\n"
            "4.Exit to the main menu.\n"
            "\nInput: ";
    cin >> printChoice;

    switch(printChoice) {
        case 1:
            if (arrayExist)
                subjectPrint(head, sizeSubject, 0);
            else {
                cout << "\nError. The list does not exist.";
            }
            goto start;
        case 2:
            if (arrayExist1)
                subjectPrint(head1, sizeSubject1, 0);
            else
                cout << "\nError. The list does not exist.\n";
            goto start;
        case 3:
            if (arrayExist2)
                subjectPrint(head2, sizeSubject2, 0);
            else
                cout << "\nError. The list does not exist.\n";
                goto start;
        case 4:
            break;
        default:
            cout << "\nInvalid input.\n";
            goto start;
    }
}

void freeMemory(typeSubject*& head, typeSubject*& head1, typeSubject*& head2) {
    if (memoryAllocate) {
        if (arrayExist) {
            while (head != nullptr) {
                node = head;
                head = head->next;
                delete node;
                if (head != nullptr)
                    head->prev = nullptr;
            }
            head = nullptr;
            arrayExist = false;
        }
        else {
            while (head1 != nullptr) {
                node = head1;
                head1 = head1->next;
                delete node;
                if (head1 != nullptr)
                    head1->prev = nullptr;
            }
            head1 = nullptr;

            while (head2 != nullptr) {
                node = head2;
                head2 = head2->next;
                delete node;
                if (head2 != nullptr)
                    head2->prev = nullptr;
            }
            head2 = nullptr;

            arrayExist1 = false;
            arrayExist2 = false;
        }

        memoryAllocate = false;
        cout << "\nThe memory is free.\n";
    } else
        cout << "\nError. No memory has been allocated.\n";
}

void subjectPrint(typeSubject* head, int sizeSubject, int sortNumber) {
    int printChoice;
    if (sortNumber)
        goto output;
    do {
        cout << "1.Top down\n"
                "2.Down up\n"
                "3.Back\n"
                "\nInput: ";
        cin >> printChoice;

        if ((printChoice < 1) || (printChoice > 3))
            cout << "\nInvalid input.\n";
        else if (printChoice == 3)
            return;
    } while ((printChoice < 1) || (printChoice > 3));

    output:

    cout << "|------------------------------------------------------"
            "-----------------------------------------------|\n";
    printf("|\t\t\t\t       Total number of movies: %-35d", sizeSubject);
    cout << "|\n"
    "|---------------------------------------------------"
    "--------------------------------------------------|\n"
    "|    Nr.    | \tTitle      |  Year   |"
    "   \tDirector       |          Genre          |  Duration   |\n"
    "|------------------------------------------------------"
    "-----------------------------------------------|\n";

    int i = 0;
    node = head;
    if (sortNumber)
        goto output2;
    switch(printChoice) {
        case 1:
        output2:

            do {
                printf ("| %-5d  ", i);
                printf (" | %-17s ", node->title);
                printf ("| %-6d ", node->year);
                printf ("| %-22s ",  node->author);
                printf ("| %-25s ",  node->genre);
                printf ("| %-7d |\n", node->hours);
                cout <<"|------------------------------------------------------"
                       "-----------------------------------------------|\n";
                i++;
                node = node->next;
            } while (node != nullptr);
            break;
        case 2:
            while (node->next != nullptr)
                node = node->next;
            do {
                printf ("| %-5d  ", i);
                printf (" | %-17s ", node->title);
                printf ("| %-6d ", node->year);
                printf ("| %-22s ",  node->author);
                printf ("| %-25s ",  node->genre);
                printf ("| %-7d |\n", node->hours);
                cout <<"|------------------------------------------------------"
                       "-----------------------------------------------|\n";
                i++;
                node = node->prev;
            } while (node != nullptr);
    }
    cout << "\nCompleted!\n";
}

void print (typeSubject *node, int position) {
    cout << "This is item Nr." << position - 1 << "Information about him::\n\n"
    "|---------------------------------------------------"
    "--------------------------------------------------|\n"
    "|    Nr.    | \tTitle      |  Year   |"
    "   \tDirector       |          Genre          |  Duration   |\n"
    "|------------------------------------------------------"
    "-----------------------------------------------|\n";
    printf ("| %-5d  ", position - 1);
    printf (" | %-17s ", node->title);
    printf ("| %-6d ", node->year);
    printf ("| %-22s ",  node->author);
    printf ("| %-25s ",  node->genre);
    printf ("| %-7d |\n", node->hours);
    cout << "|------------------------------------------------------"
    "-----------------------------------------------|\n" << endl;
}

typeSubject* miniAddElem(int position, typeSubject* head, int* sizeSubject) {
    typeSubject *newElem, *nextNewElem, *nextNode;

    newElem = new typeSubject;

    cout << "Title: ";
    cin >> newElem->title;
    cout << "Year: ";
    cin >> newElem->year;
    cout << "Director: ";
    cin >> newElem->author;
    cout << "Genre: ";
    cin >> newElem->genre;
    cout << "Duration: ";
    cin >> newElem->hours;
    node = head;
    if (position == 0) {
        head->prev = newElem;
        head = newElem;
        newElem->next = node;
        newElem->prev = nullptr;
        goto end;
    }
    if (position == *sizeSubject) {
        for (int i = 0; i < position - 1; i++)
            node = node->next;
        newElem->next = nullptr;
        newElem->prev = node;
        node->next = newElem;
        goto end;
    }
    for (int i = 0; i < position - 1; i++)
        node = node->next;
    nextNode = node->next;
    node->next = newElem;
    newElem->prev = node;
    nextNode->prev = newElem;
    newElem->next = nextNode;
    end:
    ++*sizeSubject;
    return head;
}

void sortAscendingName(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (strcmp(current->title, current->next->title) > 0) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortAscendingYear(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (current->year > current->next->year) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortAscendingFaculty(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (strcmp(current->author, current->next->author) > 0) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortAscendingCathedra(typeSubject*& head) {
    typeSubject	*current;

    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (strcmp(current->genre, current->next->genre) > 0) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortAscendingHours(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (current->hours > current->next->hours) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortDescendingName(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (strcmp(current->title, current->next->title) < 0) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortDescendingYear(typeSubject*& head) {
    typeSubject	*current;

    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (current->year < current->next->year) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortDescendingFaculty(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (strcmp(current->author, current->next->author) < 0) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortDescendingCathedra(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (strcmp(current->genre, current->next->genre) < 0) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void sortDescendingHours(typeSubject*& head) {
    typeSubject	*current;
    for (int i = 0; i < length(head) - 1; i++) {
        current = head;
        for (int j = 0; j < length(head) - 1 - i; j++) {
            if (current->hours < current->next->hours) {
                swap(head, current, current->next);
            } else
                current = current->next;
        }
    }
}

void swap(typeSubject*& head, typeSubject* firstElem, typeSubject* secondElem) {
    typeSubject *prevElem1 = firstElem->prev;
    typeSubject *prevElem2 = secondElem->prev;
    typeSubject	*nextElem1 = firstElem->next;
    typeSubject	*nextElem2 = secondElem->next;
    if (secondElem == nextElem1) {
        secondElem->next = firstElem;
        firstElem->prev = secondElem;
        firstElem->next = nextElem2;
        nextElem1->prev = prevElem1;
        if (prevElem1 != nullptr)
            prevElem1->next = secondElem;
        else
            head = secondElem;
    } else if (firstElem == nextElem2) {
        firstElem->next = secondElem;
        secondElem->prev = firstElem;
        secondElem->next = nextElem1;
        nextElem2->prev = prevElem2;
        if (prevElem2 != nullptr)
            prevElem2->next = firstElem;
        else
            head = firstElem;
    } else {
        firstElem->next = nextElem2;
        firstElem->prev = prevElem2;
        secondElem->next = nextElem1;
        if (prevElem1 != nullptr) {
            prevElem1->next = secondElem;
            secondElem->prev = prevElem1;
        } else {
            head = secondElem;
            secondElem->prev = nullptr;
        }
        if (nextElem1 != nullptr)
            nextElem1->prev = secondElem;
        if (prevElem2 != nullptr) {
            prevElem2->next = firstElem;
            firstElem->prev = prevElem2;
        } else {
            head = firstElem;
            firstElem->prev = nullptr;
        }
        if (nextElem2 != nullptr)
            nextElem2->prev = firstElem;
    }
}
