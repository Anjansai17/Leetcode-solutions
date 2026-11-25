import java.util.*;

class Solution {
    public String sortVowels(String s) {

        List<Character> list = new ArrayList<>();

        // Step 1: Collect vowels
        for (char ch : s.toCharArray()) {
            if ("aeiouAEIOU".indexOf(ch) != -1) {
                list.add(ch);
            }
        }

        // Step 2: Sort vowels
        Collections.sort(list);

        // Step 3: Replace vowel positions
        StringBuilder ans = new StringBuilder(s);

        int j = 0;

        for (int i = 0; i < s.length(); i++) {
            char ch = s.charAt(i);

            if ("aeiouAEIOU".indexOf(ch) != -1) {
                ans.setCharAt(i, list.get(j));
                j++;
            }
        }

        return ans.toString();
    }
}