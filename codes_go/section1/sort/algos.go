package main

func BinaryInsertSort(n int, tmp *[]int) {
	data := *tmp
	for sorted := 1; sorted < n; sorted++ {
		insert := data[sorted]
		i := 0

		left := 0
		right := sorted
		for left < right {
			mid := (left + right) / 2
			if data[mid] < insert {
				left = mid + 1
			} else {
				right = mid
			}
			i = left
		}

		for i <= sorted {
			temp := data[i]
			data[i] = insert
			insert = temp
			i++
		}
	}
}

func InsertSort(n int, tmp *[]int) {
	data := *tmp
	for sorted := 1; sorted < n; sorted++ {
		insert := data[sorted]
		i := 0
		for ; i <= sorted; i++ {
			if data[i] > insert {
				break
			}
		}

		for i <= sorted {
			temp := data[i]
			data[i] = insert
			insert = temp
			i++
		}
	}
}

func CombSort(n int, data *[]int) {
	gap := n
	sort := *data
	for {
		gap = (gap * 10) / 13
		if gap == 0 {
			gap = 1
		}

		flag := 1
		for i := 0; i < n-gap; i++ {
			if sort[i] > sort[i+gap] {
				flag = 0
				temp := sort[i]
				sort[i] = sort[i+gap]
				sort[i+gap] = temp
			}
		}
		if !(gap > 1 || flag != 1) {
			break
		}
	}
}

func MergeSort(n int, x *[]int) {
	var buffer []int
	data := *x

	m := n / 2
	lower := data[:m]
	upper := data[m:]
	if m > 1 {
		MergeSort(m, &lower)
	}
	if n-m > 1 {
		MergeSort(n-m, &upper)
	}

	buffer = append(buffer, data...)
	j := m
	i := 0
	k := 0
	for i < m && j < n {
		if buffer[i] <= data[j] {
			data[k] = buffer[i]
			k++
			i++
		} else {
			data[k] = data[j]
			k++
			j++
		}
	}
	for i < m {
		data[k] = buffer[i]
		k++
		i++
	}
}

func QuickSort(bottom int, top int, data *[n]int) {
	var lower, upper, div, tmp int
	if bottom >= top {
		return
	}

	div = data[bottom]
	for lower, upper = bottom, top; lower < upper; {
		for lower <= upper && data[lower] <= div {
			lower++
		}
		for lower <= upper && data[upper] > div {
			upper--
		}
		if lower < upper {
			tmp = data[lower]
			data[lower] = data[upper]
			data[upper] = tmp
		}
	}

	tmp = data[bottom]
	data[bottom] = data[upper]
	data[upper] = tmp

	QuickSort(bottom, upper-1, data)
	QuickSort(upper+1, top, data)
}

func BubbleSort(tmp *[n]int) {
	var i, j, k, flag int

	k = 0
	for {
		flag = 0
		for i = 0; i < n-1-k; i++ {
			if tmp[i] > tmp[i+1] {
				flag = 1
				j = tmp[i]
				tmp[i] = tmp[i+1]
				tmp[i+1] = j
			}
		}
		k++
		if flag == 0 {
			break
		}
	}
}
