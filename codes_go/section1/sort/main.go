package main

import (
	"fmt"
	"math/rand"
	"time"
)

const n = 10

func printSorted(sort *[]int) {
	for _, val := range *sort {
		fmt.Printf("%v ", val)
	}
}

func main() {
	var sort []int
	rand.Seed(time.Now().UnixNano())

	fmt.Printf("Prepare for sort\n")
	//for i := 0; i < n; i++ {
	//	sort = append(sort, rand.Int())
	//}
	sort = []int{9, 7, 6, 2, 8, 1, 4, 3, 5, 10}

	fmt.Printf("\nStart sorting... \n")
	start := time.Now()

	//BubbleSort(&sort)
	//QuickSort(0, n-1, &sort)
	//MergeSort(n, &sort)
	//CombSort(n, &sort)
	//InsertSort(n, &sort)
	BinaryInsertSort(n, &sort)

	end := time.Now()
	printSorted(&sort)
	fmt.Printf("Finish sorting. ")
	fmt.Printf("Elapsed: %f [ms]\n", (end.Sub(start)).Seconds()*1000)
}
