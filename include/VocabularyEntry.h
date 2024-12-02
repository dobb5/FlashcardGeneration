#ifndef VOCABULARY_ENTRY_H
#define VOCABULARY_ENTRY_H

#include <string>
#include <vector>

struct Familiarity {
  double easeFactor; // Ease of recall
  int interval;      // Days until the next review
  int repetitions;   // Number of successful reviews
  int lapses;        // Number of times forgotten

  Familiarity(double easeFactor = 2.5, int interval = 1, int repetitions = 0,
              int lapses = 0);
};

class VocabularyEntry {
public:
  VocabularyEntry(
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
