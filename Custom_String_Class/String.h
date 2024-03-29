#pragma once
#ifndef CUSTOM_STRING_HEADER
#define CUSTOM_STRING_HEADER

class String
{
public:
	String();
	String(const char* _str);
	String(const String& _other);

	~String();


public:

	void Set_Text(const char* Input);
	void Reset_Text(); //Reset Text For Testing

	size_t Length() const;
	char& CharacterAt(size_t _index);
	const char& CharacterAt(size_t _index) const;

	bool EqualTo(const String& _other) const;

	String& Append(const String& _str);
	String& Prepend(const String& _str);

	const char* CStr() const;

	String& ToLower();
	String& ToUpper();

	size_t Find(const String& _str);
	size_t Find(size_t _startIndex, const String& _str);

	String& Replace(const String& _find, const String& _replace);

	String& ReadFromConsole();
	String& WriteToConsole();


public:
	bool operator==(const String& _other);
	bool operator!=(const String& _other);

	bool operator < (const String & _other);

	String& operator=(const String& _str);

	char& operator >> (size_t _index); //Replaced [] With >>
	const char& operator >>(size_t _index) const;


public:
	char Text[100];

private:
	char Starting_Text[100];
};

#endif