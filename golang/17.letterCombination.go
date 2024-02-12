var letter []string{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"} // := 是能用于函数内部
var path = ""
var ans []string{}
func letterCombinations(digits string) []string {	
	if len(digits) == 0 {
		return ans
	}
	backtracking(digits,0)
	return ans
}
func backtracking(digits string,index int) {
	if len(string) == len(digits) {
		ans = append(ans,path)
		return ;
	}

	digit := letter[index]	//逐个取出digit
	for i,val := digit {	//遍历digit的每个char
		path = append(path,val)
		backtracking(digits,index+1)
		path = slice[len(path)-1]	
	}
}