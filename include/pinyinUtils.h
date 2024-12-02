#ifndef PINYIN_UTILS_H
#define PINYIN_UTILS_H

#include <string>

class pinyinUtils {
public:
  /**
   * Converts pinyin marked by number to pinyin with diacritic
   *
   * @param numberedPinyin String in format of any number of [pinyin][tone
   * number between 1-5 inclusive]
   * @return The same string with numbers removed and diacritics added
   */
  static std::string convertToDiacritics(const std::string &numberedPinyin);
  /**
   * Converts pinyin with diacritic to pinyin marked by number
   *
   * @param diacriticPinyin String in the format of any number of [pinyin with
   * diacritic tone marker]
   * @return The same string with diacritics removed and tone numbers added
   */
  static std::string convertToNumbered(const std::string &diacriticPinyin);
  /**
   * Converts single syllable with number to syllable with diacritic tone marker
   *
   * @param numberedSyllable Syllable with tone number
   * @return the same syllable with number removed and tone marker added
   */
private:
  static std::string
  applyDiacriticToSyllable(const std::string &numberedSyllable);
  /**
   * Convers single syllable with diacritic tone marker to syllable with number
   *
   * @param diacriticSyllable Syllable with diacritic tone marker
   * @return the same Syllable with diacritic tone marker removed and number
   * added
   */
  static std::string
  applyNumberToSyllable(const std::string &diacriticSyllable);
};

#endif
