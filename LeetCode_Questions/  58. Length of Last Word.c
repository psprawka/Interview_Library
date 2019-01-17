/*
**  58. Length of Last Word
**  
**  Given a string s consists of upper/lower-case alphabets
**  and empty space characters ' ', return the length of last
**  word in the string. If the last word does not exist, return 0.
**  Note: A word is defined as a character sequence consists of
**  non-space characters only.
**  
**  Example: 
**  Input: "Hello World"
**  Output: 5
*/

int lengthOfLastWord(char *s)
{
    int     ret = 0, i = 0;
    
    while (s[i])
    {
        ret = 0;
        while (s[i] && s[i] != ' ' && s[i] != '\0')
        {
            ret++;
            i++;
        }
         while (s[i] && s[i] == ' ')
            i++;
    }
    return (ret);
}