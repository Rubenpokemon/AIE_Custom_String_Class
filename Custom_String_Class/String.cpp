#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
	
}

String::String(const char* _str)
{
	
}

String::String(const String& _other)
{
	
}

String::~String()
{
	
}

void String::Set_Text(const char* Input) //Set Current Text And Defualt Text(For Testing)
{
	strcpy_s(Starting_Text, 100, Input);
	strcpy_s(Text, 100, Input);
}

void String::Reset_Text() //Reset Current Text To Defualt 
{
	strcpy_s(Text, 100, Starting_Text);
}

// Returns an integer representing the count of characters up to the null termination character
size_t String::Length() const
{
	return strlen(Text);
}

//Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'	
char& String::CharacterAt(size_t _index)
{
	if (_index <0 || _index > Length()) { //If < 0 Or > Length, Return 0(\0)
		static char s = 0;
		return s; 
	}
	return Text[_index];
}

//Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'	
const char& String::CharacterAt(size_t _index) const
{
	if (_index <0 || _index > Length()) { //If < 0 Or > Length, Return 0(\0)
		static char s = 0;
		return s;
	}
	return Text[_index];
}

////Returns true if str contains the same characters.
bool String::EqualTo(const String& _other) const
{
	if (strcmp(Text, _other.Text) == 0) {
		return true;
	}
	else {
		return false;
	}
}

////Adds str to the end of the string
String& String::Append(const String& _str)
{
	strcat_s(Text, 100, " "); //Add Space Between Words
	strcat_s(Text, 100, _str.Text);
	return *this;
}

////Adds str to the beginning of the string
String& String::Prepend(const String& _str)
{

	char Temp[100] = "";
	strcat_s(Temp, 100, _str.Text); //Set Temp To Input Word
	strcat_s(Temp, 100, " "); // Add Space
	strcat_s(Temp, 100, Text); //Add Starting Word To Temp

	Text[0] =  '\0'; //Reset Text
	strcat_s(Text, 100, Temp);//Set Text To Temp

	return *this;
}


////Return the const char * that is useable with std::cout. eg: std::cout << str.cstr() << std::endl;
const char* String::CStr() const
{
	return Text;
}
 

////Convert all characters to lowercase
String& String::ToLower()
{
	for (int i = 0; i < strlen(Text); i++) { //For Each Letter
		if (Text[i] >= 65 && Text[i] <= 90) { //If Letter Is Lowercase In Ascii
			Text[i] += 32; //Add 32 To Make It A Capital Letter
		}
	}
	return *this;
}


////Convert all characters to uppercase
String& String::ToUpper()
{
	for (int i = 0; i < strlen(Text); i++) { //For Each Letter
		if (Text[i] >= 97 && Text[i] <= 122) {//If Letter Is Uppercase In Ascii
			Text[i] -= 32;//Substract 32 To Make It A Lowercase Letter
		}
	}
	return *this;
}


////Returns the location of the findString. If not found, return -1
size_t String::Find(const String& _str)
{
	if (Text == _str.Text) { return 0; }
	int Key_Num = 0;
	int Correct_In_Row = 0;

	int First_Index = -1;

	for (int i = 0; i < strlen(Text); i++) { // For Letters In Text
		if (Text[i] == _str.Text[Key_Num]) { // If Current Letter = First Letter Of Search Word
			if (First_Index == -1) { // Set Starting Spot For The Word
				First_Index = i;
			}
			Key_Num++; //Check The Next Letter
			Correct_In_Row++; //Correct Letters In A Row
			if (Correct_In_Row == strlen(_str.Text)) { //If Found The Whole Word
				return First_Index;
			}

		}
		else { // Reset Search
			Key_Num = 0;
			Correct_In_Row = 0;
			First_Index = -1;
		}
	}

	return -1;
}

//Returns the location of the strToFind.Beginning the search from startIndex.If not found, return -1
size_t String::Find(size_t _startIndex, const String& _str)
{
	// Same As Above But With i = Index
	int Key_Num = 0;
	int Correct_In_Row = 0;

	int First_Index = -1;

	for (int i = _startIndex; i < strlen(Text); i++) {
		if (Text[i] == _str.Text[Key_Num]) { // For Letters In Text
			if (First_Index == -1) { // If Current Letter = First Letter Of Search Word
				First_Index = i; // Set Starting Spot For The Word
			}
			Key_Num++; //Check The Next Letter
			Correct_In_Row++; //Correct Letters In A Row
			if (Correct_In_Row == strlen(_str.Text)) { //If Found The Whole Word
				return First_Index;
			}

		}
		else { // Reset Search
			Key_Num = 0;
			Correct_In_Row = 0;
			First_Index = -1;
		}
	}
	return -1;
}


//Replaces all occurrences of findString with replaceString
String& String::Replace(const String& _find, const String& _replace)
{

		

	int Key_Num = 0;
	int Correct_In_Row = 0;

	int First_Index = -1;
	bool Found_Word = false;

	for (int i = 0; i < strlen(Text); i++) { // For Letters In Text
		if (Text[i] == _find.Text[Key_Num]) { // If Current Letter = First Letter Of Search Word
			if (First_Index == -1) { // Set Starting Spot For The Word
				First_Index = i;
			}
			Key_Num++; //Check The Next Letter
			Correct_In_Row++;
			if (Correct_In_Row == strlen(_find.Text)) { //If Found The Whole Word
				for (int x = 0; x < strlen(_replace.Text); x++) {//cout << x << ") Replacing, " << Text[First_Index+x] << " With" << _replace.Text[x] << endl;
					Text[First_Index + x] = _replace.Text[x];
				}
				Found_Word = true;
				break; //End Loop 
			}
		}
		else { // Reset Search
			Key_Num = 0;
			Correct_In_Row = 0;
			First_Index = -1;
		}
	}

	if (Found_Word == true){ Replace(_find, _replace); } //Redo Function Until No More Words Found

	return *this;
}

//Wait for input in the console window and store the result
String& String::ReadFromConsole()
{
	char Temp[100];
	cin >> Temp;
	strcpy_s(Text, 100, Temp);

	return *this;
}

//Write the string to the console window
String& String::WriteToConsole()
{
	cout << CStr() << endl;
	return *this;
}



//Returns true if lhs == rhs.
bool String::operator == (const String& _other)
{
	if (strcmp(Text, _other.Text) == 0) {
		return true;
	}
	else {
		return false;
	}
}

//Returns true if lhs != rhs.
bool String::operator!=(const String& _other)
{
	if (strcmp(Text, _other.Text) == 0) {
		return false;
	}
	else {
		return true;
	}
}

bool String::operator<(const String& _other)
{
	if (this->Text < _other.Text) {
		return true;
	}
	return false;
}

//Replaces the characters in lhs with the characters in rhs.
String& String::operator=(const String& _str)
{
	strcpy_s(Text, 100, _str.Text);
	return *this;
}

//Returns the character located at position n.
char& String::operator >> (size_t _index)
{
	return Text[_index];
}

const char& String::operator>>(size_t _index) const
{
	return Text[_index];
}




