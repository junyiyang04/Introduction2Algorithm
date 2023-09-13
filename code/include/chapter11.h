#include <iostream>
#include "export_macro.h"
#include "chapter10.h"
enum HashFunc
{
    DIRECT = 0,
    DIVISION,
    MULTIPLICATION
};

typedef struct _Key_Value_
{
    int key;
    int value;
}Key_Value;

typedef struct _Hash_Table_
{
    DLNode* head;
    int size;
};



