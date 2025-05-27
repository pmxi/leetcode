impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        let mut ret: Vec<i32> = Vec::new();
        for (index, string) in words.iter().enumerate() {
            if string.contains(x) {
                ret.push(index as i32);
            }
        }
        return ret;
    }
}
