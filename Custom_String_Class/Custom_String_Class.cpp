#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <fstream>
#include <string> //Used For Printing Date
#include "String.h"
using namespace std;

void Test();
void Print_Date();

String* File = new String();

int main()
{
    File->Set_Text("Output.txt");
    
    Print_Date();


    Test();
    //WriteFile(*File, *Test);
}


void Test() {

    ofstream writefile; //Open File
    writefile.open("Output.txt", fstream::app);

    //Set First Word
    String* Str01 = new String;
    cout << " - Enter Word 1 - " << endl;
    Str01->ReadFromConsole();
    Str01->Set_Text(Str01->CStr());

    //Set Second Word
    String* Str02 = new String;
    cout << " - Enter Word 2 - " << endl;
    Str02->ReadFromConsole();
    Str02->Set_Text(Str02->CStr());

    writefile << "Word 1 = " << Str01->CStr() << "  Word 2 = " << Str02->CStr() << endl;

    //Print Words


    //Test Length
    writefile << "Test 1 Length | " << Str01->CStr() << ", Has " << Str01->Length() << " Letters." << "," << endl;


    //Character At Test
    writefile << "Test 2 CharacterAt | " << Str01->CharacterAt(2) << ", Is In Index " << 2 <<  endl;
  


    //EqualTo Test
    if (Str01->EqualTo(*Str02)) {  writefile << "Test 3 EqualTo |  " << Str01->Text << " Is Equal To " << Str02->Text <<  endl; }
    else { writefile << "Test 3 EqualTo |  " << Str01->Text << " Is Not Equal To " << Str02->Text <<  endl; }
 


    //Append Test
    Str01->Append(*Str02);
    writefile << "Test 4 Append | " << Str01->CStr() << endl;



    //Prepend Test
    Str01->Reset_Text();
    Str01->Prepend(*Str02);
    writefile << "Test 5 Prepend | " << Str01->CStr() << endl;

    //ToUpper Test
    Str01->Reset_Text();
    Str01->ToUpper();
    writefile << "Test 6 Uppercase | " << Str01->CStr() << endl;

    //ToLower Test
    Str01->Reset_Text();
    Str01->ToLower();
    writefile << "Test 7 Lowercase | " << Str01->CStr() << endl;

    //Find Test
    Str01->Reset_Text();
    int Temp = Str01->Find(*Str02);
    if (Temp != -1) { writefile << "Test 8 Find | Found Full Word Starting With Letter, " << Temp + 1 << endl; }
    else { writefile << "Test 8 Find | Didn't Find " << Str02->CStr() << " In " << Str01->CStr() << endl; }

    //Find Test With Index
    Temp = Str01->Find(3,*Str02);
    if (Temp != -1) { writefile << "Test 9 Find(Index) | Found Full Word Starting With Letter, " << Temp + 1 << " Starting At Letter, "<< 2 << endl; }
    else { writefile << "Test 9 Find(Index) | Didn't Find " << Str02->CStr() << " In " << Str01->CStr() << " Starting At Letter, " << 2 << endl; }

    //Replace Test
    Str01->Reset_Text();
    String* Str03 = new String; //String To Be Replace
    Str03->Set_Text("e");

    String* Str04 = new String; //String To Be Replaced With
    Str04->Set_Text("a");


   // if (Str01->Find(*Str03) == -1) { writefile << "Test 10 Replace | Couldn't Find " << Str03->Text << " In " << Str01->Text << endl; }
    Str01->Replace(*Str03, *Str04);
    writefile << "Test 10 Replace | Replaced, " << Str03->Text << " With " << Str04->Text << " -> " << Str01->Text << endl; 
    // == Test
    Str01->Reset_Text();
    if (*Str01 == *Str02) { writefile << "Test 11 == | " << Str01->Text << " And " << Str02->Text << " Are Equal" << endl; }
    else { writefile << "Test 11 | == " << Str01->Text << " And " << Str02->Text << " Are Not Equal" << endl; }

    // != Test
    if (*Str01 != *Str02) { writefile << "Test 12 != | " << Str01->Text << " And " << Str02->Text << " Are Not Equal" << endl; }
    else { writefile << "Test 12 != | " << Str01->Text << " And " << Str02->Text << " Are Equal" << endl; }

    // []/>> Test
    char Char_Temp = *Str01 >> 1;
    writefile << "Test 13 [] | " << Char_Temp << " Is The Second Letter" << endl;

    // < Test
    Str01->Reset_Text();
    if (Str01 < Str02) { writefile << "Test 14 < | " << Str01->Text << " Comes Before " << Str02->CStr() << " In The Alphabet" << endl; }
    else { writefile << "Test 14 [] | " << Str01->CStr() << " Doesn't Come Before " << Str02->CStr() << " In The Alphabet" << endl; }

    // = Test
    Str01 = Str02;
    writefile << "Test 15 = | " << Str01->CStr() << "(Str01) Is Now Equal To " << Str02->Text << "(Str02)" << endl;

    //Read From Console Test
    cout << "Read From Console: ";
    Str01->ReadFromConsole();
    writefile << "Test 15 ReadFromConsole | " << Str01->CStr() << endl;

    //Write To Console Test
    cout << "\nWriting To Console: ";
    Str01->WriteToConsole();

    writefile << "\n\n\n";

    writefile.close();
}


void Print_Date() {
    time_t now = time(0);
    tm* ltm = localtime(&now);
    char* dt = ctime(&now);//cout << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << 1900 + ltm->tm_year << "   Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;

    ofstream writefile; //Open File
    writefile.open("Output.txt", fstream::app);
    writefile << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << 1900 + ltm->tm_year << "   Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;



}
