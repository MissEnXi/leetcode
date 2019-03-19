/*
Suppose Andy and Doris want to choose a restaurant for dinner,
and they both have a list of favorite restaurants represented by strings.

You need to help them find out their common interest with the least list index sum.
If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

Example 1:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"]
Output: ["Shogun"]
Explanation: The only restaurant they both like is "Shogun".
Example 2:
Input:
["Shogun", "Tapioca Express", "Burger King", "KFC"]
["KFC", "Shogun", "Burger King"]
Output: ["Shogun"]
Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
*/

package golang

func findRestaurant(list1 []string, list2 []string) []string {
	var res []string
	for sum := 0; sum < len(list1)+len(list2)-1; sum++ {
		for i := 0; i <= sum; i++ {
			if i < len(list1) && sum-i < len(list2) && list1[i] == list2[sum-i] {
				res = append(res, list1[i])
			}
		}

		if len(res) > 0 {
			return res
		}
	}

	return res
}

func findRestaurant2(list1 []string, list2 []string) []string {
	var res []string
	m := make(map[string]int)
	for pos, item := range list1 {
		m[item] = pos
	}

	minSum := len(list1) + len(list2)
	for pos2, item2 := range list2 {
		pos1, ok := m[item2]
		if ok {
			if minSum == pos1+pos2 {
				res = append(res, item2)
			} else if minSum > pos1+pos2 {
				minSum = pos1 + pos2
				res = []string{item2}
			}
		}
	}

	return res
}
