class Solution {
    public String intToRoman(int n) {
        StringBuilder str = new StringBuilder();
        int m = n/1000;
        for (int x = 0; x < m; x++) {
            str.append("M");
        }
        n %= 1000;

        int c = n/100;
        if (c == 4) {
            str.append("CD");
        } else if (c == 9) {
            str.append("CM");
        } else {
            if (c >= 5) {
                str.append("D");
                str.append("C".repeat(c - 5));
            } else {
                str.append("C".repeat(Math.max(0, c)));
            }
        }
        n %= 100;

        int x = n/10;
        if (x == 4) {
            str.append("XL");
        } else if (x == 9) {
            str.append("XC");
        } else {
            if (x >= 5) {
                str.append("L");
                str.append("X".repeat(x - 5));
            } else {
                str.append("X".repeat(Math.max(0, x)));
            }
        }
        n %= 10;

        int i = n;
        if (i == 4) {
            str.append("IV");
        } else if (i == 9) {
            str.append("IX");
        } else {
            if (i >= 5) {
                str.append("V");
                i -= 5;
            }
            str.append("I".repeat(Math.max(0, i)));
        }
        return str.toString();
    }
}