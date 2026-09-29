public class Solution {
    public string LongestCommonPrefix(string[] strs) {
        if (strs == null || strs.Length == 0) return "";

        // Compare characters column by column using the first string as reference
        for (int i = 0; i < strs[0].Length; i++) {
            char currentChar = strs[0][i];

            for (int j = 1; j < strs.Length; j++) {
                // Stop if index is out of bounds or characters don't match
                if (i >= strs[j].Length || strs[j][i] != currentChar) {
                    return strs[0].Substring(0, i);
                }
            }
        }

        return strs[0];
    }
}