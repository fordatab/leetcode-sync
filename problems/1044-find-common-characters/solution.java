class Solution {
    public List<String> commonChars(String[] words) {
        
      List<String> duplicates = new ArrayList<>();
        int[][] mapChars = new int[100][26];
        for (int y = 0; y < words.length; y++) {
            for (int x = 0; x < words[y].length(); x++) {
                mapChars[y][words[y].charAt(x)-97]++;
            }
        }
        for (int x = 0; x < 26; x++) {
            int min = 100;
            for (int y = 0; y < words.length; y++) {
                min = Math.min(mapChars[y][x], min);
            }
            for (int z = 0; z < min; z++) {
                duplicates.add(Character.toString(x+97));
            }
        }
        return duplicates; 
    }
}