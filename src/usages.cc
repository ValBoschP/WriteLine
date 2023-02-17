#include "usages.h"

void Usage(int argc, char* argv[]) {
  const std::string kHelp{"--help"};
  if (argc == 1) {
    std::cerr << argv[0] << std::endl <<  " -- Write a line -- " << std::endl;
    std::cerr << "How to use: " << argv[0] << " <file> <line>" << std::endl;
    std::cerr << "Try " << argv[0] << " --help for more information" << std::endl;
    exit(EXIT_FAILURE);
  }
  if (argv[1] == kHelp) std::cout << kHelpText << std::endl;
}

void Program(int argc, char* argv[]) {
  std::ifstream input_file(argv[1]);
  std::string line;
  bool is_empty = input_file.peek() == std::ifstream::traits_type::eof();
  if (is_empty) {
    std::ofstream output_file(argv[1]);
    if (!output_file.is_open()) {
      std::cerr << "File could not be opened!" << std::endl;
      exit(EXIT_FAILURE);
    }
    for (int i = 2; i < argc; ++i) {
      line += std::string(argv[i]) + " ";
    }
    output_file << line << std::endl;
    output_file.close();
  } else {
    std::ofstream output_file(argv[1], std::ios::app);
    if (!output_file.is_open()) {
      std::cerr << "File could not be opened!" << std::endl;
      exit(EXIT_FAILURE);
    }
    for (int i = 2; i < argc; ++i) {
      line += std::string(argv[i]) + " ";
    }
    output_file << line << std::endl;
    output_file.close();
  }
}