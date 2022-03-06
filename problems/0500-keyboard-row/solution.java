class Solution {
    public String[] findWords(String[] words) {
        ArrayList<String> out = new ArrayList<>();


        char[] firstroworder = {'e', 'i', 'o', 'p', 'q', 'r', 't', 'u', 'w', 'y'};

        char[] secondroworder = {'a', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 's'};

        char[] thirdroworder = {'b', 'c', 'm', 'n', 'v', 'x', 'z'};

        for (int x = 0; x < words.length; x++) {
            
            char[] arr = thirdroworder;
            if (binarySearch(firstroworder, Character.toLowerCase(words[x].charAt(0)))) {
                arr = firstroworder;
            } else if (binarySearch(secondroworder, Character.toLowerCase(words[x].charAt(0)))) {
                arr = secondroworder;
            }
            
            boolean contains = true;
            for (int y = 1; y < words[x].length(); y++) {
                if (!binarySearch(arr, Character.toLowerCase(words[x].charAt(y)))) {
                    contains = false;
                    break;
                }
            }

            if (contains) {
                out.add(words[x]);
            }
        }
        return out.toArray(new String[0]);
        
    }
    public static boolean binarySearch(char[] array, char c) {
        int left = 0;
        int right = array.length - 1;
        while (left <= right) {
            int mid = (left + right)/2;
            //System.out.println(left + " " + right + " " + mid);
            if (array[mid] == c) {
                return true;
            } else if (array[mid] < c) {
                left = mid + 1;
            } else if (array[mid] > c) {
                right = mid - 1;
            }
        }
        return false;
    }
}