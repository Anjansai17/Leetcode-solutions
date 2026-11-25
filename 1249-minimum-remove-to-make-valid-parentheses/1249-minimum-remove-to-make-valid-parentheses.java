class Solution {
    public String minRemoveToMakeValid(String s) {

        StringBuilder sb = new StringBuilder(s);
        Stack<Integer> st = new Stack<>();

        // Step 1: Find invalid parentheses
        for (int i = 0; i < sb.length(); i++) {

            char ch = sb.charAt(i);

            if (ch == '(') {
                st.push(i);
            }
            else if (ch == ')') {

                if (!st.isEmpty()) {
                    st.pop();
                }
                else {
                    sb.setCharAt(i, '*');
                }
            }
        }

        // Step 2: Mark remaining invalid opening brackets
        while (!st.isEmpty()) {
            sb.setCharAt(st.pop(), '*');
        }

        // Step 3: Remove marked characters
        StringBuilder ans = new StringBuilder();

        for (int i = 0; i < sb.length(); i++) {
            if (sb.charAt(i) != '*') {
                ans.append(sb.charAt(i));
            }
        }

        return ans.toString();
    }
}