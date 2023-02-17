#pragma once

#include <iostream>
#include <string>
#include <fstream>

const std::string kHelpText = 
  "-- Write a line --\n\
  How to use: ./WriteLine.exe <file> <line>\n\
  <file>: file to write to\n\
  <line>: line to write";

void Usage(int argc, char* argv[]);
void Program(int argc, char* argv[]);