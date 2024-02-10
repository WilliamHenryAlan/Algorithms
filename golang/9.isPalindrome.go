
func isPalindrome(x int) bool {
	if x % 10 == 0 && x != 0 {
		return false
	}
	n := 0
	for n < x {
		n = n * 10 + x % 10
		x /= 10
	}
	return n / 10 == x || n == x
}