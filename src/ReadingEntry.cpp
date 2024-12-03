#include "ReadingEntry.h"
#include <VocabularyEntry.h>
#include <string>
#include <vector>

Familiarity::Familiarity(double easeFactor, int interval, int repetitions,
                         int lapses)
    : easeFactor(easeFactor), interval(interval), repetitions(repetitions),
      lapses(lapses) {}

ReadingEntry::ReadingEntry(const std::string &character,
                           const std::string &pinyin,
                           const std::string &meaning,
                           const std::string &partOfSpeech,
                           std::vector<std::string> exampleSentences,
                           const std::string audioPath,
                           const Familiarity familiarity)
    : character_(character), pinyin_(pinyin), meaning_(meaning),
      partOfSpeech_(partOfSpeech), exampleSentences_(exampleSentences),
      audioPath_(audioPath), familiarity_(Familiarity()) {}

void ReadingEntry::addExampleSentence(const std::string &sentence) {
  exampleSentences_.push_back(sentence);
}

void ReadingEntry::updateFamiliarity(Familiarity familiarity) {
  familiarity_ = familiarity;
}

std::string ReadingEntry::getCharacter() { return character_; }

std::string ReadingEntry::getPinyin() { return pinyin_; }

std::string ReadingEntry::getMeaning() { return meaning_; }

std::string ReadingEntry::getPartOfSpeech() { return partOfSpeech_; }

std::vector<std::string> ReadingEntry::getExampleSentences() {
  return exampleSentences_;
}

std::string ReadingEntry::getAudioPath() { return audioPath_; }

Familiarity Reading::getFamiliarity() { return familiarity_; }
