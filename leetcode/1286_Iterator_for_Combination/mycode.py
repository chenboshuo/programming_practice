class CombinationIterator:

    def __init__(self, characters: str, combinationLength: int):
        if len(combination != 1) :
            self.sub = CombinationIterator(characters[1:], combinationLength-1)
        self.has_next = True
        self.i = 0
        self.characters = characters
        self.combinationLength = combinationLength

    def next(self) -> str:
        if self.combinationLength == 1:
            ans = self.characters[self.i]
            self.i += 1
            return ans

        if sub.hasNext():
            return self.characters[0] + sub.next()

        sub_combination = CombinationIterator(self.characters[1:], combinationLength)
        return sub_combination.next()



    def hasNext(self) -> bool:



# Your CombinationIterator object will be instantiated and called as such:
# obj = CombinationIterator(characters, combinationLength)
# param_1 = obj.next()
# param_2 = obj.hasNext()
