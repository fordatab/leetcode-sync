char* getEncryptedString(char* s, int k) {
        int size = strlen(s);
        char out[size+1];
        for (int x = 0; x < size; x++) {
            out[x] = s[(x+k)%size];
        }
        out[size] = '\0'; 
        strcpy(s, out);
        return s;
}