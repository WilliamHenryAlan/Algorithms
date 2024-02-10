func lengthOfLongestSubstring(s string) int {
    hashTable := map[byte]int{}
    l,r,ans := 0,0,0
    n := len(s)
    for r < n {
        hashTable[s[r]]++
        for hashTable[s[r]] > 1 {
            hashTable[s[l]]--
            l++
        }
        ans = max(ans,r-l+1)
        r++
    }
    return ans
}
func max(a, b int) int{
    if a > b {
        return a
    }
    return b
}