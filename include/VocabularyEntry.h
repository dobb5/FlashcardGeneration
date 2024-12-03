#ifndef VOCABULARY_ENTRY_H
#define VOCABULARY_ENTRY_H

#include <string>
#include <vector>

/**
 * Struct For storing familiarity with a vocabulary term
 *
 * @param easeFacor Ease of recal for a given vocab term
 * @param interval Period of time before recall attempt
 * @param repetitions Number of times term has been repeated
 * @param lapses Number of times vocab term has been reset due to failed recall
 */
struct Familiarity {
  double easeFactor; // Ease of recall
  int interval;      // Days until the next review
  int repetitions;   // Number of successful reviews
  int lapses;        // Number of times forgotten

  /**
   * Constructor for Familiarity struct
   *
   * @param easeFacor Ease of recal for a given vocab term
   * @param interval Period of time before recall attempt
   * @param repetitions Number of times term has been repeated
   * @param lapses Number of times vocab term has been reset due to failed
   * recall
   */
  Familiarity(double easeFactor = 2.5, int interval = 1, int repetitions = 0,
              int lapses = 0);
};

class VocabularyEntry {
public:
  virtual ~VocabularyEntry() = default;      // default destructor
  virtual std::string getAnkiId() const = 0; // returns note id and card id(s)
  virtual std::string serializeToJson() const = 0; //  serialized to JSON
  virtual std::string serializeToCsv() const = 0;  //  serialized to CSV
  virtual void
  deserializeFromJson(const std::string &jsonData) = 0; // deserializes a JSON
  virtual std::string
  getSummary() const = 0; //   Returns a brief human-readable summary of the
                          //   vocabulary entry
  virtual std::string getType() const = 0; // Returns the type of the vocabulary
                                           // entry (e.g., "Written", "Spoken")

private:
};

#endif
