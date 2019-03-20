/*
Given two strings s and t , write a function to determine if t is an anagram of s.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
*/

package golang

func isAnagram(s string, t string) bool {
	if len(s) != len(t) {
		return false
	}

	lalala := make(map[byte]int)

	for i := 0; i < len(s); i++ {
		lalala[s[i]]++
		lalala[t[i]]--
	}
	for _, v := range lalala {
		if v != 0 {
			return false
		}
	}

	return true
}
