/*
**  3. Longest Substring Without Repeating Characters
**  Given a string, find the length of the longest substring
**  without repeating characters.
**
**  Example 1:
**  Input: "abcabcbb"
**  Output: 3 
**  Explanation: The answer is "abc", with the length of 3. 
**
**  Example 2:
**  Input: "bbbbb"
**  Output: 1
**  Explanation: The answer is "b", with the length of 1.
**
**  Example 3:
**  Input: "pwwkew"
**  Output: 3
**  Explanation: The answer is "wke", with the length of 3. Note that
**  the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

/*
**  I create a table that holds all letters based on ASCII - for
**  the letters already existing in substring I set their index to true, 
**  then I iterate through a string and each time I check if a letter in
**  a table is set to true. If it is and the count of letters in substring
**  is greater than max, I save it to max. Next I set all indexes
**  of letters up to repeated letter to false and decrease length.
**  I repeat until the end of string.
**  I'd say time complexity is O(n) and space O(1).
*/
int     lengthOfLongestSubstring(char *s)
{
    bool    chars[127 - 32] = {false};
    int     max = 0, length = 0, i = 0;
    
    while (s && s[i])
    {
        if (chars[s[i] - 32])
            while (s && chars[s[i] - 32])
                chars[s[i - length--] - 32] = false;
        chars[s[i] - 32] = true;
        length++;
        if (length > max)
            max = length;
        i++;
    }
    return (max);
}