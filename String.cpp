#include <stdio.h>
#include <stdarg.h>
#include <wtypes.h>

#include "string.h"

#define TMP_STRING_SIZE 4096

void String::alloc(int required_memory) {
	allocated_memory = required_memory;
	string = new char[allocated_memory];
}

String::String()
{
	alloc(1);
	string[0] = '\0';
}

String::String(unsigned int requiered_memory)
{
	alloc(requiered_memory);
	string[0] = '\0';
}

String::String(const char* format, ...)
{
	allocated_memory = 0;
	if (format != NULL)
	{
		static char tmp[TMP_STRING_SIZE];
		static va_list ap;
		// Construct the string from variable arguments
		va_start(ap, format);
		int res = vsprintf_s(tmp, TMP_STRING_SIZE, format, ap);
		va_end(ap);
		if (res > 0)
		{
			alloc(res + 1);
			strcpy_s(string, allocated_memory, tmp);
		}
	}
	if (allocated_memory == 0)
	{
		alloc(1);
		clear();
	}
}

String::String(const String &new_string)
{
	allocated_memory = new_string.allocated_memory;
	string = new char[allocated_memory];
	strcpy_s(string, allocated_memory, new_string.string);
}

String::~String() {
	delete[] string;
}

bool String::operator== (const String &str_to_compare) const
{
	return strcmp(string, str_to_compare.string) == 0;
}

bool String::operator== (const char *str_to_compare) const
{
	if (str_to_compare != NULL)
		return strcmp(string, str_to_compare) == 0;
	return false;	
}

bool String::operator!= (const String &str_to_compare) const
{
	return strcmp(string, str_to_compare.string) != 0;
}

bool String::operator!= (const char *str_to_compare) const
{
	if (str_to_compare != NULL)
		return strcmp(string, str_to_compare) != 0;
	return true;
}

const String& String::operator= (const String &str_to_assign)
{
	if (str_to_assign.allocated_memory > allocated_memory)
	{
		delete[] string;
		alloc(allocated_memory);
	}

	strcpy_s(string, allocated_memory, str_to_assign.string);
	return (*this);
}

const String& String::operator= (const char *str_to_assign)
{
	if (str_to_assign != NULL)
	{
		if (strlen(str_to_assign) + 1 > allocated_memory)
		{
			delete[] string;
			alloc(strlen(str_to_assign) + 1);
		}

		strcpy_s(string, allocated_memory, str_to_assign);
	}
	else
		clear();

	return (*this);
}

const String& String::operator+= (const String &str_to_concatenate)
{
	
	char *str_tmp = string;
	allocated_memory = strlen(str_to_concatenate.string) + 1 + allocated_memory;
	
	char *tmp = new char[allocated_memory];
	strcpy_s(tmp, allocated_memory, str_tmp);
	strcat_s(tmp, allocated_memory, str_to_concatenate.string);
	
	delete[] string;
	string = tmp;

	return (*this);
}

const String& String::operator+= (const char *str_to_concatenate)
{
	if (str_to_concatenate != NULL)
	{
		char *str_tmp = string;
		allocated_memory = strlen(str_to_concatenate) + 1 + allocated_memory;

		char *tmp;
		tmp = new char[allocated_memory];
		strcpy_s(tmp, allocated_memory, str_tmp);
		strcat_s(tmp, allocated_memory, str_to_concatenate);

		delete[] string;
		string = tmp;
	}

	return (*this);	
}

// No comprovem si el propi atribut string ja té l'espai necessari
// per afegir el prefix. També es podria comprovar si la cadena la 
// qual serà el prefix està buida. No hauriem de fer res.
// També hauriem de comprovar que la cadena de la propia clase que 
// crida el mètode també pot estar buit.

// Si ja tenim espai, podem:
// Anar caràcter a caràcter, movent-los per encabir-los tots.
// O una funció anomendada memcpy, on només copien memòria, evitant 
// copia el zero terminal.

const String& String::prefix(const String &str_to_prefix)
{
	char *str_tmp = string;
	unsigned int allocated_memory_tmp = allocated_memory;
	allocated_memory = strlen(str_to_prefix.string) + allocated_memory_tmp + 1;

	char *tmp;
	tmp = new char[allocated_memory];
	strcpy_s(tmp, allocated_memory, str_to_prefix.string);
	strcat_s(tmp, allocated_memory, str_tmp);

	delete[] string;
	string = tmp;

	return (*this);
}

const String& String::prefix(const char *str_to_prefix)
{
	if (str_to_prefix != NULL)
	{
		char *str_tmp = string;
		unsigned int allocated_memory_tmp = allocated_memory;
		allocated_memory = strlen(str_to_prefix) + allocated_memory_tmp + 1;

		char *tmp;
		tmp = new char[allocated_memory];
		strcpy_s(tmp, allocated_memory, str_to_prefix);
		strcat_s(tmp, allocated_memory, str_tmp);

		delete[] string;
		string = tmp;
	}
	else
		clear();

	return (*this);
}

void String::trim()
{
	char *start = string;
	char *end = &string[strlen(string) - 1];

	// We check the first and last blanks..
	while (*start == ' ') { start++; }
	while (*end == ' ') { end--; }

	for (unsigned int i = 0; start <= end; i++)
	{
		string[i] = *(start++);
	}
	*(start) = '\0';
}

unsigned int String::find(const char *str_to_find)
{
	unsigned int matches = 0;
	if (str_to_find != NULL)
	{
		unsigned int str_to_find_length = strlen(str_to_find);
		unsigned int string_length = strlen(string) + 1 - str_to_find_length;

		for (unsigned int i = 0; i < string_length; i++)
		{
			if (strncmp((string + i), str_to_find, str_to_find_length) == 0)
				matches++;
		}
	}

	return matches;
}

const String& String::replace(const String &str_to_substitute, const String &new_string)
{
	return (*this);
}

unsigned int String::getLength() const
{
	return strlen(string);
}

const char* String::getString() const
{
	return string;
}

unsigned int String::capacity() const
{
	return allocated_memory;
}

void String::clear()
{
	string[0] = '\0';
}



