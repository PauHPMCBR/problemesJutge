#include <iostream>
using namespace std;

int main() {
  char c;
  int short_words = 0, medium_words = 0, long_words = 0, word_length = 0;

  // Read the sequence of words
  cin >> c;
  while (c != '.') {
    // If we encounter a dash, it means we are at the end of a word
    if (c == '-') {
      // Check the length of the word and increment the corresponding counter
      if (word_length < 5 and word_length != 0) {
        short_words++;
      } else if (word_length >= 5 && word_length <= 9) {
        medium_words++;
      } else if (word_length > 9) {
        long_words++;
      }

      // Reset the word length counter
      word_length = 0;
    } else {
      // If we encounter a letter, increment the word length counter
      word_length++;
    }

    // Get the next character
    cin >> c;
  }

  if (word_length < 5 and word_length != 0) {
        short_words++;
      } else if (word_length >= 5 && word_length <= 9) {
        medium_words++;
      } else if (word_length > 9) {
        long_words++;
      }

      // Reset the word length counter
      word_length = 0;

  // Print the results
  cout << short_words << "," << medium_words << "," << long_words << endl;

  return 0;
}
