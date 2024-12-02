#include <VocabularyEntry.h>
#include <string>
#include <vector>

Familiarity::Familiarity(double easeFactor, int interval, int repetitions,
                         int lapses)
    : easeFactor(easeFactor), interval(interval), repetitions(repetitions),
      lapses(lapses) {}

VocabularyEntry::VocabularyEntry(const std::string &character,
                                 const std::string &pinyin,
                                 const std::string &meaning,
                                 const std::string &partOfSpeech,
                                 std::vector<std::string> exampleSentences,
                                 const std::string audioPath,
                                 const Familiarity familiarity)
    : character_(character), pinyin_(pinyin), meaning_(meaning),
      partOfSpeech_(partOfSpeech), exampleSentences_(exampleSentences),
      audioPath_(audioPath), familiarity_(Familiarity()) {}

void VocabularyEntry::addExampleSentence(const std::string &sentence) {
  exampleSentences_.push_back(sentence);
}

void VocabularyEntry::updateFamiliarity(Familiarity familiarity) {
  familiarity_ = familiarity;
}

std::string VocabularyEntry::getCharacter() { return character_; }

std::string VocabularyEntry::getPinyin() { return pinyin_; }

std::string VocabularyEntry::getMeaning() { return meaning_; }

std::string VocabularyEntry::getPartOfSpeech() { return partOfSpeech_; }

std::vector<std::string> VocabularyEntry::getExampleSentences() {
  return exampleSentences_;
}

std::string VocabularyEntry::getAudioPath() { return audioPath_; }

Familiarity VocabularyEntry::getFamiliarity() { return familiarity_; }
