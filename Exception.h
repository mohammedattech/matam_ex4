#ifndef EXCEPTION_H
#define EXCEPTION_H
#include<iostream>
class DeckFileNotFound:public std::exception
{
    virtual const char* what()const throw()
    {
        return "Deck File Error: File not found";
    }
};
class DeckFileFormatError:public std::exception
{
public:
    DeckFileFormatError(int line):m_line(line){}
    virtual const char* what()const throw()
    {
        return "Deck File Error: File format error in line"+m_line;
    }
private:
    int m_line;
};
class DeckFileInvalidSize :public std::exception
{
    const char* what()const throw()
    {
        return "Deck File Error: Deck size is invalid";
    }
};
#endif