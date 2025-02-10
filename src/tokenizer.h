//
// Created by cjq on 25-2-10.
//

#ifndef HUGGINGFACE_TOKENIZER_CPP_TOKENIZER_H
#define HUGGINGFACE_TOKENIZER_CPP_TOKENIZER_H

#include "nlohmann/json.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <unicode/uchar.h>
#include <vector>

class WordPieceTokenizer {
private:
  nlohmann::json jsonObj;
  nlohmann::json vocab;
  size_t max_input_chars_per_word;
  std::wstring unk_token;
  std::vector<std::wstring> special_tokens;

public:
  WordPieceTokenizer(const std::string &config_path);

  int get_word_index(const std::wstring &word);

  std::vector<size_t> tokenize_full(const std::wstring &input_text,
                                    bool split_specials = false);

  std::vector<std::wstring> wordpiece_tokenize(const std::wstring &input_text);

  std::vector<size_t>
  convert_tokens_to_ids(const std::vector<std::wstring> &input_seq) {
    std::vector<size_t> output_ids;
    output_ids.reserve(input_seq.size());
    for (const auto &i : input_seq) {
      output_ids.push_back(get_word_index(i));
    }
    return output_ids;
  }
};

#endif // HUGGINGFACE_TOKENIZER_CPP_TOKENIZER_H
