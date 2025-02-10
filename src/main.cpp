//
// Created by cjq on 25-2-10.
//
#include "tokenizer.h"


int main(int argc, char **argv) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <input_file>" << std::endl;
    return 1;
  }

  std::locale::global(std::locale(""));
  WordPieceTokenizer tokenizer("tokenizer.json");

  // Open the input file
  std::wifstream file(argv[1]);
  file.imbue(std::locale(""));
  if (!file) {
    std::cerr << "Error: Unable to open input file." << std::endl;
    return 1;
  }

  // Read the entire file content into a single wide string
  std::wstringstream buffer;
  buffer << file.rdbuf();
  std::wstring input_text = buffer.str();

  std::wcout << input_text << std::endl;

  // Tokenize the input text
  auto r = tokenizer.tokenize_full(input_text);
  std::wcout << "===== TOKENS START=====" << std::endl;
  for (auto &x : r) {
    std::wcout << x << std::endl;
  }
  std::wcout << "===== TOKENS END ======" << std::endl;



  std::wstring text = L"这是第一个句子。";
  auto out = tokenizer.tokenize_full(text);
  for (auto &x : out) {
    std::wcout << x << " ";
  }
  std::wcout << std::endl;

  return 0;
}