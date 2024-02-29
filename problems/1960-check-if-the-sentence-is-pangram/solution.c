bool checkIfPangram(char* sentence) {
    int i = 0;
    uint32_t a = 0b0;
    while(sentence[i] != '\0') {
        uint32_t b = 0b1;
        b = b << (sentence[i++] - 'a');
        printf("%b\n", b);
        printf("%b\n", a);
        a = a | b;
        printf("%b\n", a);
    }
    printf("%b", a);
    return a == 0x03ffffff;
}