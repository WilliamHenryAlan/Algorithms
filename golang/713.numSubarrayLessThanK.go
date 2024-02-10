package main

import "fmt"

func numSubarrayProductLessThanK(nums []int, k int) int {
	if k <= 1 {
		return 0
	}
	l := 0
	ans := 0
	mult := 1
	for r,value := range nums {
		mult *= value
		for mult >= k {
			mult /= nums[l]
            l++
		}
		ans += r-l+1
	}
	return ans
}

func main() {
	nums := []int{1,2,9,4,5,3,1,5}
	ans := numSubarrayProductLessThanK(nums,4)
	fmt.Println(ans)
}