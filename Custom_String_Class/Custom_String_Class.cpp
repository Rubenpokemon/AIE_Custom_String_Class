
#include <iostream>
#include "String.h"
using namespace std;

void Test();

int main()
{
    Test();
    //String* String_Class_01 = new String;
    //char Text_01[100] = "Starting Text";
    //String_Class_01->Set_Text(Text_01);

    //String* String_Class_02 = new String;
    //char Text_02[50] = "Test";
    //String_Class_02->Set_Text(Text_02);

    //String* String_Class_03 = new String; //Used For Replace Function
    //char Text_03[50] = "Work";
    //String_Class_03->Set_Text(Text_03);
    //
    ////cout << "-> " << String_Class_01->Text[0] << endl;
    ////char First = String_Class_01[0];
    ////String_Class_01[0];

    //char First = *String_Class_01 >> 1;
    //cout << "First Letter, " << First << endl;
    //String_Class_01->WriteToConsole();
}

void Test() {
    String* Str01 = new String;
    Str01->Set_Text("Hello");


    String* Str02 = new String;
    Str02->Set_Text("Hello");


    String* Str03 = new String;
    Str03->Set_Text("Bye");


    cout << "Word 1; " << Str01->Text << " Word 2; " << Str02->Text << " Word 3; " << Str03->Text << endl;


    Str01->Length();


    Str01->CharacterAt(2);


    if (Str01->EqualTo(*Str02)) { cout << Str01->Text << " Is Equal To " << Str02->Text << endl; }
    else { cout << Str01->Text <<" Is Not Equal To "<< Str02->Text << endl; }


    Str01->Append(*Str02);
    cout << "Appended Word: " << Str01->Text << endl;


    Str01->Reset_Text();
    Str01->Prepend(*Str02);
    cout << "Prepended Word: " << Str01->Text << endl;


    Str01->Reset_Text();
    Str01->ToUpper();
    cout << "Uppercase: " << Str01->Text << endl;


    Str01->Reset_Text();
    Str01->ToLower();
    cout << "Lowercase: " << Str01->Text << endl;

    Str01->Reset_Text();
    int Temp = Str01->Find(*Str02);
    if (Temp != -1) { cout << "Found Full Word Starting With Letter, " << Temp + 1 << endl; }
    else { cout << "Didn't Find Full Word" << endl; }


    Temp = Str01->Find(3,*Str02);
    if (Temp != -1) { cout << "Found Full Word Starting With Letter, " << Temp + 1 << " Starting At Letter, "<< 2 << endl; }
    else { cout << "Didn't Find Full Word" " Starting At Letter, " << 2 << endl; }

    
    String* Str04 = new String;
    Str04->Set_Text("llo");
    Str01->Replace(*Str04, *Str03);
    cout << "Replaced, " << Str04->Text << " With " << Str03->Text << " -> " << Str01->Text << endl;


    Str01->Reset_Text();
    if (*Str01 == *Str02) { cout << "== " << Str01->Text << " And " << Str02->Text << " Are Equal" << endl; }
    else { cout << "== " << Str01->Text << " And " << Str02->Text << " Are Not Equal" << endl; }


    if (*Str01 != *Str02) { cout << "!= " << Str01->Text << " And " << Str02->Text << " Are Not Equal" << endl; }
    else { cout << "!= " << Str01->Text << " And " << Str02->Text << " Are Equal" << endl; }


    char Char_Temp = *Str01 >> 1;
    cout << Char_Temp << " Is The Second Letter" << endl;


    Str01->Reset_Text();
    if (Str01 < Str02) { cout << Str01->Text << " Comes Before " << Str02->CStr() << " In The Alphabet" << endl;}
    else { cout << Str01->CStr() << " Doesn't Come Before " << Str02->CStr() << " In The Alphabet" << endl; }


    Str01 = Str02;
    cout << Str01->CStr() << " Is Now Equal To " << Str02->Text << endl;


    cout << "Read From Console: ";
    Str01->ReadFromConsole();


    cout << "\nWriting To Console: ";
    Str01->WriteToConsole();
}


