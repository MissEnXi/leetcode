package golang

import (
	"math"
	"strconv"
)

// 冒泡
func bubbleSort(a []int) {
	for i := 0; i < len(a)-1; i++ {
		flag := false
		for j := 0; j < len(a)-i-1; j++ {
			if a[j] > a[j+1] {
				a[j], a[j+1] = a[j+1], a[j]
				flag = true
			}
		}

		if !flag {
			return
		}
	}
}

// 选择排序
func selectSort(a []int) {
	for i := 0; i < len(a)-1; i++ {
		pos := i
		for j := i + 1; j < len(a); j++ {
			if a[pos] > a[j] {
				pos = j
			}
		}
		a[i], a[pos] = a[pos], a[i]
	}
}

// 插入排序
func insertSort(a []int) {
	for i := 1; i < len(a); i++ {
		tmp := a[i]
		j := i - 1
		for j >= 0 && tmp < a[j] {
			a[j+1] = a[j]
			j--
		}
		a[j+1] = tmp
	}
}

// 希尔排序
func shellSort(a []int) {
	for gap := len(a) / 2; gap > 0; gap /= 2 {
		for i := gap; i < len(a); i++ {
			tmp := a[i]
			j := i - gap
			for j >= 0 && tmp < a[j] {
				a[j+gap] = a[j]
				j -= gap
			}
			a[j+gap] = tmp
		}
	}
}

// 快速排序
func quickSort(a []int) {
	if len(a) <= 1 {
		return
	}

	low, high, key := 0, len(a)-1, a[0]
	for low < high {
		for low < high && a[high] > key {
			high--
		}
		a[low] = a[high]

		for low < high && a[low] <= key {
			low++
		}
		a[high] = a[low]
	}
	a[low] = key
	quickSort(a[:low])
	quickSort(a[low+1:])
}

// 归并排序
func mergeSort(a []int, left, right int) {
	if left < right {
		mid := (left + right) / 2
		mergeSort(a, left, mid)
		mergeSort(a, mid+1, right)
		merge(a, left, mid, right)
	}
}

func merge(a []int, left, mid, right int) {
	i := left
	j := mid + 1
	tmp := []int{}
	for i <= mid && j <= right {
		if a[i] <= a[j] {
			tmp = append(tmp, a[i])
			i++
		} else {
			tmp = append(tmp, a[j])
			j++
		}
	}
	if i <= mid {
		tmp = append(tmp, a[i:mid+1]...)
	} else {
		tmp = append(tmp, a[j:right+1]...)
	}
	for k := 0; k < len(tmp); k++ {
		a[left+k] = tmp[k]
	}
}

// 堆排序
func HeapSort(s []int) {
	N := len(s) - 1 //s[0]不用，实际元素数量和最后一个元素的角标都为N
	//构造堆
	//如果给两个已构造好的堆添加一个共同父节点，
	//将新添加的节点作一次下沉将构造一个新堆，
	//由于叶子节点都可看作一个构造好的堆，所以
	//可以从最后一个非叶子节点开始下沉，直至
	//根节点，最后一个非叶子节点是最后一个叶子
	//节点的父节点，角标为N/2
	for k := N / 2; k >= 1; k-- {
		sink(s, k, N)
	}
	//下沉排序
	for N > 1 {
		swap(s, 1, N) //将大的放在数组后面，升序排序
		N--
		sink(s, 1, N)
	}
}

//下沉（由上至下的堆有序化）
func sink(s []int, k, N int) {
	for {
		i := 2 * k
		if i > N { //保证该节点是非叶子节点
			break
		}
		if i < N && s[i+1] > s[i] { //选择较大的子节点
			i++
		}
		if s[k] >= s[i] { //没下沉到底就构造好堆了
			break
		}
		swap(s, k, i)
		k = i
	}
}

func swap(s []int, i int, j int) {
	s[i], s[j] = s[j], s[i]
}

// 计数排序
func countSort(a []int) {
	max := a[0]
	length := len(a)
	for i := 1; i < length; i++ {
		if max < a[i] {
			max = a[i]
		}
	}

	arr := make([]int, max)
	for i := 0; i < length; i++ {
		arr[a[i]]++
	}

	k := 0
	for m, n := range arr {
		for p := 0; p < n; p++ {
			a[k] = m
			k++
		}
	}
}

// 桶排序
func binSort(a []int, bin_num int) {
	min_num, max_num := a[0], a[0]
	for i := 0; i < len(a); i++ {
		if min_num > a[i] {
			min_num = a[i]
		}
		if max_num < a[i] {
			max_num = a[i]
		}
	}
	bin := make([][]int, bin_num)
	for j := 0; j < len(a); j++ {
		n := (a[j] - min_num) / ((max_num - min_num + 1) / bin_num)
		bin[n] = append(bin[n], a[j])
		k := len(bin[n]) - 2
		for k >= 0 && a[j] < bin[n][k] {
			bin[n][k+1] = bin[n][k]
			k--
		}
		bin[n][k+1] = a[j]
	}
	o := 0
	for p, q := range bin {
		for t := 0; t < len(q); t++ {
			a[o] = bin[p][t]
			o++
		}
	}
}

// 基数排序
func radixSort(a []int) {
	max_num := a[0]
	for i := 0; i < len(a); i++ {
		if max_num < a[i] {
			max_num = a[i]
		}
	}
	for j := 0; j < len(strconv.Itoa(max_num)); j++ {
		bin := make([][]int, 10)
		for k := 0; k < len(a); k++ {
			n := a[k] / int(math.Pow(10, float64(j))) % 10
			bin[n] = append(bin[n], a[k])
		}
		m := 0
		for p := 0; p < len(bin); p++ {
			for q := 0; q < len(bin[p]); q++ {
				a[m] = bin[p][q]
				m++
			}
		}
	}
}

// top-k
func sift(a []int, low, high int) {
	i := low
	j := 2*i + 1
	tmp := a[i]
	for j <= high {
		if j < high && a[j] > a[j+1] {
			j++
		}
		if tmp > a[j] {
			a[i] = a[j]
			i = j
			j = 2*i + 1
		} else {
			break
		}
	}
	a[i] = tmp
}

func top_k(a []int, k int) []int {
	for i := k/2 - 1; i >= 0; i-- {
		sift(a, i, k-1)
	}
	for j := k; j < len(a); j++ {
		if a[0] < a[j] {
			a[0], a[j] = a[j], a[0]
			sift(a, 0, k-1)
		}
	}
	for n := k - 1; n > 0; n-- {
		a[0], a[n] = a[n], a[0]
		sift(a, 0, n-1)
	}
	return a[:k]
}
