#include <array>
#include <cstddef>
#include <map>
#include <pinyinUtils.h>
#include <regex>
#include <string>

std::size_t checka(const std::string &syllable) { return syllable.find("a"); }
std::size_t checkA(const std::string &syllable) { return syllable.find("A"); }
std::size_t checke(const std::string &syllable) { return syllable.find("e"); }
std::size_t checkE(const std::string &syllable) { return syllable.find("E"); }
std::size_t checkou(const std::string &syllable) {
  if (syllable.find("u") != std::string::npos |
      syllable.find("U") != std::string::npos)
    return syllable.find("o");
  else
    return std::string::npos;
}
std::size_t checkOU(const std::string &syllable) {
  if (syllable.find("u") != std::string::npos |
      syllable.find("U") != std::string::npos)
    return syllable.find("O");
  else
    return std::string::npos;
}
std::size_t findLastVowelIndex(const std::string &syllable) {
  const std::string vowels = "aeiouAEIOU";

  for (int i = syllable.size() - 1; i >= 0; --i) {
    if (vowels.find(syllable[i]) != std::string::npos) {
      return i;
    }
  }
  return std::string::npos;
}

std::string
pinyinUtils::convertToDiacritics(const std::string &numberedPinyin) {

  std::string diacriticPinyin = "";

  std::regex rgx("([a-zA-Z]+[1-5])"); // Define a regex pattern for one number
                                      // ranging from 1-5.

  std::sregex_token_iterator iter(numberedPinyin.begin(), numberedPinyin.end(),
                                  rgx);
  std::sregex_token_iterator end;
  for (; iter != end; ++iter)
    diacriticPinyin += applyDiacriticToSyllable(iter->str());
  return diacriticPinyin;
}

std::string
pinyinUtils::applyDiacriticToSyllable(const std::string &numberedSyllable) {
  std::map<std::string, std::array<std::string, 4>> toneMap = {
      {"a", {"ā", "á", "ǎ", "à"}}, {"A", {"Ā", "Á", "Ǎ", "À"}},
      {"e", {"ē", "é", "ě", "è"}}, {"E", {"Ē", "É", "Ě", "È"}},
      {"o", {"ō", "ó", "ǒ", "ò"}}, {"O", {"Ō", "Ó", "Ǒ", "Ò"}},
      {"i", {"ī", "í", "ǐ", "ì"}}, {"I", {"Ī", "Í", "Ǐ", "Ì"}},
      {"u", {"ū", "ú", "ǔ", "ù"}}, {"U", {"Ū", "Ú", "Ǔ", "Ù"}},
      {"ü", {"ǖ", "ǘ", "ǚ", "ǜ"}}, {"Ü", {"Ǖ", "Ǘ", "Ǚ", "Ǜ"}}};

  std::string syllable = numberedSyllable.substr(
      0,
      numberedSyllable.size() - 1); // Get the part without the last character
  int tone = numberedSyllable.back() - '1';

  std::size_t pos = checka(syllable);
  if (pos == std::string::npos)
    pos = checkA(syllable);
  if (pos == std::string::npos)
    pos = checke(syllable);
  if (pos == std::string::npos)
    pos = checkE(syllable);
  if (pos == std::string::npos)
    pos = checkou(syllable);
  if (pos == std::string::npos)
    pos = checkOU(syllable);
  if (pos == std::string::npos)
    pos = findLastVowelIndex(syllable);

  if (pos == std::string::npos) {
    return syllable;
  }

  std::string letter = std::string(1, syllable[pos]);
  std::array<std::string, 4> tonedLetters = toneMap[letter];
  std::string correctLetter = tonedLetters[tone];
  return syllable.substr(0, pos) + correctLetter + syllable.substr(pos + 1);
}

std::string pinyinUtils::convertToNumbered(const std::string &diacriticPinyin) {
  // TODO Implement
  return "";
}

std::string
pinyinUtils::applyNumberToSyllable(const std::string &numberedSyllable) {
  // TODO Implement
  return "";
}
