#ifndef READING_ENTRY_H
#define READING_ENTRY_H
#include "VocabularyEntry.h"
#include <string>
#include <vector>

class ReadingEntry : public VocabularyEntry {
public:
  ReadingEntry(
      const std::string &character, const std::string &pinyin,
      const std::string &meaning, const std::string &partOfSpeech = "",
      std::vector<std::string> exampleSentences = std::vector<std::string>(),
      const std::string audioPath = "",
      const Familiarity familiarity = Familiarity());

  void addExampleSentence(const std::string &sentence);
  void updateFamiliarity(Familiarity familiarity);

  std::string getCharacter();
  std::string getPinyin();
  std::string getMeaning();
  std::string getPartOfSpeech();
  std::vector<std::string> getExampleSentences();
  std::string getAudioPath();
  Familiarity getFamiliarity();

private:
  std::string character_;
  std::string pinyin_;
  std::string meaning_;
  std::string partOfSpeech_;
  std::vector<std::string> exampleSentences_;
  std::string audioPath_;
  Familiarity familiarity_;
};

#endif
