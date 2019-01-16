/*
**  6. ZigZag Conversion
**
**  The string "PAYPALISHIRING" is written in a zigzag pattern
**  on a given number of rows like this: (you may want to display
**  this pattern in a fixed font for better legibility)
**
**  P   A   H   N
**  A P L S I I G
**  Y   I   R
**
**  And then read line by line: "PAHNAPLSIIGYIR"
**
**  Write the code that will take a string and make this conversion
**  given a number of rows:
**  string convert(string s, int numRows);
**
**  Example 1:
**  Input: s = "PAYPALISHIRING", numRows = 3
**  Output: "PAHNAPLSIIGYIR"
**
**  Example 2:
**  Input: s = "PAYPALISHIRING", numRows = 4
**  Output: "PINALSIGYAHRPI"
**
**  Explanation:
**  P     I    N
**  A   L S  I G
**  Y A   H R
**  P     I
*/

char    *convert(char *s, int numRows)
{
    int     add1, add2, res, len;
    char    *ret;
    
    if (!s || numRows < 1)
        return (NULL);
    if (numRows == 1)
        return (s);
    
    len = strlen(s);
    ret = (char *)calloc(1, len + 1);
    add1 = numRows + numRows - 2;
    add2 = 0;
     
    for (int i = 0, j = 0; i < numRows; i++)
    {
        res = i;
        while (res < len)
        {
            if (add1 && s[res])
            {
                ret[j++] = s[res];
                res += add1;
            }
            if (add2 && res < len && s[res])
            {
                ret[j++] = s[res];
                res += add2;
            }
        }
        add1 -= numRows - (numRows - 2);
        add2 += numRows - (numRows - 2);
    }
    return (ret);
}