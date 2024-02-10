package main
import "fmt"

func main() {
	a := 20
	b := 30
	ret := add(a,b)
	fmt.Printf("a + b = %d\n",ret)
	fmt.Printf("a = %d\n",a)
	byValue(a)
	fmt.Printf("call by value => a = %d\n",a)
	fmt.Printf("b = %d\n",b)
	byReference(&b)
	fmt.Printf("call by reference => b = %d\n",b)
	fmt.Printf("b = %d\n",b)
	arr := []int {1,2,3,4,5,6}
	fmt.Println(arr)
	foo(arr)
	fmt.Println(arr)
}
func foo(arr []int) {
	arr[0] = 1000
}

func byReference(a *int) {
	*a = 0
}

func byValue(a int) {
	a = 1000
}

func add(a int,b int) int {
	return a+b
}