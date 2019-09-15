def answer(plaintext):
    arr =  ["100000", "110000", "100100", "100110", "100010", "110100",
            "110110", "110010", "010100", "010110", "101000", "111000",
            "101100", "101110", "101010", "111100", "111110", "111010",
            "011100", "011110", "101001", "111001", "010111", "101101",
            "101111", "101011" ]
    
    answer = ""
    
    for c in plaintext:
        if ord(c) > 64 and ord(c) < 91:
            answer += "000001"
            answer += arr[ord(c) - 65]
        elif (ord(c) > 96 and ord(c) < 123):
            answer += arr[ord(c) - 97]
        else:
            answer += "000000"
        print ord(c)

    return answer