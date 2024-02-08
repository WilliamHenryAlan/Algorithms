package main
import "fmt"

func combine(n int, k int) [][]int {
	res := [][]int{}
	path := []int{}
	backtracking(1,n,k,path,res)
	return res
}

func backtracking(startIndex int,n int,k int,path []int,result [][]int) {
	if len(path) == k {
		result.
	}
}