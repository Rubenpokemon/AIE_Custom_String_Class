
#include <iostream>
#include "String.h"

using namespace std;

int main()
{
    String* String_Class_01 = new String;
    char Text_01[100] = "This Is Testing RN";
    String_Class_01->Set_Text(Text_01);

    String* String_Class_02 = new String;
    char Text_02[20] = "Test";
    String_Class_02->Set_Text(Text_02);

    String* String_Class_03 = new String;
    char Text_03[20] = "Work";
    String_Class_03->Set_Text(Text_03);

    String_Class_01->Replace(*String_Class_02, *String_Class_03);
    cout << String_Class_01->Text << endl;
}
