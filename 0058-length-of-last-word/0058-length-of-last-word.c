int lengthOfLastWord(char* s) {
    int length = 0;
    int current = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ') {
            current++;
            length = current;
        } else {
            current = 0;
        }
    }

    return length;
}