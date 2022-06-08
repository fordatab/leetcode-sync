class Solution {
    public String longestCommonPrefix(String[] arr) {
        int max = arr[0].length();
        for (int x = 1; x < arr.length; x++) {
            if (arr[x].length() < max) {
                max = arr[x].length();
            }
        }
        StringBuilder out = new StringBuilder();
        for (int x = 0; x < max; x++) {
            char c = arr[0].charAt(x);
            boolean a = true;
            for (String s : arr) {
                if (c != s.charAt(x)) {
                    a = false;
                    break;
                }
            }
            if (a) {
                out.append(c);
            } else {
                break;
            }
        }
        return(out.toString());
    }
}