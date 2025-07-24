class Solution:
    def to_morse(self, word: str) -> str:
        MORSE = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        return "".join(MORSE[ord(c) - ord('a')] for c in word)
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        unique = set()
        for word in words:
            unique.add(self.to_morse(word))
        return len(unique)
