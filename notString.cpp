#include "notString.h"
#include <iostream>
#include <cstring>
using namespace std;

notString::notString() : str{nullptr }
{
    str = new char[1];
    str[0] = '\0';
}
notString::notString (const char* c) {
    int length = strlen(c);
    str = new char[length + 1];
    strcpy(str, c);
    str [length] = '\0';
}
notString::notString(char* c)
{
    if (c == nullptr) {
        str = new char[1];
        str[0] = '\0';
    }

    else {

        str = new char[strlen(c) + 1];
        strcpy(str, c);
        str[strlen(c)] = '\0';

    }
}
// Copy Constructor
notString::notString(const notString& source)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
    str[strlen(source.str)] = '\0';
}

// Move Constructor
notString::notString(notString&& source)
{
    str = source.str;
    source.str = nullptr;
}

//operator +=
notString& notString::operator+=(const notString& rhs)
{
    int length = strlen(str)+ strlen(rhs.str);

    char* buff = new char[length + 1];

    strcpy(buff, str);
    strcat(buff, rhs.str);
    buff[length] = '\0';
    str=buff;
    return *this;
}
notString& notString::operator+= (char c) {
    int temp =this->length();
    str[temp]=c;
    str[temp+1]='\0';
    return *this;
}
notString& notString::operator+= (const char* c) {
    int length = strlen(this->str)+ strlen(c);
    char* buff = new char[length + 1];

    strcpy(buff, this->str);
    strcat(buff, c);
    buff[length] = '\0';

    str=buff;

    return *this;
}

//operator +
notString operator+(const notString& lhs, const notString& rhs)
{
    int length = strlen(lhs.str)+ strlen(rhs.str);

    char* buff = new char[length + 1];

    strcpy(buff, lhs.str);
    strcat(buff, rhs.str);
    buff[length] = '\0';

    notString temp{buff };

    delete[] buff;

    return temp;
}
notString operator+(const notString& lhs, char c) {
    notString temp =lhs;
    temp+=c;
    return temp;
}
notString operator+(char c, const notString& rhs) {
    int length =strlen(rhs.str)+2;
    char* buff = new char[length];
    buff[0]=c;
    strcat(buff, rhs.str);
    buff[length] = '\0';

    notString temp{buff };

    delete[] buff;

    return temp;
}
notString operator+(const char* c, const notString& rhs)
{
    int length = strlen(c)+ strlen(rhs.str);

    char* buff = new char[length + 1];

    strcpy(buff, c);
    strcat(buff, rhs.str);
    buff[length] = '\0';

    notString temp{buff };

    delete[] buff;

    return temp;
}
notString operator+(const notString& lhs, const char* c) {
    notString temp =lhs;
    temp+=c;
    return temp;
}

//input and output operators
istream& operator>>(istream& is, notString& obj)
{
    char* buff = new char[1000];
    memset(&buff[0], 0, sizeof(buff));
    is >> buff;
    obj = notString{buff };
    delete[] buff;
    return is;
}
ostream& operator<<(ostream& os,const notString& obj)
{
    os << obj.str;
    return os;
}

char& notString::operator[](size_t pos)const{
    return *(str+pos);
}

const char* notString::c_str() const {
    return str;
}

int notString::length() const
{
    return strlen(str);
}

//comparison operators
int notString::compare(const notString & rhs) const {

    if (this->length() < rhs.length())
        return 1;
    else if (this->length() > rhs.length())
        return -1;

    return strcmp(str, rhs.str);
}
bool operator == (const notString & lhs, const notString & rhs) {
    return lhs.compare(rhs) == 0;
}
bool operator != (const notString & lhs, const notString & rhs) {
    return lhs.compare(rhs) != 0;
}
bool operator < (const notString & lhs, const notString & rhs) {
    return lhs.compare(rhs) > 0;
}
bool operator > (const notString & lhs, const notString & rhs) {
    return lhs.compare(rhs) < 0;
}
bool operator <= (const notString & lhs, const notString & rhs) {
    return lhs.compare(rhs) >= 0;
}
bool operator >= (const notString & lhs, const notString & rhs) {
    return lhs.compare(rhs) <= 0;
}

//operator =
notString& notString::operator= (const char* c) {
    strcpy(str, c);
    return *this;
}

notString& notString::operator=(const notString& rhs)
{
    if (this == &rhs)
        return *this;
    delete[] str;
    str = new char[strlen(rhs.str) + 1];
    strcpy(str, rhs.str);
    return *this;
}

//find function
size_t notString::_find(const char* other, size_t len, size_t pos) const {

    size_t toReturn = -1;

    for (; pos <= this->length() - len; ++pos)
        if (str[pos] == *other and _find_compare(other, len, pos)) {
            toReturn = pos;
            break;
        }
    return toReturn;
}
bool notString::_find_compare(const char * other, size_t len, size_t pos) const {
    for (size_t i = 1; i < len; ++i)
        if (str[pos + i] != *(other + i))
            return false;
    return true;
}
size_t notString::find(const notString& other, size_t pos) const {
    return _find(other.str, other.length(), pos);
}
size_t notString::find(const notString& other) const {
    return _find(other.str, other.length(), 0);
}
size_t notString::find(const notString& other, size_t pos, size_t n) const {
    return _find(other.str, n, pos);
}
size_t notString::find(const char* s, size_t pos) const {
    return _find(s, strlen(s), pos);
}
size_t notString::find(const char* s) const {
    return _find(s, strlen(s), 0);
}
size_t notString::find(const char* s, size_t pos, size_t n) const {
    return _find(s, n, pos);
}
size_t notString::find(char c, size_t pos) const {
    return _find(&c, 1, pos);
}
size_t notString::find(char c) const {
    return _find(&c, 1, 0);
}

//operator at()
char &notString::at(size_t i) {
    if (this->length() <= i)
        throw;
    return str[i];
}
