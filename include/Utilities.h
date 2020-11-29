#ifndef _Utilities_H
#define _Utilities_H
#pragma once
const int KB_ESCAPE = 27;

void terminate(const std::string&);
int receiveKey();
int handleRegularKey(int c);
int handleSpecialKey();
#endif // !_Utilities_H