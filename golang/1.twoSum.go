func twoSum(nums []int, target int) []int {
	hashTable := map[int]int{}
	for i,value := range nums {
		if p,ok := hashTable[target-value];ok {
			return []int{p,i}
		}else {
			hashTable[value] = i
		}
	}
	return []int{}
}