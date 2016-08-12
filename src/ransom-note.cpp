bool canConstruct(char* ransomNote, char* magazine) {
    int cnt_a[26] = {0, };
    int cnt_b[26] = {0, };
    
    for (int i=0; i < strlen(ransomNote); ++i)
        cnt_a[ransomNote[i] - 'a'] ++;
    
    for (int i=0; i < strlen(magazine); ++i)
        cnt_b[magazine[i] - 'a'] ++;
    
    for (int i=0; i<26; ++i)
        
        if (cnt_b[i] < cnt_a[i]) return false;
    
    return true;
}
