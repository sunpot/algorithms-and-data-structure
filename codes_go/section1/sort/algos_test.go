package main

import (
	"testing"
)

func TestBubbleSort(t *testing.T) {
	sort := [n]int{9, 4, 6, 2, 8, 1, 4, 3, 5, 10}
	BubbleSort(&sort)
	expected := [n]int{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}
	if sort != expected {
		t.Errorf("got %v\nwant %v", sort, expected)
	}
}
