int mySqrt(int y) {

    for (int x = 0; x < 46341; x++) {
        if (x*x >= y) {
            if (x*x == y) {
                return x;
            }
            return x-1;
        }
    }
    return 46340;
}