class Solution { // Get all-1 mask by spreading 1 from most significant to the rest:
public://Time/Space: O(1); O(1)
int bitwiseComplement(int N, int c = 1) {
  while (c < N) c = (c << 1) + 1;
  return N ^ c;
}
};