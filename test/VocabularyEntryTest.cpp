#include <VocabularyEntry.h>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>

// Test functions
void testAddExampleSentence() {
  std::vector<std::string> sentences = {"你好！我叫小明。"};
  VocabularyEntry term1("你好", "ni3hao3", "hello", "greeting", sentences);

  assert(term1.getExampleSentences().size() == 1);
  term1.addExampleSentence("你好！我是康文道。");
  assert(term1.getExampleSentences().size() == 2);
  assert(term1.getExampleSentences()[0] == "你好！我叫小明。");
  assert(term1.getExampleSentences()[1] == "你好！我是康文道。");
  std::cout << "testAddExampleSentence passed.\n";
}

void testUpdateFamiliarity() {
  VocabularyEntry term2("安全", "an1quan1", "safety");
  Familiarity newFamiliarity = Familiarity(2.5, 7, 3, 1);
  term2.updateFamiliarity(newFamiliarity);
  assert(term2.getFamiliarity().easeFactor == 2.5);
  assert(term2.getFamiliarity().interval == 7);
  assert(term2.getFamiliarity().repetitions == 3);
  assert(term2.getFamiliarity().lapses == 1);
  std::cout << "testUpdateFamiliarity passed.\n";
}

int main() {
  testAddExampleSentence();
  testUpdateFamiliarity();

  std::cout << "All tests passed successfully.\n";
  return 0;
}
