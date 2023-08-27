#pragma once
#include <iostream>

    class notString {
    public:
        char* str;
        // No arguments Constructor
        notString();
        // Constructor with 1 arguments
        notString(char* c);
        //constructor for "lines"
        notString(const char* val);
        // Copy Constructor
        notString(const notString& source);
        // Move Constructor
        notString(notString&& source);

        // Destructor
        ~notString() { delete str; }

        friend notString operator+(const notString& lhs, const notString& rhs);
        friend notString operator+(const char* c, const notString& rhs);
        friend notString operator+(const notString& lhs, char c);
        friend notString operator+(char c, const notString& lhs);
        friend notString operator+(const notString& lhs, const char* c);

        notString& operator+=(const notString& rhs);
        notString& operator+= (char c);
        notString& operator+= (const char* c);

        notString& operator=(const notString& rhs);
        notString& operator=(const char* rhs);

        char& operator[](size_t pos)const;

        friend std::ostream& operator<<(std::ostream& os,const notString& obj);
        friend std::istream& operator>>(std::istream& is, notString& obj);

        int length() const;

        const char* c_str() const;

        int compare(const notString &rhs) const;
        friend bool operator == (const notString & lhs, const notString & rhs);
        friend bool operator != (const notString &, const notString &);
        friend bool operator < (const notString &, const notString &);
        friend bool operator > (const notString &, const notString &);
        friend bool operator <= (const notString &, const notString &);
        friend bool operator >= (const notString &, const notString &);

        size_t _find(const char *other, size_t len, size_t pos) const;
        bool _find_compare(const char *other, size_t len, size_t pos) const;
        size_t find(const notString &other, size_t pos) const;
        size_t find(const char *s, size_t pos) const;
        size_t find(const char *s, size_t pos, size_t n) const;
        size_t find(char c, size_t pos) const;
        size_t find(char c) const;
        size_t find(const char *s) const;
        size_t find(const notString &other) const;
        size_t find(const notString &other, size_t pos, size_t n) const;

        char & at(size_t);
    };

