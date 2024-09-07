class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        int x = 0;
        while (x < words.size()) {
            int l = words[x].size();  // Length of the current line
            int y = x + 1;

            // Find as many words as can fit in the current line
            while (y < words.size() && l + 1 + words[y].size() <= maxWidth) {
                l += 1 + words[y].size();  // Add word and one space
                y++;
            }

            // Build the line
            string line;
            int spaces = maxWidth - l;  // Total spaces to distribute

            // If it's the last line or the line has only one word, left justify
            if (y == words.size() || y == x + 1) {
                for (int i = x; i < y; ++i) {
                    line += words[i];
                    if (i != y - 1) line += ' ';  // Add single space between words
                }
                line += string(maxWidth - line.size(), ' ');  // Pad the end with spaces
            } else {
                // Distribute spaces between words evenly
                int numWords = y - x;  // Number of words in the line
                int totalSpaces = maxWidth - (l - (numWords - 1));  // Remaining spaces to distribute
                int spacesBetween = totalSpaces / (numWords - 1);  // Spaces between each word
                int extraSpaces = totalSpaces % (numWords - 1);    // Extra spaces to distribute

                for (int i = x; i < y; ++i) {
                    line += words[i];
                    if (i != y - 1) {  // Don't add space after the last word
                        int numSpaces = spacesBetween + (extraSpaces-- > 0 ? 1 : 0);
                        line += string(numSpaces, ' ');
                    }
                }
            }

            out.push_back(line);
            x = y;  // Move to the next group of words
        }
        return out;
    }
};
