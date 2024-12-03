#include "VocabularyEntry.h"

#ifndef VOCABULARY_MANAGER_H
#define VOCABULARY_MANAGER_H

class VocabularyManager {
public:
  // CRUD Operations
  /*
   *
   */
  void addVocabularyEntry(const VocabularyEntry &entry);
  VocabularyEntry getVocabularyEntry(const std::string &character);
  void updateVocabularyEntry(const std::string &character,
                             const VocabularyEntry &updatedEntry);
  void deleteVocabularyEntry(const std::string &character);

  // Database Sync
  void loadFromDatabase(const std::string &query);
  void saveToDatabase();

private:
  // some sort of map
};

#endif
