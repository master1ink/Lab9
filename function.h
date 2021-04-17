#include <cstdlib>
#include <cstring>

typedef struct movie {
    char title[50];
    int year, hours;
    char author[50];
    char genre[50];

    struct movie *next;
    struct movie *prev;
} typeSubject;

typeSubject* createMemory(typeSubject* head, int* sizeSubject);
typeSubject* inputKeyboard(typeSubject* head, int sizeSubject);
void searchLocationElement(typeSubject* head, int sizeSubject);
typeSubject* sortArray(typeSubject* head, int sizeSubject);
typeSubject* editElem(typeSubject* head, int sizeSubject);
typeSubject* exchangeElem(typeSubject* head, int sizeSubject);
typeSubject* addElem(typeSubject* head, int* sizeSubject);
typeSubject* deleteTargetElem(typeSubject* head, int* sizeSubject);
typeSubject* addNewElem(typeSubject* head, int* sizeSubject);
void addressLast(typeSubject* head, int sizeSubject);
int length(typeSubject* head);
void split(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2);
void unite(typeSubject*& head, typeSubject*& head1, typeSubject*& head2, int* sizeSubject, int* sizeSubject1, int* sizeSubject2);
void writeFile(typeSubject* head, int sizeSubject);
void readFile(typeSubject* head, int sizeSubject);
typeSubject* readDateFromFile(typeSubject* head, int* sizeSubject);
void subjectPrintMain(typeSubject* head, typeSubject* head1, typeSubject* head2, int sizeSubject, int sizeSubject1, int sizeSubject2);
void freeMemory(typeSubject*& head, typeSubject*& head1, typeSubject*& head2);
void subjectPrint(typeSubject* head, int sizeSubject, int sortNumber);
void print (typeSubject *node, int position);
void sortAscendingName(typeSubject*& head);
void sortAscendingYear(typeSubject*& head);
void sortAscendingFaculty(typeSubject*& head);
void sortAscendingCathedra(typeSubject*& head);
void sortAscendingHours(typeSubject*& head);
void sortDescendingName(typeSubject*& head);
void sortDescendingYear(typeSubject*& head);
void sortDescendingFaculty(typeSubject*& head);
void sortDescendingCathedra(typeSubject*& head);
void sortDescendingHours(typeSubject*& head);
void swap(typeSubject*& head, typeSubject* firstElem, typeSubject* secondElem);
typeSubject* miniAddElem(int position, typeSubject* head, int* sizeSubject);
