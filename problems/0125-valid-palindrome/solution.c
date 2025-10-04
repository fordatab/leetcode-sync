bool isPalindrome(char* s) {
    int r = strlen(s);
    int l = 0;
    while (l < r) {
        if (!isalnum(s[r])) {
            r--;
        } else if (!isalnum(s[l])) {
            l++;
        } else {
            if (tolower(s[l]) == tolower(s[r])) {
                r--;
                l++;
            } else {
                return false;
            }
        } 
    }

    return true;
}