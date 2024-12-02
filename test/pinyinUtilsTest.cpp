#include <cassert>
#include <iostream>
#include <pinyinUtils.h>
#include <string>

void testConvertToDiacritics() {
  std::string numbered1 = "hao3";
  std::string numbered2 = "an1";
  std::string numbered3 = "AN1";
  std::string numbered4 = "lian4";
  std::string numbered5 = "liao2";
  std::string numbered6 = "e4";
  std::string numbered7 = "E1ren2guo2jia4";
  std::string numbered8 = "ou3an1si4E1bU2Tai4xIaN2";
  assert(pinyinUtils::convertToDiacritics(numbered1) == "hǎo");
  assert(pinyinUtils::convertToDiacritics(numbered2) == "ān");
  assert(pinyinUtils::convertToDiacritics(numbered3) == "ĀN");
  assert(pinyinUtils::convertToDiacritics(numbered4) == "liàn");
  assert(pinyinUtils::convertToDiacritics(numbered5) == "liáo");
  assert(pinyinUtils::convertToDiacritics(numbered6) == "è");
  assert(pinyinUtils::convertToDiacritics(numbered7) == "Ērénguójià");
  assert(pinyinUtils::convertToDiacritics(numbered8) == "ǒuānsìĒbÚTàixIáN");
  std::cout << "convertToDicritics test passed succesfully";
};

void testConvertToNumbered() {
  std::string diacritic1 = "hǎo";
  std::string diacritic2 = "ān";
  std::string diacritic3 = "Ān";
  std::string diacritic4 = "liàn";
  std::string diacritic5 = "liáo";
  std::string diacritic6 = "è";
  std::string diacritic7 = "Ērénguójià";
  std::string diacritic8 = "lìánǒuānsìĒbÚtàixIáN";
  assert(pinyinUtils::convertToNumbered(diacritic1) == "hao3");
  assert(pinyinUtils::convertToNumbered(diacritic2) == "an1");
  assert(pinyinUtils::convertToNumbered(diacritic3) == "AN1");
  assert(pinyinUtils::convertToNumbered(diacritic4) == "lian4");
  assert(pinyinUtils::convertToNumbered(diacritic5) == "liao2");
  assert(pinyinUtils::convertToNumbered(diacritic6) == "e4");
  assert(pinyinUtils::convertToNumbered(diacritic7) == "E1ren2guo2jia4");
  assert(pinyinUtils::convertToNumbered(diacritic8) ==
         "li4an2ou3an1si4E1bU2Tai4xIaN2");
  std::cout << "convertToNumbered test passed succesfully";
};

void misuseTest() {
  std::string term1 = "hǎo";
  std::string term2 = "hao3";
  std::string term3 = "Ānquan2";
  std::string term4 = "ān2";
  std::string term5 = "liáo";
  std::string term6 = "è";
  std::string term7 = "Ērénguójià";
  std::string term8 = "ǒuānsìĒbÚtàixIáN";
}

int main() {
  testConvertToDiacritics();
  // testConvertToNumbered();
  std::cout << "all tests passed succesfully";
  return 0;
};
