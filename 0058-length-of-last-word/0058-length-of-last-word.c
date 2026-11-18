 int lengthOfLastWord(char* s) {
    int i = strlen(s) - 1;


    while (i >= 0 && s[i] == ' ') {
        i--;
    }

    int length = 0;
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}
    
