package main
import "fmt"

func main() {
	//var price float64
	str := "none"
	fmt.Printf("%v\n",str)	
	arr := []int{1,2,3}
	arr1 := [...]int{1,2,3}
	Matrix := [3][4]int{{0}}
	for i := 0;i < len(arr);i++ {
		fmt.Println(arr[i])
	}
	j := len(arr1)	//golang没有while
	for j > 0 {
		j -= 1
		fmt.Println(arr[j])
	}
	for _,i := range Matrix {
		for _,j := range i {
			fmt.Println(j,"\t")
		}
	}
	var URL string
	URL = "hello"
	fmt.Printf(URL)
}
