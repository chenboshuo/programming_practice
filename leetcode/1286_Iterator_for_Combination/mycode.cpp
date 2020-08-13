#include <string>
using namespace std;
class CombinationIterator {
 public:
  int i = 0;
  CombinationIterator(string characters, int combinationLength) {
    if (characters.size() != 1) {
      sub = has_next = true;
    } else {
      has_next = false;
    }
    _characters = characters;
    _combinationLength = combinationLength;
  }

  string next() {
    if (_characters.size() != 1) {
      return _characters.substr(0, 1).append(sub.next());
    } else {
      return _characters;
    }
  }

  bool hasNext() {}

 private:
  bool has_next;
  CombinationIterator sub = CombinationIterator(
      characters.substr(1, characters.size() - 1), combinationLength - 1);
  string _characters;
  int _combinationLength;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters,
 * combinationLength); string param_1 = obj->next(); bool param_2 =
 * obj->hasNext();
 */
