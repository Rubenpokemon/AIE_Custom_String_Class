#include "String.h"

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

// Returns an integer representing the count of characters up to the null termination character
size_t String::Length() const
{
	return size_t();
}

//Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'	
char& String::CharacterAt(size_t _index)
{
	// TODO: insert return statement here
}

//Returns a char representing the character at the location. If index is less than 0 or greater than length, return '\0'	
const char& String::CharacterAt(size_t _index) const
{
	// TODO: insert return statement here
}

//Returns true if str contains the same characters.
bool String::EqualTo(const String& _other) const
{
	return false;
}

//Adds str to the end of the string
String& String::Append(const String& _str)
{
	// TODO: insert return statement here
}

//Adds str to the beginning of the string
String& String::Prepend(const String& _str)
{
	// TODO: insert return statement here
}

//Return the const char * that is useable with std::cout. eg: std::cout << str.cstr() << std::endl;
const char* String::CStr() const
{
	return nullptr;
}


//Convert all characters to lowercase
String& String::ToLower()
{
	// TODO: insert return statement here
}


//Convert all characters to uppercase
String& String::ToUpper()
{
	// TODO: insert return statement here
}


//Returns the location of the findString. If not found, return -1
size_t String::Find(const String& _str)
{
	return size_t();
}

//Returns the location of the findString. If not found, return -1
size_t String::Find(size_t _startIndex, const String& _str)
{
	return size_t();
}

//Replaces all occurrences of findString with replaceString
String& String::Replace(const String& _find, const String& _replace)
{
	// TODO: insert return statement here
}

//Wait for input in the console window and store the result
String& String::ReadFromConsole()
{
	// TODO: insert return statement here
}

//Write the string to the console window
String& String::WriteToConsole()
{
	// TODO: insert return statement here
}

//Returns true if lhs == rhs.
bool String::operator==(const String& _other)
{
	return false;
}

//Returns true if lhs != rhs.
bool String::operator!=(const String& _other)
{
	return false;
}

//Replaces the characters in lhs with the characters in rhs.
String& String::operator=(const String& _str)
{
	// TODO: insert return statement here
}

//Returns the character located at position n.
char& String::operator[](size_t _index)
{
	// TODO: insert return statement here
}

//Returns the character located at position n.
const char& String::operator[](size_t _index) const
{
	// TODO: insert return statement here
}
