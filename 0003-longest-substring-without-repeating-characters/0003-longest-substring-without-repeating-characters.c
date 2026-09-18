#include <string.h>

int lengthOfLongestSubstring(char* s) {
    int last_index[256];
    
  
    for (int i = 0; i < 256; i++) {
        last_index[i] = -1;
    }
    
    int max_len = 0;
    int start = 0;
    
    for (int end = 0; s[end] != '\0'; end++) {
        unsigned char current_char = (unsigned char)s[end];
     
        if (last_index[current_char] >= start) {
            start = last_index[current_char] + 1;
        }
        
      
        last_index[current_char] = end;
        
      
        int current_len = end - start + 1;
        if (current_len > max_len) {
            max_len = current_len;
        }
    }
    
    return max_len;
}