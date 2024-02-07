func minSubArrayLen(target int, nums []int) int {
    sum,l,ans := 0,0,len(nums)+1
	for r,value := range nums {
		sum += value
		for sum >= target {
            ans = min(ans,r-l+1)
            sum -= nums[l]
			l++
		}
	}
	if ans == len(nums)+1 {
		return 0
	}else {
		return ans
	}
}