#include "String.h"
#include <iostream>
using namespace std;

String::String()
{
	
}

String::String(const char* _str)
{
	cout << "Using This Constructor!" << endl;
}

String::String(const String& _other)
{
	cout << "Using Moving Constructor!" << endl;
}

String::~String()
{
}

void String::Set_Text(const char* Input)
{
	strcpy_s(Text, 100, Input);
}

// Returns an integer representing the count of characters up to the null termination character
size_t String::Length() const
{
	cout << Text <<", Has " << strlen(Text) << " Letters." << endl;
	return size_t();
}

//Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'	
char& String::CharacterAt(size_t _index)
{
	cout << "Character At " << _index << ", " << Text[_index] << endl;
	return Text[_index];
}

////Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'	
//const char& String::CharacterAt(size_t _index) const
//{
//	// TODO: insert return statement here
//}

////Returns true if str contains the same characters.
bool String::EqualTo(const String& _other) const
{
	//cout << "Other Text: " << _other.Text << endl;
	//cout << Text << " " << _other.Text << endl;

	for (int i = 0; i < strlen(Text); i++) {
		if (Text[i] != _other.Text[i]) {
			return false;
		}

	}
	return true;
}

////Adds str to the end of the string
String& String::Append(const String& _str)
{
	strcat_s(Text, 100, " ");
	strcat_s(Text, 100, _str.Text);
	return *this;
}

////Adds str to the beginning of the string
String& String::Prepend(const String& _str)
{
	cout << "1) " << _str.Text << endl;
	char Temp[100] = "";
	strcat_s(Temp, 100, _str.Text);
	cout << "2) " << Temp << endl;
	strcat_s(Temp, 100, Text);
	cout << "3) " << Temp << endl;


	Text[0] =  '\0';
	strcat_s(Text, 100, Temp);

	return *this;
}


////Return the const char * that is useable with std::cout. eg: std::cout << str.cstr() << std::endl;
//const char* String::CStr() const
//{
//	return Text;
//}
 

////Convert all characters to lowercase
String& String::ToLower()
{
	for (int i = 0; i < strlen(Text); i++) {
		if (Text[i] >= 65 && Text[i] <= 90) {
			Text[i] += 32;
		}
		cout << Text[i] << " ";
	}
	return *this;
}


////Convert all characters to uppercase
String& String::ToUpper()
{
	for (int i = 0; i < strlen(Text); i++) {
		if (Text[i] >= 97 && Text[i] <= 122) {
			Text[i] -= 32;
		}
		cout << Text[i] << " ";
	}
	return *this;
}


////Returns the location of the findString. If not found, return -1
size_t String::Find(const String& _str)
{
	int Key_Num = 0;
	int Correct_In_Row = 0;

	int First_Index = -1;

	for (int i = 0; i < strlen(Text); i++) { // For Letters In Text
		if (Text[i] == _str.Text[Key_Num]) { // If Current Letter = First Letter Of Search Word
			if (First_Index == -1) { // Set Starting Spot For The Word
				First_Index = i;
			}
			Key_Num++; //Check The Next Letter
			Correct_In_Row++; 
			if (Correct_In_Row == strlen(_str.Text)) { //If Found The Whole Word
				cout << "Found Full Word, Starting With Letter: " << First_Index + 1 << endl;
				return First_Index;
			}

		}
		else { // Reset Search
			Key_Num = 0;
			Correct_In_Row = 0;
		}
	}

	cout << "Didn't Find Full Word" << endl;
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
		if (Text[i] == _str.Text[Key_Num]) {
			if (First_Index == -1) {
				First_Index = i;
			}
			Key_Num++;
			Correct_In_Row++;
			if (Correct_In_Row == strlen(_str.Text)) {
				cout << "Found Full Word, Starting With Letter: " << First_Index + 1 << endl;
				return First_Index;
			}

		}
		else {
			Key_Num = 0;
			Correct_In_Row = 0;
		}
	}

	cout << "Didn't Find Full Word" << endl;
	return -1;
}


////Replaces all occurrences of findString with replaceString
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

				//cout << "Found Full Word, Starting With Letter: " << First_Index << endl;
				for (int x = 0; x < strlen(_replace.Text); x++) {
					cout << x << ") Replacing, " << Text[First_Index+x] << " With" << _replace.Text[x] << endl;
					Text[First_Index + x] = _replace.Text[x];
				}
				Found_Word = true;
				break;
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
//
////Wait for input in the console window and store the result
//String& String::ReadFromConsole()
//{
//	// TODO: insert return statement here
//}
//
////Write the string to the console window
//String& String::WriteToConsole()
//{
//	// TODO: insert return statement here
//}
//
////Returns true if lhs == rhs.
//bool String::operator==(const String& _other)
//{
//	return false;
//}
//
////Returns true if lhs != rhs.
//bool String::operator!=(const String& _other)
//{
//	return false;
//}
//
////Replaces the characters in lhs with the characters in rhs.
//String& String::operator=(const String& _str)
//{
//	// TODO: insert return statement here
//}
//
////Returns the character located at position n.
//char& String::operator[](size_t _index)
//{
//	// TODO: insert return statement here
//}
//
////Returns the character located at position n.
//const char& String::operator[](size_t _index) const
//{
//	// TODO: insert return statement here
//}
