#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>
#include <fstream>
#include <string>
#include "String.h"
using namespace std;

void Test();

void WriteFile(const String& File, const String& txt) {
    cout << "Read File, " << File.CStr() << endl;
    ofstream writefile;
    writefile.open(File.CStr(), fstream::app);
    writefile << txt.CStr();
    writefile.close();
}

string ReadFile(string fileName) {
    string line;
    ifstream readfile(fileName);
    if (readfile.is_open()) {
        getline(readfile, line);
        readfile.close();
    }
    return line;
}

//void WriteFile(string fileName, string txt) {
//    ofstream writefile;
//    writefile.open(fileName, fstream::app);
//    writefile << txt;
//    writefile.close();
//}

//string ReadFile(string fileName) {
//    string line;
//    ifstream readfile(fileName);
//    if (readfile.is_open()) {
//        getline(readfile, line);
//        readfile.close();
//    }
//    return line;
//}

int main()
{
    // Print Time
   /* time_t now = time(0);
    tm* ltm = localtime(&now);
    char* dt = ctime(&now);
    cout << ltm->tm_mday << "/" << ltm->tm_mon + 1 << "/" << 1900 + ltm->tm_year << "   Time: " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;*/
    
    String* File = new String();
    File->Set_Text("Output.txt");

    String* Test = new String();
    Test->Set_Text("This Is From A String Class");

    //Test();
    WriteFile(*File, *Test);
    //WriteFile("Output.txt", "SecondLineOfText\n");
    //WriteFile("Output.txt", "THIRD\n");
    //cout << ReadFile("Output.txt") << endl;
}

void Test() {
    //Set First Word
    String* Str01 = new String;
    Str01->Set_Text("Hello");

    //Set Second Word
    String* Str02 = new String;
    Str02->Set_Text("World");


    //Print Words
    cout << "Word 1'" << Str01->Text << "' Word 2'" << Str02->Text << endl;


    //Test Length
    cout << Str01->CStr() << ", Has " << Str01->Length() << " Letters." << endl;


    //Character At Test
    cout << "Character At Index " << 2 << ", " << Str01->CharacterAt(2) << endl;

    //EqualTo Test
    if (Str01->EqualTo(*Str02)) { cout << Str01->Text << " Is Equal To " << Str02->Text << endl; }
    else { cout << Str01->Text <<" Is Not Equal To "<< Str02->Text << endl; }

    //Append Test
    Str01->Append(*Str02);
    cout << "Appended Word: " << Str01->CStr() << endl;

    //Prepend Test
    Str01->Reset_Text();
    Str01->Prepend(*Str02);
    cout << "Prepended Word: " << Str01->CStr() << endl;

    //ToUpper Test
    Str01->Reset_Text();
    Str01->ToUpper();
    cout << "Uppercase: " << Str01->CStr() << endl;

    //ToLower Test
    Str01->Reset_Text();
    Str01->ToLower();
    cout << "Lowercase: " << Str01->CStr() << endl;

    //Find Test
    Str01->Reset_Text();
    int Temp = Str01->Find(*Str02);
    if (Temp != -1) { cout << "Found Full Word Starting With Letter, " << Temp + 1 << endl; }
    else { cout << "Didn't Find Full Word" << endl; }

    //Find Test With Index
    Temp = Str01->Find(3,*Str02);
    if (Temp != -1) { cout << "Found Full Word Starting With Letter, " << Temp + 1 << " Starting At Letter, "<< 2 << endl; }
    else { cout << "Didn't Find Full Word" " Starting At Letter, " << 2 << endl; }

    //Replace Test
    String* Str03 = new String; //String To Be Replace
    Str03->Set_Text("llo");

    String* Str04 = new String; //String To Be Replaced With
    Str04->Set_Text("bye");

    Str01->Replace(*Str03, *Str04);
    cout << "Replaced, " << Str04->Text << " With " << Str03->Text << " -> " << Str01->Text << endl;

    // == Test
    Str01->Reset_Text();
    if (*Str01 == *Str02) { cout << "== " << Str01->Text << " And " << Str02->Text << " Are Equal" << endl; }
    else { cout << "== " << Str01->Text << " And " << Str02->Text << " Are Not Equal" << endl; }

    // != Test
    if (*Str01 != *Str02) { cout << "!= " << Str01->Text << " And " << Str02->Text << " Are Not Equal" << endl; }
    else { cout << "!= " << Str01->Text << " And " << Str02->Text << " Are Equal" << endl; }

    // []/>> Test
    char Char_Temp = *Str01 >> 1;
    cout << Char_Temp << " Is The Second Letter" << endl;

    // < Test
    Str01->Reset_Text();
    if (Str01 < Str02) { cout << Str01->Text << " Comes Before " << Str02->CStr() << " In The Alphabet" << endl;}
    else { cout << Str01->CStr() << " Doesn't Come Before " << Str02->CStr() << " In The Alphabet" << endl; }

    // = Test
    Str01 = Str02;
    cout << Str01->CStr() << " Is Now Equal To " << Str02->Text << endl;

    //Read From Console Test
    cout << "Read From Console: ";
    Str01->ReadFromConsole();

    //Write To Console Test
    cout << "\nWriting To Console: ";
    Str01->WriteToConsole();
}


